#include "polynomial.hpp"

#include <cassert>
#include <cstdlib>

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