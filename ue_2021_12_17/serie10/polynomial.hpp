#ifndef INCLUDE_POLYNOMIAL__
#define INCLUDE_POLYNOMIAL__

class Polynomial {
private:
    int n; // degree of the polynomial.
    double *coeff; // n+1 coefficients of the polynomial.

public:
    Polynomial(int n);
    ~Polynomial();

    int degree();

    double getCoeff(int i);
    void setCoeff(int i, double value);

    // Optional, used for testing.
    void scanPoly(int n);
    void printPoly();
};

#endif