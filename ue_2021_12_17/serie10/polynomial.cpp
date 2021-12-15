#include "polynomial.hpp"

#include <cassert>
#include <cstdlib>
#include <iostream>

Polynomial::Polynomial(int n) : n(n) {
    assert(n >= 0);

    this->coeff = (double*) malloc((n + 1) * sizeof(double));
    assert(this->coeff != (double*) NULL);

    for (int i = 0; i <= n; ++i) {
        this->coeff[i] = 0.0;
    }
}

Polynomial::~Polynomial() {
    free(this->coeff);
}

int Polynomial::degree() {
    return this->n;
}

double Polynomial::getCoeff(int i) {
    assert(0 <= i && i <= n);
    return this->coeff[i];
}

void Polynomial::setCoeff(int i, double value) {
    assert(0 <= i && i <= n);
    this->coeff[i] = value;
}

void Polynomial::scanPoly(int n) {
    // Reallocate coefficients array.
    this->n = n;
    this->coeff = (double*) realloc(this->coeff, n * n * sizeof(double));
    assert(this->coeff != NULL);

    // Get user input.
    for (int i = 0; i <= n; ++i) {
        this->coeff[i] = 0;
        std::cout << "a_" << i << " = ";
        std::cin >> this->coeff[i];
    }
}

void Polynomial::printPoly() {
    for (int i = n; i >= 1; --i) {
        std::cout << coeff[i] << "*x^" << i << " + ";
    }
    std::cout << coeff[0] << std::endl;
}