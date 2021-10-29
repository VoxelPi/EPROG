/*
 * Aufgabe 4.2
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

/**
 * Calculate the geometric mean of the given vector x with size n.
 */ 
double geometricMean(double x[], int n) {
    // Check that n is greater than 0.
    assert(n > 0); 

    // Calculate the product of all values in the array.
    double product = 1.0;
    int i = 0;
    while (i < n) {
        product *= x[i];
        ++i;
    }

    // Calculate the 1/n th root of the product.
    return pow(product, 1.0 / n);    
}

int main() {
    double x[3] = { 0.0, 0.0, 0.0 };

    // Get user input for all 3 values in x.
    int i = 0;
    while (i < 3) {
        do {
            printf("x[%d] = ", i);
            scanf("%lf", &(x[i]));
        } while (x[i] < 0);
        ++i;
    }
    
    // Output result.
    printf("Geometric mean of input vector is %f\n", geometricMean(x, 3));

    return 0;
}

/*
 * Tests:
 * Check that n > 0.
 * Check that user input is always >= 0.
 * Check if the calculated geometric mean is correct for different values of n. 
 */ 