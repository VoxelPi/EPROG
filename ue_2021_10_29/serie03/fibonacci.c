/*
* Aufgabe 3.2
* Peter Smek, 27.10.2021
*/

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n = 0;

    printf("Index n = ");
    scanf("%d", &n);

    printf("fibonacci(%d) = %d\n", n, fibonacci(n));

    return 1;
}