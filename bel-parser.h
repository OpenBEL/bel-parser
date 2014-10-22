// #include <stdio.h>

#ifndef _BEL_PARSER_H
#define _BEL_PARSER_H

/*
 * Value size: The maximum number of characters to hold in an
 * accumulated value.
 */
#define VALUE_CHAR_LEN 512

/*
 * Term stack size: A value of 20 allows for a nesting of
 * a max of 20 terms.
 */
#define TERM_STACK_SIZE 20

const char* eof;

typedef enum {
    TOKEN,
    VALUE
} bel_ast_node_type;

typedef enum {
    TOKEN_TERM,
    TOKEN_ARG,
    TOKEN_NV
} bel_ast_token_type;

typedef enum {
    VALUE_FX,
    VALUE_PFX,
    VALUE_VAL
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
    char*              value;
};

typedef struct {
    bel_ast_node* root;
} bel_ast;

typedef struct {
    int                        top;
    int                        max;
    bel_ast_node*              contents[];
} bel_node_stack;

bel_node_stack* stack_init(int max);

void stack_destroy(bel_node_stack* stack);

bel_ast_node* stack_peek(bel_node_stack* stack);

void stack_push(bel_node_stack* stack, bel_ast_node* node);

bel_ast_node* stack_pop(bel_node_stack* stack);

int stack_is_empty(bel_node_stack* stack);

int stack_is_full(bel_node_stack* stack);

bel_ast_node* bel_new_ast_node_token(bel_ast_token_type type);

bel_ast_node* bel_new_ast_node_value(bel_ast_value_type type, char value[]);

bel_ast* bel_new_ast();

void bel_free_ast_node(bel_ast_node* node);

void bel_free_ast(bel_ast* ast);

void bel_print_ast_node(bel_ast_node* node, char* tree_flat_string);

void bel_print_ast(bel_ast* ast);

char* bel_ast_as_string(bel_ast* ast);

bel_ast* parse_term(char* line);

#endif /* not defined _BEL_PARSER_H */
