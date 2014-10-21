/*
 * Parses BEL terms.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "bel-parser.h"

int main(int argc, char *argv[]) {
    FILE *input;
    int len;
    char line[BUFSIZE];
    char value[VALUE_SIZE];

    if (argc == 2) {
        input = fopen(argv[1], "rb");
    } else {
        input = stdin;
    }

    while (fgets(line, BUFSIZE, input) != NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

	    memset(value, '\0', VALUE_SIZE);
	    fprintf(stdout, "parsing line -> %s\n", line);
        bel_ast* tree = parse_term(line, value);

        if (!tree->root) {
            fprintf(stderr, "parse failed\n");
            exit(1);
        }

        bel_print_ast_flat(tree);
        bel_free_ast(tree);
    }
    fclose(input);
    return 0;
}
// vim: ft=c sw=4 ts=4 sts=4 expandtab
