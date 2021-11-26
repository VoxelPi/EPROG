#include "matrix.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Creates a new mxn Matrix.
 */ 
Matrix* newMatrix(int m, int n) {
    assert(m >= 0);
    assert(n >= 0);

    // Allocate memory for one matrix object.
    Matrix *matrix = malloc(sizeof(Matrix));
    assert(matrix != NULL);

    // Set matrix properties.
    matrix->m = m;
    matrix->n = n;

    // Allocate memory for matrix data.
    matrix->values = malloc(m * n * sizeof(double));
    assert(matrix->values != NULL);
    for (int i = 0; i < m * n; ++i) {
        matrix->values[i] = 0.0;
    }

    return matrix;
}

/**
 * Deletes the given matrix.
 */ 
Matrix* delMatrix(Matrix *A) {
    free(A->values);
    A->values = NULL;
    free(A);
    return NULL;
}

/**
 * Prints the given matrix.
 */
void printMatrix(Matrix *A) {
    for (int i = 0; i < A->m; ++i) {
        for (int j = 0; j < A->n; ++j) {
            printf("%15f  ", A->values[i + j * A->m]);
        }
        printf("\n");
    }
}

/**
 * Returns the number of rows.
 */ 
int getMatrixM(Matrix *A) {
    return A->m;
}

/**
 * Returns the number of columns.
 */
int getMatrixN(Matrix *A) {
    return A->n;
}

/**
 * Returns the entry A_jk of the given matrix.
 */ 
double getMatrixEntry(Matrix *A, int j, int k) {
    assert(0 <= j && j < A->m);
    assert(0 <= k && k < A->n);

    return A->values[j + k * A->m];
}

/**
 * Sets the entry A_jk of the given matrix to x.
 */ 
void setMatrixEntry(Matrix *A, int j, int k, double x) {
    assert(0 <= j && j < A->m);
    assert(0 <= k && k < A->n);

    A->values[j + k * A->m] = x;
}

/**
 * Creates a shallow copy of the given Matrix.
 */
Matrix* shallowCopy(Matrix* A) {
    Matrix *copy = malloc(sizeof(Matrix));
    assert(copy != NULL);

    copy->m = A->m;
    copy->n = A->n;
    copy->values = A->values;
    return copy;
} 

/**
 * Creates a deep copy of the given matrix.
 */
Matrix* deepCopy(Matrix* A) {
    Matrix *copy = malloc(sizeof(Matrix));
    assert(copy != NULL);

    copy->m = A->m;
    copy->n = A->n;

    // Copy matrix data.
    copy->values = malloc(A->m * A->n * sizeof(double));
    assert(copy->values != NULL);
    for (int i = 0; i < A->m * A->n; ++i) {
        copy->values[i] = A->values[i];
    }

    return copy;
}