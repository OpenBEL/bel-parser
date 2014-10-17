/*
 * Parses annotation records from a file.
 * TODO Parse from file or stdin.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char* eof = EOF;

%%{
    machine set;
    write data;
}%%

typedef enum {
    TOKEN,
    VALUE
} bel_ast_node_type;

typedef enum {
    TOKEN_TERM,
    TOKEN_ARG,
    TOKEN_NV,
    TOKEN_NIL
} bel_ast_token_type;

typedef enum {
    VALUE_FX,
    VALUE_PFX,
    VALUE_VAL,
    VALUE_NIL
} bel_ast_value_type;

typedef struct {
    bel_ast_node_type type;
    union {
    bel_ast_token_type ttype;
    bel_ast_value_type vtype;
    };
} bel_ast_node_type_info;

typedef struct bel_ast_node_token bel_ast_node_token;
typedef struct bel_ast_node_value bel_ast_node_value;

typedef struct {
    union {
    bel_ast_node_type_info* type_info;
    bel_ast_node_token*    token;
    bel_ast_node_value*    value;
    };
} bel_ast_node;

struct bel_ast_node_token {
    bel_ast_node_type  type;
    bel_ast_token_type ttype;
    bel_ast_node*      left;
    bel_ast_node*      right;
};

struct bel_ast_node_value {
    bel_ast_node_type  type;
    bel_ast_value_type vtype;
    unsigned char*     value;
};

typedef struct {
    bel_ast_node* root;
} bel_ast;

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

bel_ast_node* bel_new_ast_node_value(bel_ast_value_type type, unsigned char* value) {
    bel_ast_node* node;
    unsigned char* copy_value;

    copy_value = (unsigned char*) malloc(sizeof(value) + 1);
    memcpy(copy_value, value, sizeof(value) + 1);

    node = malloc(sizeof(bel_ast_node));
    node->value = malloc(sizeof(bel_ast_node_value));
    node->value->type  = VALUE;
    node->value->vtype = type;
    node->value->value = value;
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
                fprintf(stdout, "fx\n");
                break;
            case VALUE_NIL:
                fprintf(stdout, "nil\n");
                break;
            case VALUE_PFX:
                fprintf(stdout, "pfx\n");
                break;
            case VALUE_VAL:
                fprintf(stdout, "val\n");
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

bel_ast* parse_term(char* line, unsigned char* value) {
    char *p = line, *pe = line + strlen(line);
    bel_ast* ast;
    int cs;
    int vi = 0;

    %%{
        action vi {
            value[vi++] = fc;
        }

        action FX {
            ast = bel_new_ast(TOKEN_TERM);
            ast->root->token->left  = bel_new_ast_node_value(VALUE_FX,  value);
            ast->root->token->right = bel_new_ast_node_token(TOKEN_NIL);
        }

        SP           = ' ';
        O_PAREN      = '(';
        C_PAREN      = ')';
        COLON        = ':';
        IDENT        = [a-zA-Z0-9_]+;
        STRING       = ('"' ('\\\"' | [^"])* '"');
        FUNCTION     = ('proteinAbundance'|'p'|'rnaAbundance'|'r'|'abundance'|'a'|'microRNAAbundance'|'m'|'geneAbundance'|'g'|'biologicalProcess'|'bp'|'pathology'|'path'|'complexAbundance'|'complex'|'translocation'|'tloc'|'cellSecretion'|'sec'|'cellSurfaceExpression'|'surf'|'reaction'|'rxn'|'compositeAbundance'|'composite'|'fusion'|'fus'|'degradation'|'deg'|'molecularActivity'|'act'|'catalyticActivity'|'cat'|'kinaseActivity'|'kin'|'phosphataseActivity'|'phos'|'peptidaseActivity'|'pep'|'ribosylationActivity'|'ribo'|'transcriptionalActivity'|'tscript'|'transportActivity'|'tport'|'gtpBoundActivity'|'gtp'|'chaperoneActivity'|'chap'|'proteinModification'|'pmod'|'substitution'|'sub'|'truncation'|'trunc'|'reactants'|'products'|'list');

#        term =
#            FUNCTION $vi %FX <>lerr(FX) O_PAREN C_PAREN;
        term =
            FUNCTION $vi %FX O_PAREN C_PAREN;

        main :=
            term;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    return ast;
};

#define VALUE_SIZE 128
#define BUFSIZE    1024 * 32 // 32 kilobytes

int main(int argc, char *argv[]) {
    FILE *input;
    int len;
    char line[BUFSIZE];
    unsigned char value[VALUE_SIZE];
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

        memset(&value, 0, sizeof(value));
        tree = parse_term(line, value);

        bel_print_ast(tree);
    }
    fclose(input);
    return 0;
}

// vim: ft=c sw=4 ts=4 sts=4 expandtab
