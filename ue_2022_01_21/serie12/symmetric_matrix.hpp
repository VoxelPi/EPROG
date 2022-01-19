#ifndef INCLUDE_SYMMETRIC_MATRIX__
#define INCLUDE_SYMMETRIC_MATRIX__

#include "matrix.hpp"

class SymmetricMatrix : public Matrix
{
public:
    SymmetricMatrix();
    SymmetricMatrix(int n, double init = 0.0);
    ~SymmetricMatrix();

    SymmetricMatrix(const SymmetricMatrix& rhs);
    SymmetricMatrix(const Matrix& rhs); // Cast Matrix -> SymmetricMatrix
    SymmetricMatrix& operator=(const SymmetricMatrix& rhs);

    // read and write matrix coefficients.
    double get(int i, int j) const;
    void set(int i, int j, double value);

    void printMatrix() const;
    bool isSymmetric() const;
};

#endif
