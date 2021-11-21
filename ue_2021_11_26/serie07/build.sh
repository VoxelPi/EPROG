# Create binaries directory
mkdir -p bin/

gcc diff.c -o bin/diff -lm
gcc matrix.c -o bin/matrix
