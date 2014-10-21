#include <stdio.h>
#include <string.h>
#include "bel-parser.h"

#test supports_parameters_without_namespace
    char line[BUFSIZE] = "p(AKT1)";
    char value[VALUE_SIZE];
    memset(value, '\0', VALUE_SIZE);

    fail_unless(
            strcmp(
                bel_ast_flat_string(parse_term(line, value)),
                "TERM fx(p) ARG NV pfx() val(AKT1) ARG NIL NIL ") == 0,
            "[parse_term] failed to parse parameter without namespace (e.g. AKT1)");

#test supports_parameters_with_namespace
    char line[BUFSIZE] = "p(HGNC:AKT1)";
    char value[VALUE_SIZE];
    memset(value, '\0', VALUE_SIZE);

    fail_unless(
            strcmp(
                bel_ast_flat_string(parse_term(line, value)),
                "TERM fx(p) ARG NV pfx(HGNC) val(AKT1) ARG NIL NIL ") == 0,
            "[parse_term] failed to parse parameter with namespace (e.g. HGNC:AKT1)");

#test supports_multiple_parameters
    char line[BUFSIZE] = "p(AKT1, HGNC:AKT2, AKT3)";
    char value[VALUE_SIZE];
    memset(value, '\0', VALUE_SIZE);

    fail_unless(
            strcmp(
                bel_ast_flat_string(parse_term(line, value)),
                "TERM fx(p) ARG NV pfx() val(AKT1) ARG NV pfx(HGNC) val(AKT2) ARG NV pfx() val(AKT3) ARG NIL NIL ") == 0,
            "[parse_term] failed to parse multiple parameters (e.g. AKT1, HGNC:AKT2, AKT3)");
// vim: ft=c sw=4 ts=4 sts=4 expandtab
