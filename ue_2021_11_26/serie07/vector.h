#ifndef INCLUDE_VECTOR__
#define INCLUDE_VECTOR__

/**
 * Vector structure from script page 177+
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

 // declaration of new data type Vector
typedef struct _Vector_ {
    int n; // Dimension
    double* entry; // Vector coefficients
} Vector;

// allocate and initialize new vector of length n
Vector* newVector(int n);

// free storage of allocated vector and return NULL
Vector* delVector(Vector* X);

// return length of a vector
int getVectorN(Vector* X);

// return coefficient Xi of vector X
double getVectorEntry(Vector* X, int i);

// assign new value to coefficient Xi of vector X
void setVectorEntry(Vector* X, int i, double Xi);

// some example functions...
Vector* inputVector();
double normVector(Vector* X);
double productVector(Vector* X, Vector* Y);

/**
 * Prints the given matrix.
 */
void printVector(Vector *X);

#endif