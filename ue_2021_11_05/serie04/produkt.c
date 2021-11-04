/*
 * Aufgabe 4.1
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <stdio.h>

/**
 * Calculates the product of two natural numbers x and y.
 */
int produkt(int x, int y) {
    // Check that both inputs are natural numbers.
    assert(x >= 0);
    assert(y >= 0);

    // Swap the values of x and y if y is smaller than x.
    if (y > x) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    // Add the value of x y times to sum.
    int i = 0;
    int sum = 0;
    while (i < y) {
        sum += x;
        ++i;
    }
    
    return sum;
}

int main() {
    int x = 0, y = 0;

    // Get user input for variable x.
    do {
        printf("x = ");
        scanf("%d", &x);
    } while (x < 0);

    // Get user input for variable y.
    do {
        printf("y = ");
        scanf("%d", &y);
    } while (y < 0);
    
    // Print result.
    printf("%d * %d = %d\n", x, y, produkt(x, y));

    return 0;
}

/*
 * Tested by entering various differnent valid and invalid numbers 
 * and checking if the output product is correct.
 */