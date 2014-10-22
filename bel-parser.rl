#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-parser.h"

const char* eof = EOF;

bel_arg_stack* stack_init(int max) {
    bel_arg_stack* stack;
    bel_ast_node*  contents;

    stack = (bel_arg_stack *) malloc(sizeof(bel_arg_stack));
    contents = (bel_ast_node *) malloc(sizeof(bel_ast_node) * max);

    if (contents == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        exit(1);  /* Exit, returning error code. */
    }

    stack->top      = -1;
    stack->max      = max;
    stack->contents = contents;

    return stack;
};

void stack_destroy(bel_arg_stack* stack) {
    free(stack->contents);
    stack->top = -1;
    stack->max = 0;
    stack->contents = NULL;
};

bel_ast_node* stack_peek(bel_arg_stack* stack) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Can't push element on stack: stack is full.\n");
        exit(1);
    }

    bel_ast_node* top = &(stack->contents[stack->top]);
    return top;
};

void stack_push(bel_arg_stack* stack, bel_ast_node element) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Can't push element on stack: stack is full.\n");
        exit(1);
    }

    stack->contents[++stack->top] = element;
};

bel_ast_node* stack_pop(bel_arg_stack* stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
        exit(1);
    }

    bel_ast_node* popped = &(stack->contents[stack->top--]);
    return popped;
};

int stack_is_empty(bel_arg_stack* stack) {
    return stack->top < 0;
};

int stack_is_full(bel_arg_stack* stack) {
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

    char val[VALUE_SIZE];
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

    char tree_flat_string[1024];
    memset(tree_flat_string, '\0', 1024);
    bel_print_ast_node(ast->root, tree_flat_string);
    fprintf(stdout, "%s\n", tree_flat_string);
};

char* bel_ast_as_string(bel_ast* ast) {
    if (!ast) {
        return NULL;
    }

    char tree_flat_string[1024];
    memset(tree_flat_string, '\0', 1024);
    bel_print_ast_node(ast->root, tree_flat_string);
    return tree_flat_string;
};

%%{
    machine set;
    write data;
}%%

bel_ast* parse_term(char* line) {
    int            cs;
    char           *p;
    char           *pe;
    int            top;
    int            *stack;
    bel_ast_node*  current_term;
    bel_ast_node*  current_nv;
    bel_ast_node*  arg;
    bel_ast_node*  next_arg;
    bel_ast*       ast;
    bel_arg_stack* arg_stack;
    bel_ast_node*  arg_top;
    char           *function;
    char           *value;
    int            fi;
    int            vi;

    p            = line;
    pe           = line + strlen(line);
    top          = 0;
    stack        = malloc(sizeof(int) * ARG_STACK_SIZE);
    current_term = NULL;
    current_nv   = NULL;
    arg          = NULL;
    next_arg     = NULL;
    arg_top      = NULL;
    arg_stack    = stack_init(ARG_STACK_SIZE);
    function     = malloc(sizeof(char) * VALUE_SIZE);
    value        = malloc(sizeof(char) * VALUE_SIZE);
    current_term = bel_new_ast_node_token(TOKEN_TERM);
    ast          = bel_new_ast();
    ast->root    = current_term;
    fi           = 0;
    vi           = 0;

    memset(function, '\0', VALUE_SIZE);
    memset(value, '\0', VALUE_SIZE);

    %%{
        action fxc {
            memset(function, '\0', VALUE_SIZE);
            fi = 0;
        }

        action valc {
            memset(value, '\0', VALUE_SIZE);
            vi = 0;
        }

        action fxn {
            function[fi++] = fc;
        }

        action valn {
            value[vi++] = fc;
        }

        action FX {
            current_term->token->left = bel_new_ast_node_value(VALUE_FX, function);

            // Create Nil argument as a placeholder; add to stack
            arg = bel_new_ast_node_token(TOKEN_ARG);
            stack_push(arg_stack, *arg);

            // Set as term argument
            current_term->token->right = arg;

            memset(function, '\0', VALUE_SIZE);
            fi = 0;
        }

        action NESTED_FX {
            current_term = bel_new_ast_node_token(TOKEN_TERM);
            current_term->token->left = bel_new_ast_node_value(VALUE_FX, function);

            arg = bel_new_ast_node_token(TOKEN_ARG);
            current_term->token->right = arg;

            bel_ast_node* arg_top = stack_peek(arg_stack);
            arg_top->token->left = current_term;

            stack_push(arg_stack, *arg);

            memset(function, '\0', VALUE_SIZE);
            fi = 0;
        }

        action PFX {
            bel_ast_node* arg_top = stack_peek(arg_stack);
            current_nv = bel_new_ast_node_token(TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(VALUE_VAL, "");
            arg_top->token->left = current_nv;

            next_arg = bel_new_ast_node_token(TOKEN_ARG);
            arg_top->token->right = next_arg;
            stack_push(arg_stack, *next_arg);

            memset(value, '\0', VALUE_SIZE);
            vi = 0;
        }

        action VAL {
            bel_ast_node* arg_top = stack_peek(arg_stack);
            if (!current_nv) {
                current_nv = bel_new_ast_node_token(TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(VALUE_PFX, "");
                current_nv->token->right = bel_new_ast_node_value(VALUE_VAL, value);
                arg_top->token->left = current_nv;

                next_arg = bel_new_ast_node_token(TOKEN_ARG);
                arg_top->token->right = next_arg;
                stack_push(arg_stack, *next_arg);
            } else {
                current_nv->token->right = bel_new_ast_node_value(VALUE_VAL, value);
            }

            current_nv = 0;
            memset(value, '\0', VALUE_SIZE);
            vi = 0;
        }

        action FCALL {
            fcall arguments;
        }

        action FRET {
            fhold;
            fret;
        }

        SP           = ' ';
        O_PAREN      = '(';
        C_PAREN      = ')';
        COLON        = ':';
        IDENT        = [a-zA-Z0-9_]+;
        STRING       = ('"' ('\\\"' | [^"])* '"');
        FUNCTION     = ('proteinAbundance'|'p'|'rnaAbundance'|'r'|'abundance'|'a'|'microRNAAbundance'|'m'|'geneAbundance'|'g'|'biologicalProcess'|'bp'|'pathology'|'path'|'complexAbundance'|'complex'|'translocation'|'tloc'|'cellSecretion'|'sec'|'cellSurfaceExpression'|'surf'|'reaction'|'rxn'|'compositeAbundance'|'composite'|'fusion'|'fus'|'degradation'|'deg'|'molecularActivity'|'act'|'catalyticActivity'|'cat'|'kinaseActivity'|'kin'|'phosphataseActivity'|'phos'|'peptidaseActivity'|'pep'|'ribosylationActivity'|'ribo'|'transcriptionalActivity'|'tscript'|'transportActivity'|'tport'|'gtpBoundActivity'|'gtp'|'chaperoneActivity'|'chap'|'proteinModification'|'pmod'|'substitution'|'sub'|'truncation'|'trunc'|'reactants'|'products'|'list');

        arguments :=
            (
                (IDENT >valc $valn ':')? @PFX (STRING|IDENT) >valc $valn %VAL |
                FUNCTION >fxc $fxn %NESTED_FX O_PAREN @FCALL C_PAREN
            )
            (
                SP* ',' SP*
                (
                    (IDENT >valc $valn ':')? @PFX (STRING|IDENT) >valc $valn %VAL |
                    FUNCTION >fxc $fxn %NESTED_FX O_PAREN @FCALL C_PAREN
                )
            )*
            C_PAREN? @FRET;

        term :=
            FUNCTION >fxc $fxn %FX O_PAREN @FCALL C_PAREN;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    if (arg_stack) {
        stack_destroy(arg_stack);
    }

    return ast;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab
