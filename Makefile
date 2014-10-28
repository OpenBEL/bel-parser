# variables
CC="gcc"
CFLAGS=-ggdb -Wall -Werror -fPIC
RAGEL_OPTS=-G2 -L
TEST_LIBS=-lcheck

all:                    clean lib main test

lib:                    parse-term.o tokenize-term.o
	                $(CC) -shared bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o -o libBEL.so

main:                   parse-term.o tokenize-term.o
	                $(CC) $(CFLAGS) bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o bel-parser.c -o bel-parser

test:                   parse-term.o tokenize-term.o tests.o
	                $(CC) $(CFLAGS) -o tests bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o tests.o $(TEST_LIBS)
	                CK_VERBOSITY=verbose ./tests

parse-term.o:           bel-ast.o bel-node-stack.o ragel
	                $(CC) $(CFLAGS) -c parse-term.c

tokenize-term.o:        bel-token.o ragel
	                $(CC) $(CFLAGS) -c tokenize-term.c

bel-node-stack.o:       bel-ast.o
	                $(CC) $(CFLAGS) -c bel-node-stack.c

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
	                rm -f parse-term.c tests.c bel-ast.o bel-node-stack.o bel-token.o parse-term.o tokenize-term.o tests.o libBEL.so tests bel-parser

check-ragel:
	                ragel -v
