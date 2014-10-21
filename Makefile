# variables
CC="gcc"
CFLAGS=-ggdb -Wall
RAGEL_OPTS=-G2 -L
TEST_LIBS=-lcheck

all:           clean main test

main:          bel-parser.o
	       $(CC) $(CFLAGS) bel-parser.o term-parser.c -o term-parser

test:          bel-parser.o tests.o
	       $(CC) $(CFLAGS) -o run-tests bel-parser.o tests.o $(TEST_LIBS)
	       CK_VERBOSITY=verbose ./run-tests

bel-parser.o:  ragel
	       $(CC) $(CFLAGS) -c bel-parser.c

ragel:
	       ragel $(RAGEL_OPTS) bel-parser.rl -o bel-parser.c

tests.o:
	       checkmk *-test.c > tests.c
	       $(CC) $(CFLAGS) -c tests.c

clean:
	       rm -f bel-parser.c tests.c bel-parser.o tests.o run-tests term-parser

check-ragel:
	       ragel -v
