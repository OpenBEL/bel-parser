#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-token.h"

%%{
    machine set;
    write data;
}%%

bel_token_list* tokenize_term(char* line) {
    int                  cs;
    char                 *p;
    char                 *pe;
    char                 *ts;
    char                 *te;
    int                  act;
    char                 *eof;
    int                  token_i;
    bel_token_list       *token_list;
    bel_token            *tokens;
    bel_token            *new_token;

    p                  = line;
    pe                 = line + strlen(line);
    eof                = pe;
    token_i            = 0;
    token_list         = malloc(sizeof(bel_token_list));
    tokens             = calloc(256, sizeof(bel_token));
    token_list->tokens = tokens;

    %%{
        C_PAREN      = ')';
        COLON        = ':';
        COMMA        = ',';
        IDENT        = [a-zA-Z0-9_]+;
        O_PAREN      = '(';
        SPACES       = [ ]+;
        STRING       = '"' ('\\\"' | [^"])* '"';

        action IDENT   {
            new_token = bel_new_token(IDENT, p, ts, te);
            tokens[token_i++] = *new_token;
        }
        action STRING  {
            new_token = bel_new_token(STRING, p, ts, te);
            tokens[token_i++] = *new_token;
        }
        action O_PAREN {
            new_token = bel_new_token(O_PAREN, p, ts, te);
            tokens[token_i++] = *new_token;
        }
        action C_PAREN {
            new_token = bel_new_token(C_PAREN, p, ts, te);
            tokens[token_i++] = *new_token;
        }
        action COLON   {
            new_token = bel_new_token(COLON, p, ts, te);
            tokens[token_i++] = *new_token;
        }
        action COMMA   {
            new_token = bel_new_token(COMMA, p, ts, te);
            tokens[token_i++] = *new_token;
        }
        action SPACES  {
            new_token = bel_new_token(SPACES, p, ts, te);
            tokens[token_i++] = *new_token;
        }

        term := |*
            IDENT    => IDENT;
            STRING   => STRING;
            O_PAREN  => O_PAREN;
            C_PAREN  => C_PAREN;
            COLON    => COLON;
            COMMA    => COMMA;
            SPACES   => SPACES;
        *|;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    token_list->length = token_i;
    return token_list;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab

