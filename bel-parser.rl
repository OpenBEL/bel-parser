#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-parser.h"

const char* eof = EOF;

bel_node_stack* stack_init(int max) {
    bel_node_stack*  stack = (bel_node_stack *) malloc(sizeof(int) *2 + sizeof(bel_ast_node) * max );
    bel_ast_node*    contents[max];

    if (contents == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        return NULL;
    }

    stack->top      = -1;
    stack->max      = max;

    return stack;
};

void stack_destroy(bel_node_stack* stack) {
    free(stack);
};

bel_ast_node* stack_peek(bel_node_stack* stack) {
    if (stack_is_empty(stack)) {
        return NULL;
    }

    bel_ast_node* (*nodes)[] = &stack->contents;
    bel_ast_node*        top = (*nodes)[stack->top];
    return top;
};

void stack_push(bel_node_stack* stack, bel_ast_node* node) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Stack is full, cannot push\n");
        return;
    }

    bel_ast_node* (*nodes)[] = &stack->contents;
    (*nodes)[++stack->top] = node;
};

bel_ast_node* stack_pop(bel_node_stack* stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty, cannot pop\n");
        return;
    }

    bel_ast_node* (*nodes)[] = &stack->contents;
    bel_ast_node* popped_top = (*nodes)[stack->top--];
    return popped_top;
};

int stack_is_empty(bel_node_stack* stack) {
    return stack->top == -1;
};

int stack_is_full(bel_node_stack* stack) {
    return stack->top >= stack->max - 1;
};


bel_ast_node* bel_new_ast_node_token(bel_ast_token_type type) {
    bel_ast_node* node;
    node = malloc(sizeof(bel_ast_node));
    node->token = malloc(sizeof(bel_ast_node_token));
    node->token->type  = TOKEN;
    node->token->ttype = type;
    node->token->left  = NULL;
    node->token->right = NULL;
    return node;
};

bel_ast_node* bel_new_ast_node_value(bel_ast_value_type type, char value[]) {
    bel_ast_node* node;
    char*         copy_value;

    if (value) {
        copy_value = malloc(sizeof(char) * (strlen(value) + 1));
        strcpy(copy_value, value);
    } else {
        copy_value = NULL;
    }

    node = malloc(sizeof(bel_ast_node));
    node->value = malloc(sizeof(bel_ast_node_value));
    node->value->type  = VALUE;
    node->value->vtype = type;
    node->value->value = copy_value;
    return node;
};

bel_ast* bel_new_ast() {
    bel_ast* ast;
    ast = malloc(sizeof(bel_ast));
    ast->root = NULL;
    return ast;
};

void bel_free_ast(bel_ast* ast) {
    if (!ast) {
        return;
    }
    bel_free_ast_node(ast->root);
    free(ast);
};

void bel_free_ast_node(bel_ast_node* node) {
    if (node->type_info->type == TOKEN) {
        if (node->token->left != NULL) {
            bel_free_ast_node(node->token->left);
        }
        if (node->token->right != NULL) {
            bel_free_ast_node(node->token->right);
        }
    }
    free(node);
};

void bel_print_ast_node(bel_ast_node* node, char* tree_flat_string) {
    if (node == NULL) {
        strcat(tree_flat_string, "NULL ");
        return;
    }

    char val[VALUE_CHAR_LEN];
    switch(node->type_info->type) {
        case TOKEN:
            switch(node->type_info->ttype) {
                case TOKEN_ARG:
                    strcat(tree_flat_string, "ARG ");
                    break;
                case TOKEN_NV:
                    strcat(tree_flat_string, "NV ");
                    break;
                case TOKEN_TERM:
                    strcat(tree_flat_string, "TERM ");
                    break;
            };
            bel_print_ast_node(node->token->left, tree_flat_string);
            bel_print_ast_node(node->token->right, tree_flat_string);
            break;
        case VALUE:
            switch(node->type_info->vtype) {
                case VALUE_FX:
                    sprintf(val, "fx(%s) ", node->value->value);
                    strcat(tree_flat_string, val);
                    break;
                case VALUE_PFX:
                    sprintf(val, "pfx(%s) ", node->value->value);
                    strcat(tree_flat_string, val);
                    break;
                case VALUE_VAL:
                    sprintf(val, "val(%s) ", node->value->value);
                    strcat(tree_flat_string, val);
                    break;
            };
            break;
    };
};

void bel_print_ast(bel_ast* ast) {
    if (!ast) {
        return;
    }

    char tree_flat_string[1024 * 32];
    memset(tree_flat_string, '\0', 1024 * 32);
    bel_print_ast_node(ast->root, tree_flat_string);
    fprintf(stdout, "%s\n", tree_flat_string);
};

char* bel_ast_as_string(bel_ast* ast) {
    if (!ast) {
        return NULL;
    }

    char tree_flat_string[1024 * 32];
    memset(tree_flat_string, '\0', 1024 * 32);
    bel_print_ast_node(ast->root, tree_flat_string);
    return tree_flat_string;
};

void stack_print(bel_node_stack* stack) {
    int i;
    fprintf(stdout, "stack count: %d\n", (stack->top + 1));
    for(i = (stack->top); i > -1; i--) {
        char tree_flat_string[1024 * 32];
        memset(tree_flat_string, '\0', 1024 * 32);
        bel_ast_node* el = stack->contents[i];
        bel_print_ast_node(el, tree_flat_string);
        fprintf(stdout, "stack[%d]: %s\n", i, tree_flat_string);
    }
};

void stack_test() {
    bel_node_stack* stack = stack_init(5);
    bel_ast_node*    term = bel_new_ast_node_token(TOKEN_TERM);
    bel_ast_node*     arg = bel_new_ast_node_token(TOKEN_ARG);
    bel_ast_node*      nv = bel_new_ast_node_token(TOKEN_NV);
    stack_push(stack, term);
    stack_push(stack, arg);
    stack_push(stack, nv);
    stack_print(stack);
};

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
