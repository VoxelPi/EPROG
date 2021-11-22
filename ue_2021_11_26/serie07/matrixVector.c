/*
 * Aufgabe 7.5
 * Peter Smek, 21.11.2021
 */

#include <assert.h>
#include <stdio.h>

#include "matrix.h"
#include "vector.h"

/**
 * Calculates the matrix-vector-product. 
 */
Vector* matrixVector(Matrix *A, Vector *x) {
    int m = getMatrixM(A);
    int n = getMatrixN(A);
    assert(getVectorN(x) == n);

    Vector *y = newVector(getMatrixM(A));

    // Iterate over all rows of the matrix.
    for (int i = 0; i < m; ++i) {
        // Calculate y[i].
        double y_i = 0.0;
        // Iterate over all columns of the matrix.
        for (int j = 0; j < n; ++j) {
            y_i += getMatrixEntry(A, i, j) * getVectorEntry(x, j);
        }
        setVectorEntry(y, i, y_i);
    }

    return y;
}

int main() {

    // Create and initialize matrix A and vector x
    Matrix *A = newMatrix(2, 3);
    Vector *x = newVector(3);

    setMatrixEntry(A, 0, 0, 0.0);
    setMatrixEntry(A, 0, 1, 1.0);
    setMatrixEntry(A, 0, 2, 2.0);
    setMatrixEntry(A, 1, 0, 3.0);
    setMatrixEntry(A, 1, 1, 4.0);
    setMatrixEntry(A, 1, 2, 5.0);

    setVectorEntry(x, 0, 1.0);
    setVectorEntry(x, 1, 2.0);
    setVectorEntry(x, 2, 3.0);

    // Output matrix A.
    printf("Matrix A:\n");
    printMatrix(A);

    // Output vector x.
    printf("Vector x:\n");
    printVector(x);

    // Calculate y = A*x.
    Vector *y = matrixVector(A, x);

    // Output vector y.
    printf("Vector y = A*x: \n");
    printVector(y);

    // Delete matrix and vectors.
    delMatrix(A);
    delVector(x);
    delVector(y);

    return 0;
}