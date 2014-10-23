#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-ast.h"
#include "bel-node-stack.h"
#include "bel-parser.h"

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
    char           *value;
} bel_token;

bel_token* bel_new_token(bel_token_type type, char* input, int ts, int te) {
    bel_token *new_token;
    int       length;
    char      *copy_input;

    new_token = malloc(sizeof(bel_token));
    new_token->type = type;

    length = te - ts;
    copy_input = malloc(length + 1);
    strncpy(copy_input, input, length);

    new_token->value = copy_input;
    return new_token;
};

%%{
    machine set;
    write data;
}%%

bel_token* parse_term_lookahead(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             ts;
    int             te;
    int             act;
    char            *eof;
    int             top;
    char            *value;
    int             fi;
    int             vi;
    bel_token       *tokens[256];

    p            = line;
    pe           = line + strlen(line);
    eof          = pe;
    top          = 0;
    value        = malloc(sizeof(char) * VALUE_CHAR_LEN);
    fi           = 0;
    vi           = 0;

    memset(value, '\0', VALUE_CHAR_LEN);

    %%{
        C_PAREN      = ')';
        COLON        = ':';
        COMMA        = ',';
        IDENT        = [a-zA-Z0-9_]+;
        O_PAREN      = '(';
        SPACES       = [ ]+;
        STRING       = '"' ('\\\"' | [^"])* '"';

        action IDENT   { bel_new_token(IDENT, p, ts, te);   }
        action STRING  { bel_new_token(STRING, p, ts, te);  }
        action O_PAREN { bel_new_token(O_PAREN, p, ts, te); }
        action C_PAREN { bel_new_token(C_PAREN, p, ts, te); }
        action COLON   { bel_new_token(COLON, p, ts, te);   }
        action COMMA   { bel_new_token(COMMA, p, ts, te);   }
        action SPACES  { bel_new_token(SPACES, p, ts, te);  }

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

    free(value);

    return tokens;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab
