/*
 * Aufgabe 4.8
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <stdio.h>

/**
 * Calculates the minimum, maximum and mean of x.
 * 
 * Results are stored in the arrays int_results and dbl_results in the following order.
 * int_results[0] = min
 * int_results[1] = max
 * double_results[0] = mean
 * 
 * The size of the array int_results must be at least 2.
 * The size of the array dbl_results must be at least 1.
 */
void minmaxmean(int x[], int n, int int_results[2], double dbl_results[1]) {
    assert(n >= 0); // Check that array size is >= 0.

    int min = x[0];
    int max = x[0];
    double mean = 0;

    // Loop over all values of x.
    int i = 0;
    int sum = 0;
    while (i < n) {
        // If x[i] is smaller than the current minimum, set min to x[i].
        if (x[i] < min) {
            min = x[i];
        }
        // If x[i] is larger than the current maximum, set max to x[i].
        if (x[i] > max) {
            max = x[i];
        }
        // Add x[i] to sum.
        sum += x[i];

        ++i;
    }

    // Calculate mean.
    mean = sum / (double)n;
    
    // Store results in arrays.
    dbl_results[0] = mean;
    int_results[0] = min;
    int_results[1] = max;
}

int main() {
    int x[3] = { 0, 0, 0 };
    int int_results[2] = { 0, 0 };
    double dbl_results[1] = { 0.0 };

    // Get user input for vector x.
    int i = 0;
    printf("Vector x:\n");
    while (i < 3) {
        printf(" x[%d] = ", i);
        scanf("%d", &(x[i]));
        ++i;
    }

    // Output calulated values.
    minmaxmean(x, 3, int_results, dbl_results);
    printf("Minimum of x: %d\n", int_results[0]);
    printf("Maximum of x: %d\n", int_results[1]);
    printf("Mean of x: %f\n", dbl_results[0]);

    return 0;
}

/*
* Tests:
* Test minmaxmean with different inputs.
* Test minmaxmean with negative inputs.
* Test minmaxmean with n!=3.
*/