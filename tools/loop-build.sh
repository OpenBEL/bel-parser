#!/usr/bin/env bash
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"/../

if [ -z "$1" ]; then
    echo "usage: loop-build.sh" 1>&2
fi

# loop compile + state chart
inotifywait -m -e modify . | while read line; do
    RET=($line)
    FILE="${RET[@]:2}"

    case "$FILE" in
        *.rl|*.h|bel-ast.c|bel-node-stack.c|term-parser.c|term-test.c|Makefile)
            RESULT=$(make clean all 2>&1)
            if [ $? -ne 0 ]; then
                LAST=$(echo -e "$RESULT" | tail -n1)
                notify-send -t 2000 -u critical "Failed compilation\n\n$LAST"
                echo -e "$RESULT\n\n" 2>&1
            else
                notify-send -t 2000 -u normal "Successful compilation"
            fi
            ;;
        *)
            ;;
    esac
done
# vim: ts=4 sts=4 sw=4 expandtab
