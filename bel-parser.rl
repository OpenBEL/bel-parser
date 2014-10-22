#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-ast.h"
#include "bel-node-stack.h"
#include "bel-parser.h"

const char* eof = EOF;

%%{
    machine set;
    write data;
}%%

bel_ast* parse_term(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             top;
    int             *stack;
    bel_ast_node*   term;
    bel_ast_node*   current_nv;
    bel_ast*        ast;
    bel_node_stack* term_stack;
    char            *function;
    char            *value;
    int             fi;
    int             vi;

    p            = line;
    pe           = line + strlen(line);
    top          = 0;
    stack        = malloc(sizeof(int) * TERM_STACK_SIZE);
    current_nv   = NULL;
    function     = malloc(sizeof(char) * VALUE_CHAR_LEN);
    value        = malloc(sizeof(char) * VALUE_CHAR_LEN);
    fi           = 0;
    vi           = 0;

    term_stack   = stack_init(TERM_STACK_SIZE);
    term         = bel_new_ast_node_token(TOKEN_TERM);
    ast          = bel_new_ast();
    ast->root    = term;

    stack_push(term_stack, term);
    memset(function, '\0', VALUE_CHAR_LEN);
    memset(value, '\0', VALUE_CHAR_LEN);

    %%{
        action fxc {
            fi = 0;
        }

        action valc {
            vi = 0;
        }

        action fxn {
            function[fi++] = fc;
        }

        action valn {
            value[vi++] = fc;
        }

        action FX {
            term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(TOKEN_ARG);

            memset(function, '\0', VALUE_CHAR_LEN);
            fi = 0;
        }

        action NESTED_FX {
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            bel_ast_node* arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);

            memset(function, '\0', VALUE_CHAR_LEN);
            memset(value, '\0', VALUE_CHAR_LEN);
            fi = 0;
        }

        action PFX {
            term = stack_peek(term_stack);

            // find ARG leaf
            bel_ast_node* arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(VALUE_VAL, "");
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(TOKEN_ARG);

            memset(value, '\0', VALUE_CHAR_LEN);
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

                current_nv               = bel_new_ast_node_token(TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(VALUE_PFX, "");
                current_nv->token->right = bel_new_ast_node_value(VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(VALUE_VAL, value);
            }

            current_nv = 0;
            memset(value, '\0', VALUE_CHAR_LEN);
            vi = 0;
        }

        action FCALL {
            fcall arguments;
        }

        action FRET {
            stack_pop(term_stack);
            fret;
        }

        SP           = ' ';
        O_PAREN      = '(';
        C_PAREN      = ')';
        COLON        = ':';
        IDENT        = [a-zA-Z0-9_]+;
        STRING       = '"' ('\\\"' | [^"])* '"';
        FUNCTION     = 'proteinAbundance'|'p'|'rnaAbundance'|'r'|'abundance'|'a'|'microRNAAbundance'|'m'|'geneAbundance'|'g'|'biologicalProcess'|'bp'|'pathology'|'path'|'complexAbundance'|'complex'|'translocation'|'tloc'|'cellSecretion'|'sec'|'cellSurfaceExpression'|'surf'|'reaction'|'rxn'|'compositeAbundance'|'composite'|'fusion'|'fus'|'degradation'|'deg'|'molecularActivity'|'act'|'catalyticActivity'|'cat'|'kinaseActivity'|'kin'|'phosphataseActivity'|'phos'|'peptidaseActivity'|'pep'|'ribosylationActivity'|'ribo'|'transcriptionalActivity'|'tscript'|'transportActivity'|'tport'|'gtpBoundActivity'|'gtp'|'chaperoneActivity'|'chap'|'proteinModification'|'pmod'|'substitution'|'sub'|'truncation'|'trunc'|'reactants'|'products'|'list';

        arguments :=
            (
                (IDENT >valc $valn ':')? @PFX (STRING|IDENT) >valc $valn %VAL |
                FUNCTION >fxc $fxn %NESTED_FX O_PAREN @FCALL
            )
            (
                SP* ',' SP*
                (
                    (IDENT >valc $valn ':')? @PFX (STRING|IDENT) >valc $valn %VAL |
                    FUNCTION >fxc $fxn %NESTED_FX O_PAREN @FCALL
                )
            )* C_PAREN @FRET;

        term :=
            FUNCTION >fxc $fxn %FX O_PAREN @FCALL C_PAREN;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    if (term_stack) {
        stack_destroy(term_stack);
    }

    return ast;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab
