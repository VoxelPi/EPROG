#include "polynomial.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a new polynomial.
 */ 
Polynomial* newPoly(int degree) {
    assert(degree >= 0);

    // Allocate memory for the polynomial object.
    Polynomial *polynomial = malloc(sizeof(Polynomial));
    assert(polynomial != NULL);

    // Set degree of polynomial.
    polynomial->degree = degree;

    // Create coefficient array of the polynomial, with all entries set to 0.
    polynomial->coefficients = malloc(degree * sizeof(double));
    assert(polynomial->coefficients != NULL);
    for (int i = 0; i < degree; ++i) {
        polynomial->coefficients[i] = 0.0;
    }

    // Return created polynomial.
    return polynomial;
}

/**
 * Deletes the given polynomial.
 */ 
Polynomial* delPoly(Polynomial *polynomial) {
    if (polynomial == NULL) {
        return NULL;
    }

    // Free coefficients array.
    free(polynomial->coefficients);
    polynomial->coefficients = NULL;

    // Free polynomial instance.
    free(polynomial);

    return NULL;
}

/**
 * Returns the degree of the given polynomial.
 */
int getPolyDegree(Polynomial *polynomial) {
    return polynomial->degree;
}

/**
 * Returns the i_th coefficient of the given polynomial.
 */ 
double getPolyCoefficient(Polynomial *polynomial, int i_coefficient) {
    return polynomial->coefficients[i_coefficient];
}

/**
 * Sets the i_th coefficient of the given polynomial to value.
 */ 
void setPolyCoefficient(Polynomial *polynomial, int i_coefficient, double value) {
    polynomial->coefficients[i_coefficient] = value;
}
