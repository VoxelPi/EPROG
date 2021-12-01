#include "cdouble.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a new complex number equals to a + i*b.
 */ 
cDouble* newCDouble(double a, double b) {

    // Allocate memory for the complex number.
    cDouble *z = malloc(sizeof(cDouble));
    assert(z != NULL);

    // Set real and imaginary part of z.
    z->a = a;
    z->b = b;

    // Return created complex number.
    return z;
}

/**
 * Deletes the given complex number.
 */ 
cDouble* delCDouble(cDouble *z) {
    z->a = 0;
    z->b = 0;

    // Free memory.
    free(z);

    // Return NULL.
    return NULL;
}

/**
 * Sets the real part of the given complex number z to a.
 */ 
void setCDoubleReal(cDouble* z, double a) {
    z->a = a;
}

/**
 * Returns the real part of the given complex number z.
 */ 
double getCDoubleReal(cDouble* z) {
    return z->a;
}

/**
 * Sets the imaginary part of the given complex number z to i * b.
 */ 
void setCDoubleImag(cDouble* z, double b) {
    z->b = b;
}

/**
 * Returns the imaginary part of the given complex number z.
 */ 
double getCDoubleImag(cDouble* z) {
    return z->b;
}

/**
 * Reads a complex number from stdin.
 */ 
cDouble* scanCDouble() {
    double a = 0.0, b = 0.0;
    printf("real(z) = ");
    scanf("%lf", &a);
    printf("imag(z) = ");
    scanf("%lf", &b);

    return newCDouble(a, b);
}

/**
 * Prints the complex number z to stdout.
 */ 
void printCDouble(cDouble *z) {
    printf("%f + i*%f\n", z->a, z->b);
}