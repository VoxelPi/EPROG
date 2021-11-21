/*
 * Aufgabe 7.4
 * Peter Smek, 21.11.2021
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Matrix_ {
    int m;
    int n;
    double *values;
} Matrix;

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

int main() {
    // Get user input for matrix size.
    int m = 0, n = 0;
    do {
        printf("m = ");
        scanf("%d", &m);
    } while (m <= 0);
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n <= 0);

    // Create matrix.
    Matrix *matrix = newMatrix(m, n);
    Matrix *shallowCopyMatrix = shallowCopy(matrix);
    Matrix *deepCopyMatrix = deepCopy(matrix);

    // Tests.
    assert(getMatrixM(matrix) == m);
    assert(getMatrixN(matrix) == n);
    setMatrixEntry(matrix, 0, 0, -2352.2);
    assert(getMatrixEntry(matrix, 0, 0) == -2352.2);
    assert(getMatrixEntry(shallowCopyMatrix, 0, 0) == -2352.2);
    assert(getMatrixEntry(deepCopyMatrix, 0, 0) == 0);

    printf("Matrix:\n");
    printMatrix(matrix);

    printf("\nShallow copy of Matrix:\n");
    printMatrix(shallowCopyMatrix);

    printf("\nDeep copy of Matrix:\n");
    printMatrix(deepCopyMatrix);

    // Delete matrix.
    delMatrix(matrix);
    delMatrix(deepCopyMatrix);

    return 0;
}