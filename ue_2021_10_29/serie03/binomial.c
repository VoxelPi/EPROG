/*
* Aufgabe 3.6
* Peter Smek, 27.10.2021
*/

#include <stdio.h>

int binomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main() {
    int n = 0, k = 0;

    printf("1 <= k < n\n");
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);

    printf("binomial(%d, %d) = %d\n", n, k, binomial(n, k));

    return 0;
}