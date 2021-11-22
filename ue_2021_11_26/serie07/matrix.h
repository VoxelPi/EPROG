#ifndef INCLUDE_MATRIX__
#define INCLUDE_MATRIX__

/**
 * Matrix library.
 */ 

typedef struct _Matrix_ {
    int m;
    int n;
    double *values;
} Matrix;

/**
 * Creates a new mxn Matrix.
 */ 
Matrix* newMatrix(int m, int n);

/**
 * Deletes the given matrix.
 */ 
Matrix* delMatrix(Matrix *A);

/**
 * Prints the given matrix.
 */
void printMatrix(Matrix *A);

/**
 * Returns the number of rows.
 */ 
int getMatrixM(Matrix *A);

/**
 * Returns the number of columns.
 */
int getMatrixN(Matrix *A);

/**
 * Returns the entry A_jk of the given matrix.
 */ 
double getMatrixEntry(Matrix *A, int j, int k);

/**
 * Sets the entry A_jk of the given matrix to x.
 */ 
void setMatrixEntry(Matrix *A, int j, int k, double x);

/**
 * Creates a shallow copy of the given Matrix.
 */
Matrix* shallowCopy(Matrix* A);

/**
 * Creates a deep copy of the given matrix.
 */
Matrix* deepCopy(Matrix* A);

#endif