// #include <stdio.h>

#ifndef _BEL_PARSER_H
#define _BEL_PARSER_H

#define VALUE_SIZE 1024
#define BUFSIZE    1024 * 32 // 32 kilobytes
#define ARG_STACK_SIZE 100
const char* eof;

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
    char*              value;
};

typedef struct {
    bel_ast_node* root;
} bel_ast;

typedef struct {
    int                        top;
    int                        max;
    bel_ast_node*              contents;
} bel_arg_stack;

bel_arg_stack* stack_init(int max);

void stack_destroy(bel_arg_stack* stack);

bel_ast_node* stack_peek(bel_arg_stack* stack);

void stack_push(bel_arg_stack* stack, bel_ast_node element);

bel_ast_node stack_pop(bel_arg_stack* stack);

int stack_is_empty(bel_arg_stack* stack);

int stack_is_full(bel_arg_stack* stack);

bel_ast_node* bel_new_ast_node_token(bel_ast_token_type type);

bel_ast_node* bel_new_ast_node_value(bel_ast_value_type type, char value[]);

bel_ast* bel_new_ast();

void bel_free_ast_node(bel_ast_node* node);

void bel_free_ast(bel_ast* ast);

void bel_print_ast_node(bel_ast_node* node);

void bel_print_ast_node_flat(bel_ast_node* node, char* tree_flat_string);

void bel_print_ast(bel_ast* ast);

void bel_print_ast_flat(bel_ast* ast);

char* bel_ast_flat_string(bel_ast* ast);

bel_ast* parse_term(char* line, char value[]);

#endif /* not defined _BEL_PARSER_H */
