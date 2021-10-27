/*
* Aufgabe 3.4
* Peter Smek, 27.10.2021
*/


#include <stdio.h>

double folgenglied(int n) {
    return (n % 2 ? -1.0 : 1.0) / (n + 2);
}

int main() {

    int n = 0;
    printf("n = ");
    scanf("%d", &n);

    printf("a_n = %f\n", folgenglied(n));

    return 0;
}
