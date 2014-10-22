#include "bel-ast.h"

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

bel_ast* parse_term(char* line);

#endif /* not defined _BEL_PARSER_H */
