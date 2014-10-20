#include <stdio.h>
#include <string.h>
#include "belparser.h"

#test missing_namespace
    char line[BUFSIZE] = "p(AKT1)";
    char value[VALUE_SIZE];
    memset(value, '\0', VALUE_SIZE);

    fprintf(stdout, "%s\n", bel_ast_flat_string(parse_term(line, value)));

    fail_unless(
            strcmp(
                bel_ast_flat_string(parse_term(line, value)),
                "TERM fx(p) ARG NV pfx() val(AKT1) ARG NIL NIL \n"),
            "[parse_term] failed to parse terms missing namespace (e.g. p(AKT1))");
