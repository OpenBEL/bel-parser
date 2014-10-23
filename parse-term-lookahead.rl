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
    bel_token       *tokens;

    p            = line;
    pe           = line + strlen(line);
    eof          = pe;
    top          = 0;
    value        = malloc(sizeof(char) * VALUE_CHAR_LEN);
    tokens       = malloc(sizeof(bel_token) * 256);
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

        action STATE {
            fprintf(stdout, "state: %d\n", fcurs);
        }

        term := |*
            IDENT    => { fprintf(stdout, "IDENT\n");   };
            STRING   => { fprintf(stdout, "STRING\n");  };
            O_PAREN  => { fprintf(stdout, "O_PAREN\n"); };
            C_PAREN  => { fprintf(stdout, "C_PAREN\n"); };
            COLON    => { fprintf(stdout, "COLON\n");   };
            COMMA    => { fprintf(stdout, "COMMA\n");   };
            SPACES   => { fprintf(stdout, "SPACES\n");  };
        *|;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    free(value);

    return tokens;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab
