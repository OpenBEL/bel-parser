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

void parse(char *str, char* name, char* value)
{
    char *p = str, *pe = str + strlen(str);
    int cs;
    int name_index = 0, value_index = 0;

    %%{
        action name {
            name[name_index++] = fc;
        }
        action value {
            value[value_index++] = fc;
        }
        SP = ' ';
        SET = /SET/;
        SETD = /SET DOCUMENT/;
        IDENT = [a-zA-Z0-9_]+;
        EQUALS = '=';
        STRING = ('"' ('\\\"' | [^"])* '"');
        LIST = '{' SP* STRING* SP* (',' SP* STRING)* '}';
        set = 
            SET SP+ IDENT+$name SP+ EQUALS SP+ (STRING | IDENT | LIST)$value;
        set_doc =
            SETD SP+ IDENT+$name SP+ EQUALS SP+ (STRING | IDENT)$value;
        main := 
            set_doc | set;

        # Initialize and execute.
        write init;
        write exec;
    }%%

    return;
};

#define NAMELEN 128
#define BUFSIZE 1024 * 32 // 32 kilobytes

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

        char name[NAMELEN], value[BUFSIZE];
        memset(&name, 0, sizeof(name));
        memset(&value, 0, sizeof(value));
        parse(line, name, value);

        printf("%s -> %s\n", name, value);
    }
    fclose(input);
    return 0;
}
