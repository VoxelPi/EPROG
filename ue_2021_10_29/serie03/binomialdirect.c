/*
* Aufgabe 3.7
* Peter Smek, 27.10.2021
*/

#include <stdio.h>

// The function factorial computes the factorial
// of a nonnegative integer n recursively
// EPROG Folien S.56
int factorial(int n) {
    if (n <= -1) {
        // factorial not defined for n <= -1
        return -1;
    }
    else {
        if (n > 1) {
            // recursive step n! = n*(n-1)!
            return n*factorial(n-1);
        }
        else {
            // stopping criterion 0! = 1 = 1!
            return 1;
        }
    }
}

int binomialdirect(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n = 0, k = 0;

    printf("1 <= k < n\n");
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);

    printf("binomial(%d, %d) = %d\n", n, k, binomialdirect(n, k));

    return 0;
}