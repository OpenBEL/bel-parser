#!/usr/bin/env bash
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"/../

# loop compile + state chart
inotifywait -m -e modify src tests | while read line; do
    RET=($line)
    FILE="${RET[@]:2}"

    case "$FILE" in
        *.rl|*.h|*.tc|bel-ast.c|bel-node-stack.c|bel-parser.c|bel-token.c)
            echo "Tripped build: $FILE"
            RESULT=$(make all 2>&1)
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
