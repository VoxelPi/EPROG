#ifndef INCLUDE_COMPLEX__
#define INCLUDE_COMPLEX__

/**
 * (EPROG VO 286-292) 
 */ 

#include <iostream>
#include <cmath>
#include <cassert>

class Complex {
private:
    double re;
    double im;
public:
    Complex(double=0, double=0);
    Complex(const Complex&);
    ~Complex();
    Complex& operator=(const Complex&);

    double real() const;
    double imag() const;
    double abs() const;

    operator double() const;

    Complex operator~() const;
    Complex operator-() const;

};

std::ostream& operator<<(std::ostream& output,
                                      const Complex& x);
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const double);
Complex operator/(const Complex&, const Complex&);

#endif
