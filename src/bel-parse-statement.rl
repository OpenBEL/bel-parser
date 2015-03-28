#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libbel.h"
#include "bel-ast.h"
#include "bel-node-stack.h"

%%{
    machine set;
    write data;
}%%

/* private */
bel_ast* _create_statement_ast();

/* private - optimistic subject creation */
bel_ast_node* _create_statement_ast_node();

/* private */
bel_ast_node* _create_term_ast_node();

/* private */
bel_ast_node* _create_arg_nv_ast_node();

/* private */
bel_ast_node* _create_arg_term_ast_node();

/* private */
bel_ast_node* _create_nv_ast_node();

bel_ast* bel_parse_statement(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             top;
    int             *stack;
    bel_ast_node*   statement;
    bel_ast_node*   parent_statement;
    bel_ast_node*   subject;
    bel_ast_node*   rel;
    bel_ast_node*   object;
    bel_ast_node*   term;
    bel_ast_node*   current_nv;
    bel_ast_node*   arg;
    bel_ast*        ast;
    bel_node_stack* term_stack;
    bel_node_stack* statement_stack;
    char            *function;
    char            *relationship;
    char            *value;
    int             fi;
    int             ri;
    int             vi;

    // Copy line to stack; Append new line if needed.
    int             line_length = strlen(line);
    int             i;
    char            input[line_length + 2];
    strcpy(input, line);
    for (i = line_length - 1; (input[i] == '\n' || input[i] == '\r'); i--)
        input[i] = '\0';
    input[i + 1] = '\n';
    input[i + 2] = '\0';

    p                 = input;
    pe                = input + strlen(input);
    top               = 0;
    stack             = malloc(sizeof(int) * TERM_STACK_SIZE);
    current_nv        = NULL;
    function          = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    relationship      = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value             = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    fi                = 0;
    ri                = 0;
    vi                = 0;

    term_stack        = stack_init(TERM_STACK_SIZE);
    statement_stack   = stack_init(STATEMENT_STACK_SIZE);
    statement         = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
    parent_statement  = NULL;
    term              = NULL;
    ast               = bel_new_ast();
    ast->root         = statement;

    stack_push(statement_stack, statement);

    memset(function, '\0', BEL_VALUE_CHAR_LEN);
    memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
    memset(value, '\0', BEL_VALUE_CHAR_LEN);

    %%{
        action fxc {
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }

        action relc {
            ri = 0;
            memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
        }

        action valc {
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }

        action fxn {
            function[fi++] = fc;
        }

        action reln {
            relationship[ri++] = fc;
        }

        action valn {
            value[vi++] = fc;
        }

        action FX {
            term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }

        action REL {
            rel = bel_new_ast_node_token(BEL_TOKEN_REL);
            rel->token->left  = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            rel->token->right = NULL;

            object = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
            object->token->left = rel;

            statement = stack_peek(statement_stack);
            statement->token->right = object;
        }

        action NESTED_FX {
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }

        action PFX {
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }

        action VAL {
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }

        action CALL_ARGUMENTS {
            fcall arguments;
        }

        action RET_ARGUMENTS {
            term = stack_pop(term_stack);
            fret;
        }

        action CALL_TERM {
            fhold;
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            fcall term;
        }

        action RET_TERM {
            statement = stack_peek(statement_stack);
            if (statement->token->left == NULL) {
                // assign term as subject
                subject = bel_new_ast_node_token(BEL_TOKEN_SUBJECT);
                subject->token->left  = bel_copy_ast_node(term);
                subject->token->right = NULL;
                statement->token->left = subject;
            } else {
                // assign term as object; object is already available
                // after REL action
                object = statement->token->right;
                object->token->right = bel_copy_ast_node(term);
                statement->token->right = object;
            }

            fret;
        }

        action CALL_STATEMENT {
            statement = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
            stack_push(statement_stack, statement);
            fcall statement;
        }

        action RET_STATEMENT {
            statement        = stack_pop(statement_stack);
            parent_statement = stack_peek(statement_stack);

            object = parent_statement->token->right;
            object->token->right = bel_copy_ast_node(statement);

            fret;
        }

        # Chracter class definitions
        SP               = [ \t];
        NL               = '\n' | '\r' '\n'?;
        O_PAREN          = '(';
        C_PAREN          = ')';
        NOT_SPACE         = [^ \t\n];
        FUNCTION_CHAR     = [^ \t(];
        HEAD_PREFIX_CHAR  = [^ \t:];
        TAIL_PREFIX_CHAR  = [^ \t:,];

        # Complete token definitions
        STRING            = '"' ('\\\"' | [^"])* '"';
        VALUE             = [^ \t,:()"]+;

        # BEL structure definitions
        FUNCTION         = FUNCTION_CHAR+            >fxc  $fxn            %FX;
        NESTED_FUNCTION  = FUNCTION_CHAR+            >fxc  $fxn            %NESTED_FX;
        HEAD_PREFIX      = (HEAD_PREFIX_CHAR+        >valc $valn ':')?     @PFX;
        TAIL_PREFIX      = (TAIL_PREFIX_CHAR+        >valc $valn ':')?     @PFX;
        STRING_OR_TOKEN  = (STRING|VALUE)             >valc $valn           %VAL;

        # Control definitions
        HOLD_ANY_CHAR    = any @{ fhold; };

        arguments :=
            SP*
            (
                HEAD_PREFIX SP* STRING_OR_TOKEN |
                NESTED_FUNCTION O_PAREN @CALL_ARGUMENTS
            )
            (
                SP* ',' SP*
                (
                    TAIL_PREFIX SP* STRING_OR_TOKEN |
                    NESTED_FUNCTION O_PAREN @CALL_ARGUMENTS
                )
            )* SP* C_PAREN @RET_ARGUMENTS
        ;

        term :=
            FUNCTION SP* O_PAREN >CALL_ARGUMENTS HOLD_ANY_CHAR @RET_TERM
        ;

        statement :=
            SP* FUNCTION_CHAR @CALL_TERM SP+ NOT_SPACE+ >relc $reln @REL
            SP+
            (
                ( FUNCTION_CHAR @CALL_TERM SP* C_PAREN? @RET_STATEMENT NL    )
                  |
                ( O_PAREN @CALL_STATEMENT SP* C_PAREN @RET_STATEMENT )
            )
        ;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    // free allocations
    bel_free_ast_node(term);
    if (term_stack) {
        stack_destroy(term_stack);
    }
    if (statement_stack) {
        stack_destroy(statement_stack);
    }
    free(stack);
    free(function);
    free(relationship);
    free(value);

    return ast;
};

/* private */
bel_ast* _create_statement_ast() {
    bel_ast*      ast;
    bel_ast_node* statement;

    ast       = bel_new_ast();
    statement = _create_statement_ast_node();
    ast->root = statement;

    return ast;
};

/* private - optimistic subject creation */
bel_ast_node* _create_statement_ast_node() {
    bel_ast_node* statement;
    bel_ast_node* subject;
    bel_ast_node* object;
    bel_ast_node* term;

    statement = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
    subject   = bel_new_ast_node_token(BEL_TOKEN_SUBJECT);
    object    = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
    term      = _create_term_ast_node();

    statement->token->left  = subject;
    statement->token->right = object;
    subject->token->left    = term;

    return statement;
};

/* private */
bel_ast_node* _create_term_ast_node() {
    bel_ast_node* term;
    bel_ast_node* fx;
    bel_ast_node* arg;

    term = bel_new_ast_node_token(BEL_TOKEN_TERM);
    fx   = bel_new_ast_node_value(BEL_VALUE_FX, NULL);
    arg  = bel_new_ast_node_token(BEL_TOKEN_ARG);

    term->token->left  = fx;
    term->token->right = arg;

    return term;
};

/* private */
bel_ast_node* _create_arg_nv_ast_node() {
    bel_ast_node* arg;
    bel_ast_node* nv;
    bel_ast_node* arg_placeholder;

    arg              = bel_new_ast_node_token(BEL_TOKEN_ARG);
    nv               = _create_nv_ast_node();
    arg_placeholder  = bel_new_ast_node_token(BEL_TOKEN_ARG);

    arg->token->left  = nv;
    arg->token->right = arg_placeholder;

    return arg;
};

/* private */
bel_ast_node* _create_arg_term_ast_node() {
    bel_ast_node* arg;
    bel_ast_node* term;
    bel_ast_node* arg_placeholder;

    arg              = bel_new_ast_node_token(BEL_TOKEN_ARG);
    term             = _create_nv_ast_node();
    arg_placeholder  = bel_new_ast_node_token(BEL_TOKEN_ARG);

    arg->token->left  = term;
    arg->token->right = arg_placeholder;

    return arg;
};

/* private */
bel_ast_node* _create_nv_ast_node() {
    bel_ast_node* nv;
    bel_ast_node* pfx;
    bel_ast_node* val;

    nv   = bel_new_ast_node_token(BEL_TOKEN_NV);
    pfx  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
    val  = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);

    nv->token->left  = pfx;
    nv->token->right = val;

    return nv;
};

// vim: ft=ragel sw=4 ts=4 sts=4 expandtab

