/*
* Aufgabe 3.2
* Peter Smek, 27.10.2021
*/

#include <stdio.h>

// calculate n-th fibonacci number
int fibonacci(int n) {
    // exit conditions
    if (n == 0 || n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n = 0;

    // read index input
    printf("Index n = ");
    scanf("%d", &n);

    // output n-th fibonacci number
    printf("fibonacci(%d) = %d\n", n, fibonacci(n));

    return 1;
}