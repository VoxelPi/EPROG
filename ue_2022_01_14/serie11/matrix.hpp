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

    Matrix(const Matrix& rhs);
    Matrix& operator=(const Matrix& rhs);

    // return matrix dimension
    int size() const;

    // read and write matrix coefficients.
    double get(int i, int j) const;
    void set(int i, int j, double value);

    // Calculates the matrix-vector product.
    Vector multiplyLeft(Vector& x) const;
    // Calculates the vector-matrix product.
    Vector multiplyRight(Vector& x) const;

    void scanMatrix(int n);
    void printMatrix() const;
    double trace() const;

    double columnSumNorm() const;
    double rowSumNorm() const;
    double frobeniusNorm() const;
    double maxNorm() const;

    // Calculates the determinant.
    double det() const;

    bool isDiagonal() const;
    bool isSymmetric() const;
    bool isSkewSymmetric() const;
};

#endif