#include "polynomial.hpp"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

Polynomial::Polynomial(int n) {
    assert(n >= 0);
    this->n = n;

    c = new double[n + 1];
    for (int i = 0; i <= n; ++i) {
        c[i] = 0.0;
    }
}

Polynomial::Polynomial(const Polynomial& rhs) {
    n = rhs.n;

    c = new double[n];
    for (int i = 0; i <= n; ++i) {
        c[i] = rhs.c[i];
    }
}

Polynomial::~Polynomial() {
    delete[] c;
    c = (double*)NULL;
    n = 0;
}

int Polynomial::degree() const {
    return n;
}

const double& Polynomial::operator[](int j) const {
    assert(0 <= j && j <= n);
    return c[j];
}

double& Polynomial::operator[](int j) {
    assert(0 <= j && j <= n);
    return c[j];
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (c != NULL) {
        delete[] c;
    }

    n = rhs.n;
    c = new double[n];
    for (int i = 0; i <= n; ++i) {
        c[i] = rhs.c[i];
    }

    return *this;
}

double Polynomial::operator()(double x) const {
    double result = 0.0;
    double x_p = 1;
    
    for (int i = 0; i <= n; ++i) {
        result += x_p * c[i];
        x_p *= x;
    }

    return result;
}

Polynomial Polynomial::diff() const {
    if (n == 0) {
        return Polynomial(0);
    }

    Polynomial result(n - 1);
    for (int i = 1; i <= n; ++i) {
        result.c[i - 1] = i * c[i];
    }

    return result;
}

double Polynomial::quad(double a, double b) const {
    assert(a <= b);

    double result = 0.0;
    double a_p = 1.0;
    double b_p = 1.0;

    for (int i = 0; i <= n; ++i) {
        a_p *= a;
        b_p *= b;
        result += c[i] * (b_p - a_p) / (i + 1);
    }

    return result;
}

Polynomial operator+(const Polynomial& p, const Polynomial& q) {
    int n = p.degree();
    if (q.degree() > n) {
        n = q.degree();
    }

    Polynomial result(n);
    for (int i = 0; i <= n; ++i) {
        result[i] = 0;
        if (p.degree() >= i) {
            result[i] += p[i];
        }
        if (q.degree() >= i) {
            result[i] += q[i];
        }
    }

    return result;
}

Polynomial operator*(const Polynomial& p, double lambda) {
    Polynomial result(p.degree());

    for (int i = 0; i <= p.degree(); ++i) {
        result[i] = p[i] * lambda;
    }

    return result;
}

Polynomial operator*(double lambda, const Polynomial& p) {
    return p * lambda;
}

Polynomial operator*(const Polynomial& p, const Polynomial& q) {
    int n = p.degree() + q.degree();
    Polynomial result(n);

    for (int i_p = 0; i_p <= p.degree(); ++i_p) {
        for (int i_q = 0; i_q <= q.degree(); ++i_q) {
            result[i_p + i_q] += p[i_p] * q[i_q];
        }
    }

    return result;
}

double root(const Polynomial& p, double x_0, double tau) {
    assert(tau > 0);

    double x_n = 0.0; // current x
    double x_n_1 = x_0; // previos x

    Polynomial derivative = p.diff();

    while (1) {
        x_n = x_n_1 - p(x_n_1) / derivative(x_n_1);
        if (fabs(x_n - x_n_1) <= tau && fabs(p(x_n)) <= tau) {
            break;
        }
        x_n_1 = x_n;
    }

    return x_n;    
}

std::ostream& operator<<(std::ostream& output, const Polynomial& p) {
    for (int i = p.degree(); i >= 1; --i) {
        output << p[i] << "*x^" << i << " + ";
    }
    output << p[0];

    return output;
}