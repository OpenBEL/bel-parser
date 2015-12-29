bin_PROGRAMS = belparser
belparser_SOURCES = bel-parser.c bel-parse-term.c bel-tokenize-term.c bel-token.c bel-parser.h bel-ast.c bel-node-stack.c bel-token.h bel-ast.h bel-node-stack.h bel-parser.h
belparser_CFLAGS = $(AM_CFLAGS)

lib_LTLIBRARIES = libbel.la
libbel_la_SOURCES = bel-parse-term.c bel-tokenize-term.c bel-token.c bel-parser.h bel-ast.c bel-node-stack.c bel-token.h bel-ast.h bel-node-stack.h bel-parser.h
libbel_la_LDFLAGS = -version-info 0:1:0

bel-parse-term.c: bel-parse-term.rl
	ragel -G2 -L -C -o $@ $<
bel-tokenize-term.c: bel-tokenize-term.rl
	ragel -G2 -L -C -o $@ $<
