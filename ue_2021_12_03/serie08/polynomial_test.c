/**
 * Aufgabe 8.2
 */

#include <assert.h>
#include <stdio.h>

#include "polynomial.h"

int main() {
    // Test polynomial library.

    // Create polynomial.
    Polynomial *polynomial = newPoly(3);
    assert(getPolyDegree(polynomial) == 3);

    // Check if coefficients are initialized to 0.
    assert(getPolyCoefficient(polynomial, 0) == 0);

    // Set 1 coefficient to 2.
    setPolyCoefficient(polynomial, 1, 2);
    assert(getPolyCoefficient(polynomial, 1) == 2);

    // Delete polynomial.
    polynomial = delPoly(polynomial);
    assert(polynomial == NULL);

    printf("All tests passed!\n");

    return 0;
}