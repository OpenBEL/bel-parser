bin_PROGRAMS = belparser
belparser_SOURCES = bel-parser.c bel-parse-statement.c bel-parse-term.c bel-tokenize-term.c bel-token.c bel-parser.h bel-ast.c bel-node-stack.c bel-token.h bel-ast.h bel-node-stack.h bel-parser.h

bel-parse-statement.c: bel-parse-statement.rl
	ragel -G2 -L -C -o $@ $<
bel-parse-term.c: bel-parse-term.rl
	ragel -G2 -L -C -o $@ $<
bel-tokenize-term.c: bel-tokenize-term.rl
	ragel -G2 -L -C -o $@ $<
