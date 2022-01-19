#include "symmetric_matrix.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>

SymmetricMatrix::SymmetricMatrix() : Matrix() {}

SymmetricMatrix::SymmetricMatrix(int n, double init) : Matrix() {
    assert(n > 0);
    this->n = n;

    // Allocate coefficient array.
    this->coeff = (double*) malloc((n*(n+1)/2) * sizeof(double));
    assert(coeff != (double*) NULL);

    // Initialize coefficient array.
    for (int i = 0; i < n*(n+1)/2; ++i) {
        this->coeff[i] = init;
    }
}

SymmetricMatrix::~SymmetricMatrix() {}

SymmetricMatrix::SymmetricMatrix(const SymmetricMatrix& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) malloc((rhs.n*(rhs.n+1)/2) * sizeof(double));
    assert(this->coeff != NULL);

    for (int i = 0; i < (rhs.n*(rhs.n+1)/2); ++i) {
        this->coeff[i] = rhs.coeff[i];
    }
}

SymmetricMatrix::SymmetricMatrix(const Matrix& rhs) {
    assert(rhs.isSymmetric()); // Check that matrix is symmetric.

    this->n = rhs.size();
    this->coeff = (double*) malloc((n*(n+1)/2) * sizeof(double));
    assert(this->coeff != NULL);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            set(i, j, rhs.get(i, j));
        }
    }
}

SymmetricMatrix& SymmetricMatrix::operator=(const SymmetricMatrix& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) realloc(this->coeff, (rhs.n*(rhs.n+1)/2) * sizeof(double));

    for (int i = 0; i < (rhs.n*(rhs.n+1)/2); ++i) {
        this->coeff[i] = rhs.coeff[i];
    }

    return *this;
}

double SymmetricMatrix::get(int i, int j) const {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    if (j > i) {
        return get(j, i);
    }

    // return coeff[i + j * n - (((j+1)*(j+1)) - ((j+1)*(j+2)/2))];
    return coeff[i + j*n - ((j*(j+1))/2)];
}

void SymmetricMatrix::set(int i, int j, double value) {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    if (j > i) {
        set(j, i, value);
        return;
    }

    coeff[i + j*n - ((j*(j+1))/2)] = value;
}

bool SymmetricMatrix::isSymmetric() const {
    return true;
}

void SymmetricMatrix::printMatrix() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(8) << get(i, j) << " "; // setw(8) sets the width of the following output.
        }
        std::cout << std::endl;
    }
}