# Create binaries directory
mkdir -p bin/

gcc diff.c -o bin/diff -lm
gcc matrix1.c matrix.c -o bin/matrix1
gcc newton.c -o bin/newton -lm
gcc matrix2.c matrix.c -o bin/matrix2
