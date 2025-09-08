#!/bin/bash
set -e
set -o pipefail

OS="$(uname -s)"
EXT=""
if [[ "$OS" == "MINGW"* || "$OS" == "CYGWIN"* || "$OS" == "MSYS"* ]]; then
    EXT=".exe"
fi

for f in a b generator; do
  [[ $f.cpp -nt $f$EXT ]] && g++ -std=c++17 -O2 $f.cpp -o $f$EXT
done

for ((i = 1; ; i++)); do
    echo "-> Test #$i"
    ./generator$EXT "$i" > input.txt
    ./a$EXT < input.txt > out_a.txt
    ./b$EXT < input.txt > out_b.txt

    if ! diff -w out_a.txt out_b.txt > /dev/null; then
        echo "** Mismatch at test $i"
        echo "Input:"
        cat input.txt
        echo "Output A:"
        cat out_a.txt
        echo "Output B:"
        cat out_b.txt
        break
    fi
done