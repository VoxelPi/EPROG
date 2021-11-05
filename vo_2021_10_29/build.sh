# Create binaries directory
mkdir -p bin/

gcc sqrt.c -o bin/sqrt -lm
gcc loop.c -o bin/loop
gcc bisection.c -o bin/bisection
gcc euclid.c -o bin/euclid
gcc assert.c -o bin/assert
gcc array.c -o bin/array