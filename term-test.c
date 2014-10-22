#include <stdio.h>
#include <string.h>
#include "bel-parser.h"

#define LINE_CHAR_LEN 1024 * 32 // 32 kilobytes

#test supports_empty_term
    char line[LINE_CHAR_LEN] = "";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM NULL NULL ") == 0,
            "[parse_term] failed to parse empty term");

#test supports_parameter_identifiers
    char line[LINE_CHAR_LEN] = "r(AFFX:100009_r_at)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(r) ARG NV pfx(AFFX) val(100009_r_at) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter identifier (e.g. 100009_r_at)");

#test supports_parameter_strings
    char line[LINE_CHAR_LEN] = "bp(GOBP:\"apoptotic process\")";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(bp) ARG NV pfx(GOBP) val(\"apoptotic process\") ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter string (e.g. \"apoptotic process\")");

#test supports_parameters_without_namespace
    char line[LINE_CHAR_LEN] = "p(AKT1)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(p) ARG NV pfx((null)) val(AKT1) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter without namespace (e.g. AKT1)");

#test supports_parameters_with_namespace
    char line[LINE_CHAR_LEN] = "p(HGNC:AKT1)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(line)),
                "TERM fx(p) ARG NV pfx(HGNC) val(AKT1) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse parameter with namespace (e.g. HGNC:AKT1)");

#test supports_parameters_single_char
    char term1[LINE_CHAR_LEN] = "r(MGI:a)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term1)),
                "TERM fx(r) ARG NV pfx(MGI) val(a) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse single character parameter (e.g. MGI:a)");

    char term2[LINE_CHAR_LEN] = "r(a)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term2)),
                "TERM fx(r) ARG NV pfx((null)) val(a) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse single character parameter (e.g. a)");

    char term3[LINE_CHAR_LEN] = "pmod(P)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term3)),
                "TERM fx(pmod) ARG NV pfx((null)) val(P) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse single character parameter (e.g. P)");

#test supports_long_parameters
    char term[LINE_CHAR_LEN] = "a(SCHEM:\"3,5,9-Trioxo-4-phosphaheptacosan-1-aminium, 7-(acetyloxy)-4-hydroxy-N,N,N-trimethyl-, hydroxide, inner salt, 4-oxide, (R)-\")";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term)),
                "TERM fx(a) ARG NV pfx(SCHEM) val(\"3,5,9-Trioxo-4-phosphaheptacosan-1-aminium, 7-(acetyloxy)-4-hydroxy-N,N,N-trimethyl-, hydroxide, inner salt, 4-oxide, (R)-\") ARG NULL NULL ") == 0,
            "[parse_term] failed to parse long parameter (e.g. SCHEM:\"3,5,9-Trioxo-4-phosphaheptacosan-1-aminium, 7-(acetyloxy)-4-hydroxy-N,N,N-trimethyl-, hydroxide, inner salt, 4-oxide, (R)-\"");


#test supports_multiple_parameters
    char term1[LINE_CHAR_LEN] = "p(AKT1, HGNC:AKT2, AKT3)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term1)),
                "TERM fx(p) ARG NV pfx((null)) val(AKT1) ARG NV pfx(HGNC) val(AKT2) ARG NV pfx((null)) val(AKT3) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse multiple parameters (e.g. AKT1, HGNC:AKT2, AKT3)");

    char term2[LINE_CHAR_LEN] = "bp(GOBP:\"apoptotic process\", AFFX:\"AFFX-18SRNAMur/X00686_5_at\")";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term2)),
                "TERM fx(bp) ARG NV pfx(GOBP) val(\"apoptotic process\") ARG NV pfx(AFFX) val(\"AFFX-18SRNAMur/X00686_5_at\") ARG NULL NULL ") == 0,
            "[parse_term] failed to parse multiple parameters (e.g. \"apoptotic process\", \"AFFX-18SRNAMur/X00686_5_at\")");

#test supports_nested_terms
    char term1[LINE_CHAR_LEN] = "cat(p(HGNC:AKT1))";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term1)),
                "TERM fx(cat) ARG TERM fx(p) ARG NV pfx(HGNC) val(AKT1) ARG NULL NULL ARG NULL NULL ") == 0,
            "[parse_term] failed to parse nested terms (e.g. cat(p(HGNC:AKT1)) )");

    char term2[LINE_CHAR_LEN] = "p(HGNC:AKT1, pmod(P,S,317))";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term2)),
                "TERM fx(p) ARG NV pfx(HGNC) val(AKT1) ARG TERM fx(pmod) ARG NV pfx((null)) val(P) ARG NV pfx((null)) val(S) ARG NV pfx((null)) val(317) ARG NULL NULL ARG NULL NULL ") == 0,
            "[parse_term] failed to parse nested terms (e.g. p(HGNC:AKT1, pmod(P,S,317)) )");

    char term3[LINE_CHAR_LEN] = "complex(p(HGNC:AKT1), p(HGNC:AKT2))";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term3)),
                "TERM fx(complex) ARG TERM fx(p) ARG NV pfx(HGNC) val(AKT1) ARG NULL NULL ARG TERM fx(p) ARG NV pfx(HGNC) val(AKT2) ARG NULL NULL ARG NULL NULL ") == 0,
            "[parse_term] failed to parse nested terms (e.g. p(HGNC:AKT1, pmod(P,S,317)) )");

    char term4[LINE_CHAR_LEN] = "tloc(p(MGI:Slc2a4), GOCCID:0005737, GOCCID:0005886)";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term4)),
                "TERM fx(tloc) ARG TERM fx(p) ARG NV pfx(MGI) val(Slc2a4) ARG NULL NULL ARG NV pfx(GOCCID) val(0005737) ARG NV pfx(GOCCID) val(0005886) ARG NULL NULL ") == 0,
            "[parse_term] failed to parse nested terms (e.g. p(HGNC:AKT1, pmod(P,S,317)) )");

#test supports_long_terms
    char term1[LINE_CHAR_LEN] = "rxn(reactants(a(CHEBI:testosterone),p(EGID:1666),p(EGID:1666),p(EGID:1666),a(SCHEM:Oxygen),a(SCHEM:Oxygen),a(SCHEM:Oxygen),a(SCHEM:\"H+\"),a(SCHEM:\"H+\"),a(SCHEM:\"H+\")),products(a(SCHEM:\"Estradiol-17beta\"),a(SCHEM:\"NADP+\"),a(CHEBI:formate),a(SCHEM:H2O),a(SCHEM:H2O),a(SCHEM:H2O),a(SCHEM:H2O)))";
    fail_unless(
            strcmp(
                bel_ast_as_string(parse_term(term1)),
                "TERM fx(rxn) ARG TERM fx(reactants) ARG TERM fx(a) ARG NV pfx(CHEBI) val(testosterone) ARG NULL NULL ARG TERM fx(p) ARG NV pfx(EGID) val(1666) ARG NULL NULL ARG TERM fx(p) ARG NV pfx(EGID) val(1666) ARG NULL NULL ARG TERM fx(p) ARG NV pfx(EGID) val(1666) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(Oxygen) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(Oxygen) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(Oxygen) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(\"H+\") ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(\"H+\") ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(\"H+\") ARG NULL NULL ARG NULL NULL ARG TERM fx(products) ARG TERM fx(a) ARG NV pfx(SCHEM) val(\"Estradiol-17beta\") ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(\"NADP+\") ARG NULL NULL ARG TERM fx(a) ARG NV pfx(CHEBI) val(formate) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(H2O) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(H2O) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(H2O) ARG NULL NULL ARG TERM fx(a) ARG NV pfx(SCHEM) val(H2O) ARG NULL NULL ARG NULL NULL ARG NULL NULL ") == 0,
            "[parse_term] failed to parse long term (e.g. rxn(reactants(a(CHEBI:testosterone),p(EGID:1666),p(EGID:1666),p(EGID:1666),a(SCHEM:Oxygen),a(SCHEM:Oxygen),a(SCHEM:Oxygen),a(SCHEM:\"H+\"),a(SCHEM:\"H+\"),a(SCHEM:\"H+\")),products(a(SCHEM:\"Estradiol-17beta\"),a(SCHEM:\"NADP+\"),a(CHEBI:formate),a(SCHEM:H2O),a(SCHEM:H2O),a(SCHEM:H2O),a(SCHEM:H2O))) )");

// vim: ft=c sw=4 ts=4 sts=4 expandtab
