#!/usr/bin/env bash
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"/../

if [ -z "$1" ]; then
    echo "usage: loop-build.sh" 1>&2
fi
RAGEL_FILE="$1"

# loop compile + state chart
inotifywait -r -m -e modify . | while read line; do
    RET=($line)
    FILE="${RET[@]:2}"

    case "$FILE" in
        *.rl)
            make clean all
            ;;
        *)
            ;;
    esac
done

