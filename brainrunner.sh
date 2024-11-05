#!/bin/bash
TARGET="$(readlink -f "$0")"
SCRIPT_DIR="$(dirname "$TARGET")"
make -C "${SCRIPT_DIR}" re > /dev/null
"$SCRIPT_DIR/brainrunner" "${1}"
mv temp.c "$SCRIPT_DIR/temp.c"
gcc -o "$SCRIPT_DIR/a.out" "$SCRIPT_DIR/temp.c"
$SCRIPT_DIR/a.out
rm -f $SCRIPT_DIR/temp.c
rm -f $SCRIPT_DIR/a.out
rm -f $SCRIPT_DIR/brainrunnerls
