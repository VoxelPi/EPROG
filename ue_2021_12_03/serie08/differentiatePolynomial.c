/**
 * Aufgabe 8.6
 */

#include <assert.h>
#include <stdio.h>

#include "polynomial.h"

/**
 * Calculates the k-th derivative of the given polynomial
 */ 
Polynomial* differentiatePolynomial(Polynomial *polynomial, int k) {
    int p_n = getPolyDegree(polynomial);

    // Degree of derivative is deg(poly) - k.
    int d_n = p_n - k;

    // If deg(poly) - k < 0 return 0.
    if (d_n < 0) {
        return newPoly(0);
    }

    // Create derivative polynomial.
    Polynomial *derivative = newPoly(d_n);

    // Set coefficients of derivative.
    for (int i_d = 0; i_d <= d_n; ++i_d) {
        int i_p = i_d + k; // corresponding index in the original polynomial.

        // Calculate factor. a*x^n -> (n) * a*x^(n-1) -> (n*(n-1)) * a*x^(n-2) -> (n*(n-1)*(n-2)) * a*x^(n-3)
        int b = 1;
        for (int j = 0; j < k; ++j) {
            b *= (i_p - j);
        }

        // Set coefficient.
        setPolyCoefficient(derivative, i_d, b * getPolyCoefficient(polynomial, i_p));
    }

    return derivative;
}

int main() {
    int k = 0;

    // Get user input for the polynomial.
    Polynomial *polynomial = scanPoly();

    // Get user input for k.
    do {
        printf("k = ");
        scanf("%d", &k);
    } while (k <= 0);

    // Calculate derivative.
    Polynomial *derivative = differentiatePolynomial(polynomial, k);

    // Print result.
    printPoly(derivative);

    // Free memory.
    polynomial = delPoly(polynomial);
    derivative = delPoly(derivative);

    return 0;
}