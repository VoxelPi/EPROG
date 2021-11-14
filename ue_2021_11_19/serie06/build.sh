# Create binaries directory
mkdir -p bin/

gcc selectionsort.c -lm -o bin/selectionsort
gcc unique.c -lm -o bin/unique
gcc meanVariance.c -lm -o bin/meanVariance
gcc sampleVector.c -lm -o bin/sampleVector