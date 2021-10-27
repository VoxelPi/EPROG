/*
* Aufgabe 3.8
* Peter Smek, 27.10.2021
*/

#include <stdio.h>

double P(int n) {
    double sum = 4 * (1 - 2 * (n%2)) / (double)(2 * n + 1);

    if (n > 0) {
        sum += P(n - 1);
    }

    return sum;
}

int main() {

    int n = 0;
    printf("n = ");
    scanf("%d", &n);

    printf("P(n) = %f\n", P(n));

    return 0;
}