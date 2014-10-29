#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bel-token.h"

bel_token* bel_new_token(bel_token_type type, char* input, char* ts, char* te) {
    bel_token *new_token;
    int       length;
    char      *match_copy;

    new_token = malloc(sizeof(bel_token));
    new_token->type = type;
    new_token->pos_start = ts - input;
    new_token->pos_end   = te - input;

    length = te - ts;
    match_copy = malloc(length + 1);
    strncpy(match_copy, ts, length);
    match_copy[length] = '\0';
    new_token->value = match_copy;
    return new_token;
};

void bel_print_token_list(bel_token_list* token_list) {
    bel_token *tokens;
    bel_token *next;
    int       token_i;

    if (!token_list) {
	return;
    }

    tokens  = token_list->tokens;
    int list_length = token_list->length;
    for (token_i = 0; token_i < list_length; token_i++) {
	next = &tokens[token_i];
	switch(next->type) {
	    case IDENT:
		fprintf(stdout, "IDENT(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	    case STRING:
		fprintf(stdout, "STRING(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	    case O_PAREN:
		fprintf(stdout, "O_PAREN(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	    case C_PAREN:
		fprintf(stdout, "C_PAREN(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	    case COLON:
		fprintf(stdout, "COLON(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	    case COMMA:
		fprintf(stdout, "COMMA(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	    case SPACES:
		fprintf(stdout, "SPACES(\"%s\", %d, %d) ", next->value, next->pos_start, next->pos_end);
		break;
	};
    }
    fprintf(stdout, "\n");
};

void free_bel_token(bel_token* token) {
    if (!token) {
	return;
    }
    if (token->value) {
        free(token->value);
    }
};

void free_bel_token_list(bel_token_list* token_list) {
    if (!token_list) {
	return;
    }

    int       token_i;
    int       list_length;
    bel_token *next;

    list_length = token_list->length;
    for (token_i = 0; token_i < list_length; token_i++) {
	next = &token_list->tokens[token_i];
	if (!next && next->value) {
	    free(next->value);
	}
	// FIXME Memory leak, cannot free, yields, "free(): invalid size"
	// free(next);
    }

    free(token_list->tokens);
    free(token_list);
};

