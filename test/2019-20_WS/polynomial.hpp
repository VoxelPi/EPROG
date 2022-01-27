#ifndef INCLUDE_POLYNOMIAL__
#define INCLUDE_POLYNOMIAL__

#include <iostream>

class Polynomial {
private :
    int n;
    double * c;
public :
    Polynomial(int n = 0);
    Polynomial(const Polynomial&);
    ~Polynomial();
    Polynomial& operator=( const Polynomial&);

    int degree() const ;
    Polynomial diff() const ;
    double quad(double a, double b) const;

    double operator()(double x) const;
    const double& operator[](int j) const;
    double& operator[](int j);

};

Polynomial operator+(const Polynomial& p, const Polynomial& q);
Polynomial operator*(const Polynomial& p, const Polynomial& q);
Polynomial operator*(double lambda, const Polynomial& p);
Polynomial operator*(const Polynomial& p, double lambda);

double root(const Polynomial& p, double x_0, double tau);

std::ostream& operator<<(std::ostream& output, const Polynomial& p);

#endif