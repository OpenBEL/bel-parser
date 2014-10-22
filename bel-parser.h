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

bel_ast* parse_term(char* line);

#endif /* not defined _BEL_PARSER_H */
