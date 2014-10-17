# variables
CC="gcc"
CFLAGS=-ggdb -Wall

# default rule
all: set term error_handling

# set ragel parser: generate ragel and compile
set:
	ragel -G2 -L set.rl -o set.c
	$(CC) $(CFLAGS) set.c -o set-parser

# term ragel parser: generate ragel and compile
term:
	ragel -G2 -L term.rl -o term.c
	$(CC) $(CFLAGS) term.c -o term-parser

error_handling:
	ragel -G2 -L error_handling.rl -o error_handling.c
	$(CC) $(CFLAGS) error_handling.c -o error_handling

# clean both source and compiled binaries
clean:
	rm -f set.c term.c set-parser term-parser
