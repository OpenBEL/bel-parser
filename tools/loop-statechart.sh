#!/usr/bin/env bash

# must have RAGEL_OPTS set
# if [ -z "$RAGEL_OPTS" ]; then
#     echo "RAGEL_OPTS not set.  Not sure how to build." 1>&2
#     exit 1
# fi

if [ -z "$1" ]; then
    echo "usage: loop-statechart.sh [Ragel .rl FILE]" 1>&2
fi
RAGEL_FILE="$1"

# loop compile + state chart
inotifywait -r -m -e modify . | while read line; do
    RET=($line)
    FILE="${RET[@]:2}"

    if [ "$FILE" == $(basename $RAGEL_FILE) ]; then
        NAME="${FILE%.rl}"
        ragel -p -V "$RAGEL_FILE" | dot -Tpng -o "$NAME.png"
        if [ "$?" == 0 ]; then
            PID=$(pidof feh)
            if [ -n "$PID" ]; then
                kill -9 $PID > /dev/null 2>&1
            fi
            feh --no-screen-clip "$NAME.png" &
        fi
    fi
done

