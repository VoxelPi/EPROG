#include "diagonal_matrix.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>

DiagonalMatrix::DiagonalMatrix() : Matrix() {}

DiagonalMatrix::DiagonalMatrix(int n, double init) : Matrix() {
    assert(n > 0);
    this->n = n;

    // Allocate coefficient array.
    this->coeff = (double*) malloc(n * sizeof(double));
    assert(coeff != (double*) NULL);

    // Initialize coefficient array.
    for (int i = 0; i < n; ++i) {
        this->coeff[i] = init;
    }
}

DiagonalMatrix::~DiagonalMatrix() {}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) malloc(rhs.n * sizeof(double));
    assert(this->coeff != NULL);

    for (int i = 0; i < rhs.n; ++i) {
        this->coeff[i] = rhs.coeff[i];
    }
}

DiagonalMatrix::DiagonalMatrix(const Matrix& rhs) {
    assert(rhs.isDiagonal()); // Check that matrix is diagonal.

    this->n = rhs.size();
    this->coeff = (double*) malloc(n * sizeof(double));
    assert(this->coeff != NULL);

    for (int i = 0; i < n; ++i) {
        set(i, i, rhs.get(i, i));
    }
}

DiagonalMatrix& DiagonalMatrix::operator=(const DiagonalMatrix& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) realloc(this->coeff, rhs.n * sizeof(double));

    for (int i = 0; i < rhs.n; ++i) {
        this->coeff[i] = rhs.coeff[i];
    }

    return *this;
}

double DiagonalMatrix::get(int i, int j) const {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    if (i != j) {
        return 0.0;
    }

    return coeff[i];
}

void DiagonalMatrix::set(int i, int j, double value) {
    assert(i == j);
    assert(i >= 0 && i < n);

    coeff[i] = value;
}

bool DiagonalMatrix::isDiagonal() const {
    return true;
}

void DiagonalMatrix::printMatrix() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(8) << get(i, j) << " "; // setw(8) sets the width of the following output.
        }
        std::cout << std::endl;
    }
}