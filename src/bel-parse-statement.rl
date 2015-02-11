#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-ast.h"
#include "bel-node-stack.h"

/*
 * Value size: The maximum number of characters to hold in an
 * accumulated value.
 */
#define BEL_VALUE_CHAR_LEN 512

/*
 * Term stack size: A value of 20 allows for a nesting of
 * a max of 20 terms.
 */
#define TERM_STACK_SIZE 20

%%{
    machine set;
    write data;
}%%

bel_ast* bel_parse_statement(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             top;
    int             *stack;
    bel_ast_node*   statement;
    bel_ast_node*   subject;
    bel_ast_node*   rel;
    bel_ast_node*   object;
    bel_ast_node*   term;
    bel_ast_node*   current_nv;
    bel_ast*        ast;
    bel_node_stack* term_stack;
    char            *function;
    char            *relationship;
    char            *value;
    int             fi;
    int             ri;
    int             vi;

    p            = line;
    pe           = line + strlen(line);
    top          = 0;
    stack        = malloc(sizeof(int) * TERM_STACK_SIZE);
    current_nv   = NULL;
    function     = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    relationship = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value        = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    fi           = 0;
    ri           = 0;
    vi           = 0;

    term_stack   = stack_init(TERM_STACK_SIZE);
    statement    = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
    subject      = bel_new_ast_node_token(BEL_TOKEN_SUBJECT);
    rel          = bel_new_ast_node_token(BEL_TOKEN_REL);
    object       = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
    ast          = bel_new_ast();
    ast->root    = statement;

    memset(function, '\0', BEL_VALUE_CHAR_LEN);
    memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
    memset(value, '\0', BEL_VALUE_CHAR_LEN);

    %%{
        action fxc {
            fi = 0;
        }

        action relc {
            ri = 0;
        }

        action valc {
            vi = 0;
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

            memset(function, '\0', BEL_VALUE_CHAR_LEN);
            fi = 0;
        }

        action REL {
            rel->token->left = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            object->token->left = rel;

            memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
            ri = 0;
        }

        action NESTED_FX {
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            bel_ast_node* arg = term_top->token->right;
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

            memset(function, '\0', BEL_VALUE_CHAR_LEN);
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
            fi = 0;
        }

        action PFX {
            term = stack_peek(term_stack);

            // find ARG leaf
            bel_ast_node* arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);

            memset(value, '\0', BEL_VALUE_CHAR_LEN);
            vi = 0;
        }

        action VAL {
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                bel_ast_node* arg = term->token->right;
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
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
            vi = 0;
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
            if (statement->token->left == NULL) {
                // statement left token (e.g. subject) is available
                subject->token->left = bel_copy_ast_node(term);
                statement->token->left = subject;
            } else {
                // assume right token (e.g. object) is available
                object->token->right = bel_copy_ast_node(term);
                statement->token->right = object;
            }

            fret;
        }

        SP           = ' ';
        NL           = '\n' | '\r' '\n'?;
        O_PAREN      = '(';
        C_PAREN      = ')';
        COLON        = ':';
        STRING       = '"' ('\\\"' | [^"])* '"';
        IDENT        = [a-zA-Z0-9_];
        FUNCTION     = 'proteinAbundance'|'p'|'rnaAbundance'|'r'|'abundance'|'a'|'microRNAAbundance'|'m'|'geneAbundance'|'g'|'biologicalProcess'|'bp'|'pathology'|'path'|'complexAbundance'|'complex'|'translocation'|'tloc'|'cellSecretion'|'sec'|'cellSurfaceExpression'|'surf'|'reaction'|'rxn'|'compositeAbundance'|'composite'|'fusion'|'fus'|'degradation'|'deg'|'molecularActivity'|'act'|'catalyticActivity'|'cat'|'kinaseActivity'|'kin'|'phosphataseActivity'|'phos'|'peptidaseActivity'|'pep'|'ribosylationActivity'|'ribo'|'transcriptionalActivity'|'tscript'|'transportActivity'|'tport'|'gtpBoundActivity'|'gtp'|'chaperoneActivity'|'chap'|'proteinModification'|'pmod'|'substitution'|'sub'|'truncation'|'trunc'|'reactants'|'products'|'list';
        RELATIONSHIP = 'increases'|'decreases'|'-|'|'directlyIncreases'|'=>'|'directlyDecreases'|'=|'|'causesNoChange'|'positiveCorrelation'|'negativeCorrelation'|'translatedTo'|'>>'|'transcribedTo'|':>'|'isA'|'subProcessOf'|'rateLimitingStepOf'|'biomarkerFor'|'prognosticBiomarkerFor'|'orthologous'|'analogous'|'association'|'--'|'hasMembers'|'hasComponents'|'hasMember'|'hasComponent';

        arguments :=
            (
                (IDENT+ >valc $valn ':')? @PFX (STRING|IDENT+) >valc $valn %VAL |
                FUNCTION >fxc $fxn %NESTED_FX O_PAREN @CALL_ARGUMENTS
            )
            (
                SP* ',' SP*
                (
                    (IDENT+ >valc $valn ':')? @PFX (STRING|IDENT+) >valc $valn %VAL |
                    FUNCTION >fxc $fxn %NESTED_FX O_PAREN @CALL_ARGUMENTS
                )
            )* C_PAREN @RET_ARGUMENTS;

        term :=
            FUNCTION >fxc $fxn %FX O_PAREN >CALL_ARGUMENTS (SP+|NL) @RET_TERM;

        statement :=
            IDENT @CALL_TERM RELATIONSHIP >relc $reln @REL SP+ IDENT @CALL_TERM;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    // free allocations
    bel_free_ast_node(term);
    if (term_stack) {
        stack_destroy(term_stack);
    }
    free(stack);
    free(function);
    free(relationship);
    free(value);

    return ast;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab

