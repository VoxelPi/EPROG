# Create binaries directory
mkdir -p bin/

gcc pnorm.c -lm -o bin/pnorm
gcc zeilensummennorm.c -o bin/zeilensummennorm
gcc binominal.c -o bin/binominal
gcc fibonacci.c -o bin/fibonacci
gcc maxabs.c -lm -o bin/maxabs
gcc printUnique.c -o bin/printUnique
gcc issymmetric.c -o bin/issymmetric
gcc zeitmessung.c -o bin/zeitmessung