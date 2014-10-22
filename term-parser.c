/*
 * Parses BEL terms.
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-parser.h"

#define LINE_CHAR_LEN 1024 * 32 // 32 kilobytes

int main(int argc, char *argv[]) {
    FILE *input;
    int len;
    char line[LINE_CHAR_LEN];

    if (argc == 2) {
        input = fopen(argv[1], "rb");
    } else {
        input = stdin;
    }

    int print = 0;
    if (getenv("AST_PRINT") != NULL) {
        print = 1;
    }

    int verbose = 0;
    if (getenv("AST_VERBOSE") != NULL) {
        verbose = 1;
    }

    while (fgets(line, LINE_CHAR_LEN, input) != NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (verbose) {
            fprintf(stdout, "parsing line -> %s\n", line);
        }

        bel_ast* tree = parse_term(line);

        if (!tree->root) {
            fprintf(stderr, "parse failed\n");
            exit(1);
        }

        if (print) {
            bel_print_ast(tree);
        }
        bel_free_ast(tree);
    }
    fclose(input);
    return 0;
}
// vim: ft=c sw=4 ts=4 sts=4 expandtab
