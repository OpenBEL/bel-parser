#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "libbel.h"
#include "bel-ast.h"
#include "bel-node-stack.h"

%%{
    machine set;
    write data;
}%%

/* private */
bel_ast* _create_statement_ast();

/* private */
bel_ast_node* _create_statement_ast_node();

/* private */
bel_ast_node* _create_term_ast_node();

/* private */
bel_ast_node* _create_wildcard_arg_ast_node();

/* private */
bel_ast_node* _create_arg_nv_ast_node();

/* private */
bel_ast_node* _create_arg_term_ast_node();

/* private */
bel_ast_node* _create_nv_ast_node();

/* private */
bel_ast_node* _mutable_node_value(bel_ast_value_type type, char* value);

/* private */
bel_ast_node* _set_wildcard_as_term_node(bel_ast_node* wildcard_node);

/* private */
bel_ast_node* _set_wildcard_as_nv_node(bel_ast_node* node);

/* private */
void _swap_left_right(bel_ast_node* wildcard_node);

/* private */
void _mark_subject_node_complete(bel_ast_node* statement_node);

/* private */
void _mark_object_node_complete(bel_ast_node* statement_node);

/* private */
void _mark_statement_node_complete(bel_ast_node* statement_node);

bel_ast* bel_parse_statement(char* line) {
    // ragel - definitions
    int             cs;
    char            *p;
    char            *pe;
    /* char            *ts; */
    /* char            *te; */
    int             top;
    int             *stack;
    /* const char      *eof; */

    // state - definitions
    bel_ast*        ast;
    bel_ast_node*   statement;
    bel_ast_node*   next;
    bel_ast_node*   term;
    bel_ast_node*   wildcard_node;
    bel_node_stack* arg_stack;
    bel_node_stack* statement_stack;
    char            *function;
    char            *relationship;
    char            *value;
    int             fi;
    int             ri;
    int             vi;

    // Copy line to C stack; Append new line if needed.
    int             line_length = strlen(line);
    int             i;
    char            input[line_length + 2];
    strcpy(input, line);
    for (i = line_length - 1; (input[i] == '\n' || input[i] == '\r'); i--)
        input[i] = '\0';
    input[i + 1] = '\n';
    input[i + 2] = '\0';

    // ragel - assignments
    p                 = input;
    pe                = input + strlen(input);
    /* ts                = p; */
    /* te                = NULL; */
    top               = 0;
    stack             = malloc(sizeof(int) * STACK_SIZE);
    /* eof               = (char*) EOF; */

    // state - initial assignments
    statement_stack   = stack_init(STACK_SIZE);
    arg_stack         = stack_init(STACK_SIZE);
    statement         = _create_statement_ast_node();
    next              = statement->token->left;
    term              = NULL;
    wildcard_node     = NULL;
    /* nv                = NULL; */
    ast               = bel_new_ast();
    ast->root         = statement;
    fi                = 0;
    ri                = 0;
    vi                = 0;
    stack_push(arg_stack, statement->token->left);
    stack_push(statement_stack, statement);
    function          = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    relationship      = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value             = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    memset(function, '\0', BEL_VALUE_CHAR_LEN);
    memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
    memset(value, '\0', BEL_VALUE_CHAR_LEN);

    // Initial State (i0)
    //   input:          ""
    //   termStack:      empty
    //   statementStack: [ statement_0 ]
    //   AST:            STATEMENT SUBJECT (null) (null) OBJECT (null) (null)
    //   Description:    Parsing statement but SUBJECT and OBJECT are empty.

    // Initial State (i1)
    //   input:          "p"
    //   termStack:      [ term_0      ]
    //   statementStack: [ statement_0 ]
    //   AST:            STATEMENT SUBJECT TERM fx(p) ARG (null) (null) (null) OBJECT (null) (null)
    //   Description:    Parsing SUBJECT TERM and collecting fx value.

    // Initial State (i2)
    //   input:          "p("
    //   termStack:      [ term_0      ]
    //   statementStack: [ statement_0 ]
    //   fsm action:     Call ARGUMENTS machine.
    //   AST:            STATEMENT SUBJECT TERM fx(p) ARG (null) (null) (null) OBJECT (null) (null)
    //   Description:    Parsing SUBJECT TERM and collecting fx value.

    // Initial State (i3)
    //   input:          "p(H"
    //   termStack:      [ term_0      ]
    //   statementStack: [ statement_0 ]
    //   fsm action:     Call ARGUMENTS machine.
    //   AST:            STATEMENT SUBJECT TERM fx(p) ARG NV pfx(H) val((null)) ARG (null) (null) (null) OBJECT (null) (null)
    //   Description:    Parsing 'H' to an ARG node.

    %%{
        action hold {
            fhold;
        }

        action fxc {
            /* ts = p; */
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
            wildcard_node->token->right->value->value = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
            memset(wildcard_node->token->right->value->value, '\0', BEL_VALUE_CHAR_LEN);
        }

        action fxn {
            /* te = p; */
            if (!wildcard_node) {
              wildcard_node = _create_wildcard_arg_ast_node();

              next = stack_peek(arg_stack);
              next->token->left = wildcard_node;
              fprintf(stdout, "created wildcard, ast: %s\n", bel_ast_as_string(ast));
            }
            // Store in right node.
            fprintf(stdout, "store %c\n", fc);
            fprintf(stdout, "wildcard_node type %d\n", wildcard_node->token->ttype);
            wildcard_node->token->right->value->value[fi++] = fc;
        }

        action reln {
            relationship[ri++] = fc;
        }

        action valn {
            wildcard_node->token->right->value->value[vi++] = fc;
        }

        action ARG_TO_TERM {
            term = _set_wildcard_as_term_node(wildcard_node);

            next = term->token->right;
            stack_push(arg_stack, next);
            fprintf(stdout, "arg to term, clear wildcard, ast: %s\n", bel_ast_as_string(ast));
            wildcard_node = NULL;
        }

        action ARG_TO_NV {
            _set_wildcard_as_nv_node(wildcard_node);

            //add terminal ARG
            next->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            next = next->token->right;
            stack_push(arg_stack, next->token->right);
            fprintf(stdout, "arg to nv, ast: %s\n", bel_ast_as_string(ast));
        }

        action MARK_ARG_COMPLETE {
            wildcard_node->token->is_complete = 1;
            next->token->is_complete = 1;
            stack_pop(arg_stack);
            wildcard_node = NULL;
            fprintf(stdout, "mark arg complete, ast: %s\n", bel_ast_as_string(ast));
        }

        action MARK_TERM_COMPLETE {
            term->token->is_complete = 1;
            wildcard_node->token->is_complete = 1;
            next->token->is_complete = 1;

            stack_pop(arg_stack);
            next = stack_peek(arg_stack);
            wildcard_node = NULL;
            fprintf(stdout, "mark term complete, ast: %s\n", bel_ast_as_string(ast));
        }

        action SWAP {
            _swap_left_right(wildcard_node);
        }

        action CALL_ARGUMENTS {
            fcall arguments;
        }

        action RET_ARGUMENTS {
            fret;
        }

        action CALL_TERM {
            fhold;
            fcall term;
        }

        action RET_TERM {
            fret;
        }

        action CALL_STATEMENT {
            statement = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
            stack_push(statement_stack, statement);
            fcall statement;
        }

        action RET_STATEMENT {
            fret;
        }

        # Chracter class definitions
        SP               = [ \t];
        NL               = '\n' | '\r' '\n'?;
        COLON            = ':';
        O_PAREN          = '(';
        C_PAREN          = ')';
        NOT_SPACE        = [^ \t\n];
        ARGUMENT_CHAR    = [^ \t\n,:()];
        FUNCTION_CHAR    = [^ \t\n(];

        # Complete token definitions
        STRING           = '"' ('\\\"' | [^"])* '"';
        VALUE            = [^ \t\n,:()"]+;

        # BEL structure definitions
        STRING_OR_TOKEN  = (STRING|VALUE)            >valc $valn;
        ARGUMENT         = ARGUMENT_CHAR+            >fxc  $fxn  ( COLON @SWAP STRING_OR_TOKEN >valc $valn | O_PAREN @ARG_TO_TERM @CALL_ARGUMENTS | C_PAREN @hold @ARG_TO_NV)?;
        FUNCTION         = FUNCTION_CHAR+            >fxc  $fxn  $lerr(ARG_TO_TERM) %ARG_TO_TERM;

        # Control definitions
        HOLD_ANY_CHAR    = any @{ fhold; };

        arguments :=
            SP*
            ARGUMENT NL? @MARK_ARG_COMPLETE
            (
                ',' @MARK_ARG_COMPLETE @ARG_TO_NV SP* ARGUMENT NL? @MARK_ARG_COMPLETE
            )*
            SP* C_PAREN @MARK_ARG_COMPLETE @MARK_TERM_COMPLETE @RET_ARGUMENTS
        ;

        term :=
            ARGUMENT SP* HOLD_ANY_CHAR @RET_TERM
        ;

        statement :=
            SP* FUNCTION_CHAR @CALL_TERM SP+ NOT_SPACE+ >relc $reln
            SP+
            (
                ( FUNCTION_CHAR @CALL_TERM SP* C_PAREN? @RET_STATEMENT NL )
                  |
                ( O_PAREN @CALL_STATEMENT SP* C_PAREN @RET_STATEMENT      )
            )
        ;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    // If wildcard_node remains an ARG then convert this to an NV.
    // This can happen if we're within a TERM.
    if (wildcard_node && wildcard_node->token->ttype == BEL_TOKEN_ARG) {
        _set_wildcard_as_nv_node(wildcard_node);

        //add terminal ARG
        next->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
    }

    _mark_subject_node_complete(ast->root);
    _mark_object_node_complete(ast->root);
    _mark_statement_node_complete(ast->root);

    // free allocations
    if (arg_stack) {
        stack_destroy(arg_stack);
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

/* private */
bel_ast_node* _create_statement_ast_node() {
    bel_ast_node* statement;
    bel_ast_node* subject;
    bel_ast_node* object;

    statement = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
    subject   = bel_new_ast_node_token(BEL_TOKEN_SUBJECT);
    object    = bel_new_ast_node_token(BEL_TOKEN_OBJECT);

    // optimistic subject term assignment
    statement->token->left  = subject;
    statement->token->right = object;

    return statement;
};

/* private */
bel_ast_node* _create_term_ast_node() {
    bel_ast_node* term;
    bel_ast_node* fx_node;
    bel_ast_node* arg;
    char*         fx_value;

    fx_value = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    memset(fx_value, '\0', BEL_VALUE_CHAR_LEN);

    term     = bel_new_ast_node_token(BEL_TOKEN_TERM);
    fx_node  = _mutable_node_value(BEL_VALUE_FX, fx_value);
    arg      = bel_new_ast_node_token(BEL_TOKEN_ARG);

    term->token->left  = fx_node;
    term->token->right = arg;

    return term;
};

/* private */
bel_ast_node* _create_wildcard_arg_ast_node() {
    bel_ast_node* arg;
    bel_ast_node* value_node_1;
    bel_ast_node* value_node_2;
    char*         value_1;
    char*         value_2;

    value_1 = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value_2 = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    memset(value_1, '\0', BEL_VALUE_CHAR_LEN);
    memset(value_2, '\0', BEL_VALUE_CHAR_LEN);

    arg          = bel_new_ast_node_token(BEL_TOKEN_ARG);
    value_node_1 = _mutable_node_value(BEL_VALUE_VAL, value_1);
    value_node_2 = _mutable_node_value(BEL_VALUE_VAL, value_2);

    arg->token->left  = value_node_1;
    arg->token->right = value_node_2;

    return arg;
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
    bel_ast_node* nv_node;
    bel_ast_node* pfx_node;
    bel_ast_node* val_node;
    char*         pfx_value;
    char*         val_value;

    pfx_value = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    val_value = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    memset(pfx_value, '\0', BEL_VALUE_CHAR_LEN);
    memset(val_value, '\0', BEL_VALUE_CHAR_LEN);

    nv_node  = bel_new_ast_node_token(BEL_TOKEN_NV);
    pfx_node = _mutable_node_value(BEL_VALUE_PFX, NULL);
    val_node = _mutable_node_value(BEL_VALUE_VAL, NULL);

    nv_node->token->left  = pfx_node;
    nv_node->token->right = val_node;

    return nv_node;
};

/* private */
bel_ast_node* _mutable_node_value(bel_ast_value_type type, char* value) {
    bel_ast_node* node;

    node = malloc(sizeof(bel_ast_node));
    node->value = malloc(sizeof(bel_ast_node_value));
    node->value->type  = BEL_VALUE;
    node->value->vtype = type;
    node->value->value = value;
    return node;
};

bel_ast_node* _set_wildcard_as_term_node(bel_ast_node* wildcard_node) {
    bel_ast_node* fx_node;
    bel_ast_node* arg_node;
    wildcard_node->token->ttype              = BEL_TOKEN_TERM;
    wildcard_node->token->left->value->vtype = BEL_VALUE_FX;

    // Convert wildcard to TERM:
    // - Move value pointer from right to left.
    fx_node = bel_new_ast_node_value(
        BEL_VALUE_FX,
        wildcard_node->token->right->value->value
    );

    bel_free_ast_node(wildcard_node->token->left);
    bel_free_ast_node(wildcard_node->token->right);

    wildcard_node->token->left = fx_node;
    arg_node = bel_new_ast_node_token(BEL_TOKEN_ARG);
    wildcard_node->token->right = arg_node;

    // Wildcard to TERM requires freeing right child; This node needs to be an
    // ARG now...

    // ...first, free right BEL_VALUE_VAL

    // ...then,  create an assign ARG to right
    /* term_arg_node = bel_new_ast_node_token(BEL_TOKEN_ARG); */
    /* wildcard_node->token->right = term_arg_node; */
    return wildcard_node;
};

bel_ast_node* _set_wildcard_as_nv_node(bel_ast_node* wildcard_node) {
    wildcard_node->token->ttype               = BEL_TOKEN_NV;
    wildcard_node->token->left->value->vtype  = BEL_VALUE_PFX;
    wildcard_node->token->right->value->vtype = BEL_VALUE_VAL;

    if (wildcard_node->token->left->value->value[0] == '\0') {
        free(wildcard_node->token->left->value->value);
        wildcard_node->token->left->value->value = NULL;
    }

    if (wildcard_node->token->right->value->value[0] == '\0') {
        free(wildcard_node->token->right->value->value);
        wildcard_node->token->right->value->value = NULL;
    }

    return wildcard_node;
};

void _swap_left_right(bel_ast_node* wildcard_node) {
    bel_ast_node* left;

    left = wildcard_node->token->left;
    wildcard_node->token->left  = wildcard_node->token->right;
    wildcard_node->token->right = left;
};

void _mark_subject_node_complete(bel_ast_node* statement_node) {
    bel_ast_node* subject_node;
    bel_ast_node* term_node;

    assert(statement_node != NULL);

    subject_node   = statement_node->token->left;
    term_node      = subject_node->token->left;

    if (term_node && term_node->token->is_complete) {
        subject_node->token->is_complete = 1;
    }
};

void _mark_object_node_complete(bel_ast_node* statement_node) {
    bel_ast_node* object_node;
    bel_ast_node* rel_node;
    bel_ast_node* object_term_or_statement_node;

    assert(statement_node != NULL);

    object_node                   = statement_node->token->right;
    rel_node                      = object_node->token->left;
    object_term_or_statement_node = object_node->token->right;

    if (rel_node && rel_node->token->is_complete &&
        (object_term_or_statement_node && object_term_or_statement_node->token->is_complete)) {

        object_node->token->is_complete = 1;
    }
};

void _mark_statement_node_complete(bel_ast_node* statement_node) {
    bel_ast_node* subject_node;
    bel_ast_node* object_node;

    assert(statement_node != NULL);

    subject_node                  = statement_node->token->left;
    // SUBJECT is not complete implies the STATEMENT is not complete
    if (!subject_node->token->is_complete) {
        statement_node->token->is_complete = 0;
        return;
    }

    object_node                   = statement_node->token->right;

    // OBJECT L:NULL R:NULL implies the STATEMENT is subject-only and complete
    if (object_node->token->left == NULL && object_node->token->right == NULL) {
        statement_node->token->is_complete = 1;
        return;
    }

    if (!object_node->token->is_complete) {
        statement_node->token->is_complete = 0;
        return;
    }

    // SUBJECT is complete and OBJECT L:REL R:TERM|STATEMENT is complete
    statement_node->token->is_complete = 1;
};

// vim: ft=ragel sw=4 ts=4 sts=4 expandtab

