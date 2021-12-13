#ifndef INCLUDE_MATRIX__
#define INCLUDE_MATRIX__

#include "vector.hpp"

class Matrix {
private:
    int n;
    double *coeff;

public:
    Matrix();
    Matrix(int n, double init = 0.0);
    ~Matrix();

    // return matrix dimension
    int size();

    // read and write matrix coefficients.
    double get(int i, int j);
    void set(int i, int j, double value);

    // UE 10.3
    // Calculates the matrix-vector product.
    Vector multiplyLeft(Vector& x);
    // Calculates the vector-matrix product.
    Vector multiplyRight(Vector& x);

    // UE 10.4
    void scanMatrix(int n);
    void printMatrix();
    double trace();
};


#endif