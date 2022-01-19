#ifndef INCLUDE_DIAGONAL_MATRIX__
#define INCLUDE_DIAGONAL_MATRIX__

#include "matrix.hpp"

class DiagonalMatrix : public Matrix
{
public:
    DiagonalMatrix();
    DiagonalMatrix(int n, double init = 0.0);
    ~DiagonalMatrix();

    DiagonalMatrix(const DiagonalMatrix& rhs);
    DiagonalMatrix(const Matrix& rhs); // Cast Matrix -> SymmetricMatrix
    DiagonalMatrix& operator=(const DiagonalMatrix& rhs);

    // read and write matrix coefficients.
    double get(int i, int j) const;
    void set(int i, int j, double value);

    bool isDiagonal() const;
    void printMatrix() const;
};

#endif
