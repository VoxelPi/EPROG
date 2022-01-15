#ifndef INCLUDE_MATRIX__
#define INCLUDE_MATRIX__

#include <iostream>

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

    Matrix(int n, double lb, double ub);

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

    // Unary minus UE 12.1
    const Matrix operator-() const;

    // Transpose matrix UE 12.3
    const Matrix operator~() const;
};

// Matrix addition UE 12.1
const Matrix operator+(const Matrix& A, const Matrix& B);

// Matrix subtraction UE 12.1
const Matrix operator-(const Matrix& A, const Matrix& B);

// Matrix-Matrix multiplication UE 12.1
const Matrix operator*(const Matrix& A, const Matrix& B);

// Matrix-Vector multiplication UE 12.3
const Vector operator*(const Matrix& A, const Vector& x);

// Matrix-Scalar multiplication UE 12.3
const Matrix operator*(const Matrix& A, const double s);

// Scalar-Matrix multiplication UE 12.3
const Matrix operator*(const double s, const Matrix& A);

// UE 12.4
std::ostream& operator<<(std::ostream& output, const Matrix& x);

#endif