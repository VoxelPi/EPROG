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
    polynomial->coefficients = malloc((degree + 1) * sizeof(double));
    assert(polynomial->coefficients != NULL);
    for (int i = 0; i <= degree; ++i) {
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
    assert(0 <= i_coefficient && i_coefficient <= polynomial->degree);
    return polynomial->coefficients[i_coefficient];
}

/**
 * Sets the i_th coefficient of the given polynomial to value.
 */ 
void setPolyCoefficient(Polynomial *polynomial, int i_coefficient, double value) {
    assert(0 <= i_coefficient && i_coefficient <= polynomial->degree);
    polynomial->coefficients[i_coefficient] = value;
}

Polynomial* scanPoly() {
    int degree = 0;
    do {
        printf("Degree n = ");
        scanf("%d", &degree);
    } while (degree < 0);
    
    Polynomial *polynomial = newPoly(degree);

    printf("Coefficients:\n");
    for (int i = degree; i >= 0; --i) {
        printf("  a_%d = ", i);
        scanf("%lf", &(polynomial->coefficients[i]));
    }

    return polynomial;
}

void printPoly(Polynomial *polynomial) {
    for (int i = polynomial->degree; i >= 1; --i) {
        printf("%f*x^%d + ", polynomial->coefficients[i], i);
    }
    printf("%f\n", polynomial->coefficients[0]);
}
