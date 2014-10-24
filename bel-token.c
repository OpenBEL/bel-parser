#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bel-token.h"

bel_token* bel_new_token(bel_token_type type, char* input, char* ts, char* te) {
    bel_token *new_token;
    int       length;
    char      *copy_input;

    new_token = malloc(sizeof(bel_token));
    new_token->type = type;

    length = te - ts;
    copy_input = malloc(length + 1);
    strncpy(copy_input, ts, length);
    new_token->value = copy_input;
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
		fprintf(stdout, "IDENT(%s) ", next->value);
		break;
	    case STRING:
		fprintf(stdout, "STRING(%s) ", next->value);
		break;
	    case O_PAREN:
		fprintf(stdout, "O_PAREN(%s) ", next->value);
		break;
	    case C_PAREN:
		fprintf(stdout, "C_PAREN(%s) ", next->value);
		break;
	    case COLON:
		fprintf(stdout, "COLON(%s) ", next->value);
		break;
	    case COMMA:
		fprintf(stdout, "COMMA(%s) ", next->value);
		break;
	    case SPACES:
		fprintf(stdout, "SPACES(%s) ", next->value);
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

