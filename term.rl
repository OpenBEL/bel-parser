/*
 * Parses BEL terms.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "belparser.h"

%%{
    machine set;
    write data;
}%%

bel_arg_stack* stack_init(int max) {
    bel_arg_stack* stack;
    struct bel_ast_node_token *contents;

    stack = (bel_arg_stack *) malloc(sizeof(bel_arg_stack));
    contents = (struct bel_ast_node_token *) malloc(sizeof(bel_ast_node_token) * max);

    if (contents == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        exit(1);  /* Exit, returning error code. */
    }

    stack->top      = -1;
    stack->max      = max;
    stack->contents = contents;

    return stack;
};

void stack_destory(bel_arg_stack* stack) {
    free(stack->contents);
    stack->top = -1;
    stack->max = 0;
    stack->contents = NULL;
};

void stack_push(bel_arg_stack* stack, struct bel_ast_node_token element) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Can't push element on stack: stack is full.\n");
        exit(1);
    }

    stack->contents[++stack->top] = element;
};

struct bel_ast_node_token stack_pop(bel_arg_stack* stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
        exit(1);
    }

    return stack->contents[stack->top--];
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

    fprintf(stdout, "size of value: %lu, value: %s\n", (sizeof(value)+1), value);
    copy_value = malloc(sizeof(value) + 1);
    strcpy(copy_value, value);

    node = malloc(sizeof(bel_ast_node));
    node->value = malloc(sizeof(bel_ast_node_value));
    node->value->type  = VALUE;
    node->value->vtype = type;
    node->value->value = copy_value;
    return node;
};

bel_ast* bel_new_ast(bel_ast_token_type type) {
    bel_ast* ast;
    ast = malloc(sizeof(bel_ast));
    ast->root = bel_new_ast_node_token(type);
    return ast;
};

void bel_print_ast_node(bel_ast_node* node) {
    if (!node) {
        return;
    }

    switch(node->type_info->type) {
    case TOKEN:
        switch(node->type_info->ttype) {
            case TOKEN_ARG:
                fprintf(stdout, "ARG\n");
                break;
            case TOKEN_NIL:
                fprintf(stdout, "NIL\n");
                break;
            case TOKEN_NV:
                fprintf(stdout, "NV\n");
                break;
            case TOKEN_TERM:
                fprintf(stdout, "TERM\n");
                break;
        }
        bel_print_ast_node(node->token->left);
        bel_print_ast_node(node->token->right);
        break;
    case VALUE:
        switch(node->type_info->vtype) {
            case VALUE_FX:
                fprintf(stdout, "fx(%s)\n", node->value->value);
                break;
            case VALUE_NIL:
                fprintf(stdout, "nil(%s)\n", node->value->value);
                break;
            case VALUE_PFX:
                fprintf(stdout, "pfx(%s)\n", node->value->value);
                break;
            case VALUE_VAL:
                fprintf(stdout, "val(%s)\n", node->value->value);
                break;
        }
        break;
    }
}

void bel_print_ast(bel_ast* ast) {
    if (!ast) {
        return;
    }
    bel_print_ast_node(ast->root);
};

#define VALUE_SIZE 128
#define BUFSIZE    1024 * 32 // 32 kilobytes

bel_ast* parse_term(char* line, char value[]) {
    char *p = line, *pe = line + strlen(line);
    bel_ast* ast;
    bel_ast_node* next;
    bel_ast_node* arg;
    int cs;
    int vi = 0;

    %%{
        action vi {
            value[vi++] = fc;
        }

        action FX {
	        fprintf(stdout, "FX action: %s\n", value);
            ast = bel_new_ast(TOKEN_TERM);
            ast->root->token->left  = bel_new_ast_node_value(VALUE_FX,  value);

            arg = bel_new_ast_node_token(TOKEN_NIL);
            ast->root->token->right = arg;

	        memset(value, '\0', VALUE_SIZE);
            vi = 0;
        }

        action PFX {
	        fprintf(stdout, "PFX action: %s\n", value);
            next = bel_new_ast_node_token(TOKEN_NV);
            next->token->left  = bel_new_ast_node_value(VALUE_PFX, value);
            next->token->right = bel_new_ast_node_value(VALUE_NIL, "\0");

            arg = bel_new_ast_node_token(TOKEN_ARG);
            arg->token->left  = next;
            arg->token->right = bel_new_ast_node_token(TOKEN_NIL);

            ast->root->token->right = arg;

	        fprintf(stdout, "end of PFX\n");
	        memset(value, '\0', VALUE_SIZE);
            vi = 0;
        }

        action VAL {
	        fprintf(stdout, "VAL action: %s\n", value);
            next->token->right = bel_new_ast_node_value(VALUE_VAL, value);

	        memset(value, '\0', VALUE_SIZE);
            vi = 0;
        }

        SP           = ' ';
        O_PAREN      = '(';
        C_PAREN      = ')';
        COLON        = ':';
        IDENT        = [a-zA-Z0-9_]+;
        STRING       = ('"' ('\\\"' | [^"])* '"');
        FUNCTION     = ('proteinAbundance'|'p'|'rnaAbundance'|'r'|'abundance'|'a'|'microRNAAbundance'|'m'|'geneAbundance'|'g'|'biologicalProcess'|'bp'|'pathology'|'path'|'complexAbundance'|'complex'|'translocation'|'tloc'|'cellSecretion'|'sec'|'cellSurfaceExpression'|'surf'|'reaction'|'rxn'|'compositeAbundance'|'composite'|'fusion'|'fus'|'degradation'|'deg'|'molecularActivity'|'act'|'catalyticActivity'|'cat'|'kinaseActivity'|'kin'|'phosphataseActivity'|'phos'|'peptidaseActivity'|'pep'|'ribosylationActivity'|'ribo'|'transcriptionalActivity'|'tscript'|'transportActivity'|'tport'|'gtpBoundActivity'|'gtp'|'chaperoneActivity'|'chap'|'proteinModification'|'pmod'|'substitution'|'sub'|'truncation'|'trunc'|'reactants'|'products'|'list');
#       FUNCTION     = ('p'|'r'|'a'|'m'|'g'|'bp');

#        term =
#            FUNCTION $vi %FX <>lerr(FX) O_PAREN C_PAREN;
        term =
            FUNCTION $vi %FX O_PAREN (IDENT $vi ':')? @PFX (STRING $vi | IDENT $vi) %VAL C_PAREN;

        main :=
            term;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    return ast;
};

int main(int argc, char *argv[]) {
    FILE *input;
    int len;
    char line[BUFSIZE];
    char value[VALUE_SIZE];
    bel_ast* tree;

    if (argc == 2) {
        input = fopen(argv[1], "rb");
    } else {
        input = stdin;
    }

    while (fgets(line, BUFSIZE, input) != NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

	memset(value, '\0', VALUE_SIZE);
	fprintf(stdout, "parsing line -> %s\n", line);
        tree = parse_term(line, value);

        bel_print_ast(tree);
    }
    fclose(input);
    return 0;
}

// vim: ft=c sw=4 ts=4 sts=4 expandtab
