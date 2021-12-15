#include "matrix.hpp"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
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

/**
 * UE 10.3
 */ 

Vector Matrix::multiplyLeft(Vector& x) {
    assert(n == x.size());

    Vector result(n, 0.0);

    for (int i = 0; i < n; ++i) {
        double r_i = 0.0;
        for (int j = 0; j < n; ++j) {
            r_i += this->get(i, j) * x.get(j);
        } 
        result.set(i, r_i);
    }

    return result;
}

Vector Matrix::multiplyRight(Vector& x) {
    assert(n == x.size());

    Vector result(n);

    for (int i = 0; i < n; ++i) {
        double r_i = 0.0;
        for (int j = 0; j < n; ++j) {
            r_i += this->get(j, i) * x.get(j);
        } 
        result.set(i, r_i);
    }

    return result;
}

/**
 * UE 10.4
 */
void Matrix::scanMatrix(int n) {
    // Free existing data.
    if (this->n != 0 && this->coeff != NULL) {
        free(this->coeff);
    }
    this->n = n;
    this->coeff = (double*) malloc(n * n * sizeof(double));
    assert(this->coeff != NULL);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << i << ", " << j << "] = ";
            std::cin >> coeff[i + j * n];
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(8) << get(i, j) << " "; // setw(8) sets the width of the following output.
        }
        std::cout << std::endl;
    }
}

double Matrix::trace() {
    double result;
    for (int j = 0; j < n; ++j) {
        result += coeff[j + j * n];
    }
    return result;
}

/**
 * UE 10.5
 */
double Matrix::columnSumNorm() {
    double max = 0;

    for (int k = 0; k < n; ++k) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += fabs(get(j, k));
        }

        if (sum > max) {
            max = sum;
        }
    }

    return max;
}

double Matrix::rowSumNorm() {
    double max = 0;

    for (int j = 0; j < n; ++j) {
        double sum = 0;
        for (int k = 0; k < n; ++k) {
            sum += fabs(get(j, k));
        }

        if (sum > max) {
            max = sum;
        }
    }

    return max;
}

double Matrix::frobeniusNorm() {
    double result = 0;

    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            result += get(j, k) * get(j, k);
        }
    }

    return sqrt(result);
}

double Matrix::maxNorm() {
    double max = 0;

    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            double abs_a_jk = fabs(get(j, k));
            if (abs_a_jk > max) {
                max = abs_a_jk;
            }
        }
    }

    return max;
}