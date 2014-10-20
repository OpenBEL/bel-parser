# variables
CC="gcc"
CFLAGS=-ggdb -Wall
RAGEL_OPTS=-G2 -L
TEST_LIBS=-lcheck

all:           clean test

ragel:
	       ragel $(RAGEL_OPTS) term.rl -o term.c

main:          ragel
	       $(CC) $(CFLAGS) term.c -o term-parser

test:          term.o tests.o
	       gcc -o run-tests term.o tests.o $(TEST_LIBS)
	       ./run-tests

tests.o:
	       checkmk *-test.c > tests.c
	       $(CC) $(CFLAGS) -c tests.c

term.o:        ragel
	       $(CC) $(CFLAGS) -c term.c

clean:
	       rm -f term.c tests.c term.o tests.o run-tests term-parser
