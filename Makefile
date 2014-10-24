# variables
CC="gcc"
CFLAGS=-ggdb -Wall -Werror
RAGEL_OPTS=-G2 -L
TEST_LIBS=-lcheck

all:                    clean main test

main:                   parse-term.o tokenize-term.o
	                $(CC) $(CFLAGS) bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o bel-parser.c -o bel-parser

test:                   parse-term.o tokenize-term.o tests.o
	                $(CC) $(CFLAGS) -o tests bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o tests.o $(TEST_LIBS)
	                CK_VERBOSITY=verbose ./tests

parse-term.o:           bel-ast.o bel-node-stack.o ragel
	                $(CC) $(CFLAGS) bel-ast.o bel-node-stack.o -c parse-term.c

tokenize-term.o:        bel-token.o ragel
	                $(CC) $(CFLAGS) bel-token.o -c tokenize-term.c

bel-node-stack.o:       bel-ast.o
	                $(CC) $(CFLAGS) bel-ast.o -c bel-node-stack.c

bel-ast.o:
	                $(CC) $(CFLAGS) -c bel-ast.c

bel-token.o:
	                $(CC) $(CFLAGS) -c bel-token.c

ragel:
	                ragel $(RAGEL_OPTS) parse-term.rl -o parse-term.c
	                ragel $(RAGEL_OPTS) tokenize-term.rl -o tokenize-term.c

tests.o:
	                checkmk *-test.c > tests.c
	                $(CC) $(CFLAGS) -c tests.c

clean:
	                rm -f parse-term.c tests.c bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o tests.o tests bel-parser

check-ragel:
	                ragel -v
