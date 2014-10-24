#include "bel-ast.h"
#include "bel-token.h"

#ifndef _BEL_PARSER_H
#define _BEL_PARSER_H

bel_ast* parse_term(char* line);

bel_token_list* tokenize_term(char* line);

#endif /* not defined _BEL_PARSER_H */
