#include <stdio.h>
#include <string.h>
#include "bel-parser.h"

#test supports_parameter_identifiers
    char line[BUFSIZE] = "r(AFFX:100009_r_at)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(r) ARG NV pfx(AFFX) val(100009_r_at) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter identifier (e.g. 100009_r_at)");

#test supports_parameter_strings
    char line[BUFSIZE] = "bp(GOBP:\"apoptotic process\")";
    fprintf(stdout, "actual: %s\n", bel_ast_as_string(parse_term(line)));
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(bp) ARG NV pfx(GOBP) val(\"apoptotic process\") ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter string (e.g. \"apoptotic process\")");

#test supports_parameters_without_namespace
    char line[BUFSIZE] = "p(AKT1)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(p) ARG NV pfx() val(AKT1) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter without namespace (e.g. AKT1)");

#test supports_parameters_with_namespace
    char line[BUFSIZE] = "p(HGNC:AKT1)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(p) ARG NV pfx(HGNC) val(AKT1) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter with namespace (e.g. HGNC:AKT1)");

#test supports_parameters_single_char
    char term1[BUFSIZE] = "r(MGI:a)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term1)),
                "TERM fx(r) ARG NV pfx(MGI) val(a) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse single character parameter (e.g. MGI:a)");

    char term2[BUFSIZE] = "r(a)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term2)),
                "TERM fx(r) ARG NV pfx() val(a) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse single character parameter (e.g. a)");

    char term3[BUFSIZE] = "pmod(P)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term3)),
                "TERM fx(pmod) ARG NV pfx() val(P) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse single character parameter (e.g. P)");

#test supports_long_parameters
    char term[BUFSIZE] = "a(SCHEM:\"3,5,9-Trioxo-4-phosphaheptacosan-1-aminium, 7-(acetyloxy)-4-hydroxy-N,N,N-trimethyl-, hydroxide, inner salt, 4-oxide, (R)-\")";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term)),
                "TERM fx(a) ARG NV pfx(SCHEM) val(\"3,5,9-Trioxo-4-phosphaheptacosan-1-aminium, 7-(acetyloxy)-4-hydroxy-N,N,N-trimethyl-, hydroxide, inner salt, 4-oxide, (R)-\") ARG NULL NULL ") == 0,
            "[parse_term] failed to parse long parameter (e.g. SCHEM:\"3,5,9-Trioxo-4-phosphaheptacosan-1-aminium, 7-(acetyloxy)-4-hydroxy-N,N,N-trimethyl-, hydroxide, inner salt, 4-oxide, (R)-\"");


#test supports_multiple_parameters
    char term1[BUFSIZE] = "p(AKT1, HGNC:AKT2, AKT3)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term1)),
                "TERM fx(p) ARG NV pfx() val(AKT1) ARG NV pfx(HGNC) val(AKT2) ARG NV pfx() val(AKT3) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse multiple parameters (e.g. AKT1, HGNC:AKT2, AKT3)");

    char term2[BUFSIZE] = "bp(GOBP:\"apoptotic process\", AFFX:\"AFFX-18SRNAMur/X00686_5_at\")";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term2)),
                "TERM fx(bp) ARG NV pfx(GOBP) val(\"apoptotic process\") ARG NV pfx(AFFX) val(\"AFFX-18SRNAMur/X00686_5_at\") ARG NULL NULL ") == 0,
            "[parse_term] failed to parse multiple parameters (e.g. \"apoptotic process\", \"AFFX-18SRNAMur/X00686_5_at\")");
// vim: ft=c sw=4 ts=4 sts=4 expandtab
