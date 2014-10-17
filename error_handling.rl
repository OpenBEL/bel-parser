/*
 * Parses annotation records from a file.
 * TODO Parse from file or stdin.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

%%{
    machine set;
    write data;
}%%

char* eof = 0;

void parse(char *str)
{
    char *p = str, *pe = str + strlen(str);
    int cs;

    %%{
        action cmd_err {
            printf("command error\n");
            fhold; fgoto line;
        }
        action from_err {
            printf("from error\n");
            fhold; fgoto line;
        }
        action to_err {
            printf("to error\n");
            fhold; fgoto line;
        }

        ws       = ' ';
        address  = [0-9]+ ws+ [A-Za-z0-9]+ ('st'|'rd'|'blvd');
        date     = [0-9]{4} '-' [0-9]{2} '-' [0-9]{2};

        line    := [^\n]* '\n' @{ fgoto main; };

        main := (
            (
                'from' @err(cmd_err) ( ws+ address ws+ date '\n' ) $err(from_err) |
                'to' @err(cmd_err) ( ws+ address '\n' ) $err(to_err)
            )
        )* '\n';

        # Initialize and execute.
        write init;
        write exec;
    }%%

    return;
};

#define BUFSIZE 1024 * 32

int main(int argc, char *argv[])
{
    FILE *input;
    if (argc == 2) {
        input = fopen(argv[1], "rb");
    } else {
        input = stdin;
    }
    
    int len;
    char line[BUFSIZE];

    while (fgets(line, BUFSIZE, input) != NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        parse(line);
    }
    fclose(input);
    return 0;
}
