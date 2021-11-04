/*
 * Aufgabe 4.7
 * Peter Smek, 29.10.2021
 */

#include <assert.h>
#include <stdio.h>

/**
 * Returns 1 if the sequence x contains the sequence y otherwise 0.
 */
int check(int x[], int x_n, int y[], int y_n) {
    // Assert that 0 <= y_n <= x_n
    assert(y_n >= 0);
    assert(x_n >= y_n);

    // Loop over all possible starting positions in x.
    int i = 0;
    while (i <= x_n - y_n) {
        // Assume sequences are equal.
        int equal = 1;

        // Loop over all elements of y.
        int j = 0;
        while (j < y_n) {
            // If x[i + j] is not y[j] set equal to 0 and break out of the inner loop.
            if (x[i + j] != y[j]) {
                equal = 0;
                break;
            }
            ++j;
        }

        // If equal is still true, the sequence x contains the sequence y and 1 is returned.
        if (equal) {
            return 1;
        }
        ++i;
    }

    // If no match is found return 0.
    return 0;
}

int main() {

    int x[6] = { 0, 0, 0, 0, 0, 0 };
    int y[3] = { 0, 0, 0 };
    int i = 0;

    // Get user input for the sequence x.
    i = 0;
    printf("Sequence x:\n");
    while (i < 6) {
        printf("  x[%d] = ", i);
        scanf("%d", &(x[i]));
        ++i;
    }

    // Get user input for the sequence y.
    i = 0;
    printf("Sequence y:\n");
    while (i < 3) {
        printf("  y[%d] = ", i);
        scanf("%d", &(y[i]));
        ++i;
    }
    
    // Check if the sequence x contains the sequence y.
    if (check(x, 6, y, 3)) {
        printf("The sequence x contains the sequence y.\n");
    } else {
        printf("The sequence x doesn't contain the sequence y.\n");
    }

    return 0;
}

/*
* Tests:
* Test {1, 2, 3, 3, 2, 1} and {3, 3, 2}.
* Test other examples that should be true.
* Test other examples that should be false.
*/