/**
 * Aufgabe 8.5
 */

#include <assert.h>
#include <stdio.h>

#include "polynomial.h"

/**
 * Calculates and returns the product of the two polynomials A and B.
 */ 
Polynomial* prodPoly(Polynomial *A, Polynomial *B) {
    int n_A = getPolyDegree(A);
    int n_B = getPolyDegree(B);

    // Degree of the resulting polynomial is deg(A) + deg(B).
    Polynomial *result = newPoly(n_A + n_B);

    // Calculate the coefficients of the resulting polynomial.
    for (int i_A = 0; i_A <= n_A; ++i_A) {
        for (int i_B = 0; i_B <= n_B; ++i_B) {
            int i = i_A + i_B;
            setPolyCoefficient(result, i, getPolyCoefficient(result, i) + getPolyCoefficient(A, i_A) * getPolyCoefficient(B, i_B));
            // equal to: result->coefficients[i] += A->coefficients[i_A] * B->coefficients[i_B];
        }
    }

    return result;
}

int main() {
    // Get user input for polynomials A and B.
    Polynomial *A = scanPoly();
    Polynomial *B = scanPoly();

    // Calculate product.
    Polynomial *product = prodPoly(A, B);

    // Print result.
    printPoly(product);

    // Free memory.
    A = delPoly(A);
    B = delPoly(B);
    product = delPoly(product);

    return 0;
}