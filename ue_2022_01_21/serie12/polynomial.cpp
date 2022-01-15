#include "polynomial.hpp"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

#define TOLERANCE 10e-13

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
    this->coeff = NULL;
}

Polynomial::Polynomial(const Polynomial& rhs) : n(rhs.n) {
    coeff = (double*) malloc((n + 1) * sizeof(double));
    assert(coeff != NULL);

    for (int i = 0; i <= n; ++i) {
        coeff[i] = rhs.coeff[i];
    }
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    this->n = rhs.n;
    this->coeff = (double*) realloc(this->coeff, (n + 1) * sizeof(double));

    for (int i = 0; i <= n; ++i) {
        coeff[i] = rhs.coeff[i];
    }

    return *this;
}

int Polynomial::degree() const {
    return this->n;
}

double Polynomial::getCoeff(int i) const {
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
    this->coeff = (double*) realloc(this->coeff, (n + 1) * sizeof(double));
    assert(this->coeff != NULL);

    // Get user input.
    for (int i = 0; i <= n; ++i) {
        this->coeff[i] = 0;
        std::cout << "a_" << i << " = ";
        std::cin >> this->coeff[i];
    }
}

void Polynomial::printPoly() const {
    for (int i = n; i >= 1; --i) {
        std::cout << coeff[i] << "*x^" << i << " + ";
    }
    std::cout << coeff[0] << std::endl;
}

/**
 * UE 10.6
 */ 
Polynomial Polynomial::diff(int k) const {
    // Degree of derivative is deg(poly) - k.
    int d_n = n - k;

    // If deg(poly) - k < 0 return 0.
    if (d_n < 0) {
        return Polynomial(0);
    }

    // Create derivative polynomial.
    Polynomial derivative(d_n);

    // Set coefficients of derivative.
    for (int i_d = 0; i_d <= d_n; ++i_d) {
        int i_p = i_d + k; // corresponding index in the original polynomial.

        // Calculate factor. a*x^n -> (n) * a*x^(n-1) -> (n*(n-1)) * a*x^(n-2) -> (n*(n-1)*(n-2)) * a*x^(n-3)
        int b = 1;
        for (int j = 0; j < k; ++j) {
            b *= (i_p - j);
        }

        // Set coefficient.
        derivative.coeff[i_d] = b * this->coeff[i_p];
    }

    return derivative;
}

/**
 * UE 10.7
 */ 
double Polynomial::eval(double x) const {
    double y = coeff[0];
    double x_i = 1;
    for (int i = 1; i <= n; ++i) {
        x_i *= x;
        y += coeff[i] * x_i;
    }

    return y;
}

/**
 * UE 11.8
 */
double Polynomial::computeIntegral(double alpha, double beta) const {
    assert(alpha < beta);

    double result = 0.0;

    double alpha_power = alpha; // alpha^(i+1)
    double beta_power = beta;   //  beta^(i+1)
    for (int j = 0; j <= n; ++j) {
        result += (coeff[j] * (beta_power - alpha_power)) / (j + 1);
        alpha_power *= alpha;
        beta_power *= beta;
    }
    
    return result;
}

/**
 * UE 10.8
 */
Polynomial addPolynomials(const Polynomial& p, const Polynomial& q) {
    int n; // Calculate degree of sum polynomial
    if (p.degree() > q.degree()) {
        n = p.degree();
    } else {
        n = q.degree();
    }

    Polynomial sum(n);

    for (int i = 0; i <= n; ++i) {
        double p_c_i = 0, q_c_i = 0;

        if (p.degree() >= i) {
            p_c_i = p.getCoeff(i);
        }
        if (q.degree() >= i) {
            q_c_i = q.getCoeff(i);
        }

        sum.setCoeff(i, p_c_i + q_c_i);
    }

    return sum;
}

// UE 11.7
const Polynomial prodPolynomials(const Polynomial& p, const Polynomial& q) {
    int n_p = p.degree();
    int n_q = q.degree();

    Polynomial result(n_p + n_q);

    // Calculate the coefficients of the resulting polynomial.
    for (int i_p = 0; i_p <= n_p; ++i_p) {
        for (int i_q = 0; i_q <= n_q; ++i_q) {
            int i = i_p + i_q;
            result.setCoeff(i, result.getCoeff(i) + p.getCoeff(i_p) * q.getCoeff(i_q));
        }
    }

    return result;
}

// UE 12.5
bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    if (lhs.degree() != rhs.degree()) {
        return false;
    }

    for (int i = 0; i <= lhs.degree(); ++i) {
        if (fabs(lhs.getCoeff(i) - rhs.getCoeff(i)) > TOLERANCE) {
            return false;
        }
    }

    return true;
}
