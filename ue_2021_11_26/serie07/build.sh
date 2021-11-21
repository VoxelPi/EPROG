# Create binaries directory
mkdir -p bin/

gcc diff.c -o bin/diff -lm
gcc matrix.c -o bin/matrix
gcc newton.c -o bin/newton -lm
gcc matrix2.c -o bin/matrix2
