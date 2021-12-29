#include "matrix.hpp"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

Matrix::Matrix() : n(0), coeff((double*) NULL) {
    // std::cout << "allocate empty matrix" << std::endl;
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
    // std::cout << "allocated " << n << "x" << n << "-matrix (init: " << init << ")" << std::endl;
}

Matrix::~Matrix() {
    free(coeff);
    coeff = NULL;
    // std::cout << "free matrix, size " << n << "x" << n << std::endl;
}

Matrix::Matrix(const Matrix& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) malloc(rhs.n * rhs.n * sizeof(double));
    assert(this->coeff != NULL);

    for (int i = 0; i < rhs.n * rhs.n; ++i) {
        this->coeff[i] = rhs.coeff[i];
    }

    // std::cout << "copy constructor" << std::endl;
}

Matrix& Matrix::operator=(const Matrix& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) realloc(this->coeff, rhs.n * rhs.n * sizeof(double));

    for (int i = 0; i < rhs.n * rhs.n; ++i) {
        this->coeff[i] = rhs.coeff[i];
    }

    // std::cout << "assignment operator" << std::endl;

    return *this;
}

Matrix::Matrix(int n, double lb, double ub) {
    assert(n > 0);
    this->n = n;
    
    // Check that lb is <= ub
    assert(lb <= ub); 

    // Allocate coefficient array.
    this->coeff = (double*) malloc(n * n * sizeof(double));
    assert(coeff != (double*) NULL);

    srand(time(NULL)); // Set seed to current time.
    for (int i = 0; i < n * n; ++i) {
        this->coeff[i] = ((double)rand() / RAND_MAX) * (ub - lb) + lb; // Generate random number between lb and ub
    }
}

int Matrix::size() const {
    return n;
}

double Matrix::get(int i, int j) const {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    return coeff[i + j * n];
}

void Matrix::set(int i, int j, double value) {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);

    coeff[i + j * n] = value;
}

Vector Matrix::multiplyLeft(Vector& x) const {
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

Vector Matrix::multiplyRight(Vector& x) const {
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

void Matrix::scanMatrix(int n) {
    // Reallocate coefficients array.
    this->n = n;
    this->coeff = (double*) realloc(this->coeff, n * n * sizeof(double));
    assert(this->coeff != NULL);

    // Get user input.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            this->coeff[i + j * n] = 0;
            std::cout << "a[" << i << ", " << j << "] = ";
            std::cin >> coeff[i + j * n];
        }
    }
}

void Matrix::printMatrix() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(8) << get(i, j) << " "; // setw(8) sets the width of the following output.
        }
        std::cout << std::endl;
    }
}

double Matrix::trace() const {
    double result;
    for (int j = 0; j < n; ++j) {
        result += coeff[j + j * n];
    }
    return result;
}

double Matrix::columnSumNorm() const {
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

double Matrix::rowSumNorm() const {
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

double Matrix::frobeniusNorm() const {
    double result = 0;

    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            result += get(j, k) * get(j, k);
        }
    }

    return sqrt(result);
}

double Matrix::maxNorm() const {
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

double Matrix::det() const {
    if (n == 1) {
        return coeff[0];
    }

    double determinante = 0.0;

    int yi = 0;
    for (int xi = 0; xi < n; ++xi) {
        // Get selected matrix element.
        double a_ij = get(xi, yi);

        // Calculate sign.
        // xi + 1, yi + 1 because indices should start at 1.
        if (((xi + 1) + (yi + 1)) % 2 == 1) {
            a_ij *= -1;
        }

        // Calculate A_ij
        Matrix sub_matrix(n - 1);
        double *p_data_w = sub_matrix.coeff;
        for (int y = 0; y < n; ++y) {
            if (y == yi) {
                // Skip column
                continue;
            }
            for (int x = 0; x < n; ++x) {
                if (x == xi) {
                    // Skip row
                    continue;
                }
                *p_data_w = coeff[x + y * n];
                ++p_data_w;
            }
        }

        determinante += a_ij * sub_matrix.det();
    }

    return determinante;
}

bool Matrix::isDiagonal() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && get(i, j) != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetric() const {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) { // j = i optimization, only check upper triangle.
            if (get(i, j) != get(j, i)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSkewSymmetric() const {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) { // j = i optimization, only check upper triangle.
            if (get(i, j) != -get(j, i)) {
                return false;
            }
        }
    }
    return true;
}