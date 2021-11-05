# Create binaries directory
mkdir -p bin/

gcc produkt.c -o bin/produkt
gcc geometricMean.c -o bin/geometricMean -lm
gcc goldenerSchnitt.c -o bin/goldenerSchnitt -lm
gcc scanfpositive.c -o bin/scanfpositive
gcc wurzelschranke.c -o bin/wurzelschranke
gcc produkte.c -o bin/produkte
gcc check.c -o bin/check
gcc minmaxmean.c -o bin/minmaxmean