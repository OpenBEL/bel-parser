#include <stdlib.h>
#include <string.h>

#ifndef _BEL_TOKEN_H
#define _BEL_TOKEN_H

typedef enum {
    IDENT,
    STRING,
    O_PAREN,
    C_PAREN,
    COLON,
    COMMA,
    SPACES
} bel_token_type;

typedef struct {
    bel_token_type type;
    int            pos_start;
    int            pos_end;
    char           *value;
} bel_token;

typedef struct {
    int            length;
    bel_token      *tokens;
} bel_token_list;

bel_token* bel_new_token(bel_token_type type, char* input, char* ts, char* te);

bel_token_list* bel_new_token_list(int length);

void bel_print_token_list(bel_token_list* token_list);

void free_bel_token(bel_token* token);

void free_bel_token_list(bel_token_list* token_list);

#endif /* not defined _BEL_TOKEN_H */

