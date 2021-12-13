#include "matrix.hpp"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

Matrix::Matrix() : n(0), coeff((double*) NULL) {
    std::cout << "allocate empty matrix" << std::endl;
}

Matrix::Matrix(int n, double init) {
    assert(n > 0);
    this->n = n;

    // Allocate coefficient array.
    this->coeff = (double*) malloc(n * n * sizeof(double));
    assert(coeff != (double*) NULL);

    for (int i = 0; i < n * n; ++i) {
        this->coeff[i] = init;
    }
    std::cout << "allocated " << n << "x" << n << "-matrix (init: " << init << ")" << std::endl;
}

Matrix::~Matrix() {
    free(coeff);
    std::cout << "free matrix, size " << n << "x" << n << std::endl;
}

int Matrix::size() {
    return n;
}

double Matrix::get(int i, int j) {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    return coeff[i + j * n];
}

void Matrix::set(int i, int j, double value) {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    coeff[i + j * n] = value;
}
