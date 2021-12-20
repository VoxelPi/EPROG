#include "complex.hpp"
using std::ostream;

/**
 * (EPROG VO 286-292) 
 */ 

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rhs) {
    re = rhs.re;
    im = rhs.im;
}

Complex::~Complex() {
}

Complex& Complex::operator=(const Complex& rhs) {
    if (this != &rhs) {
        re = rhs.re;
        im = rhs.im;
    }
    return *this;
}

double Complex::real() const {
    return re;
}

double Complex::imag() const {
    return im;
}

double Complex::abs() const {
    return sqrt(re*re + im*im);
}

Complex::operator double() const {
        return re;
}


Complex Complex::operator-() const {
    return Complex(-re,-im);
}

Complex Complex::operator~() const {
    return Complex(re,-im);
}

Complex operator+(const Complex& x,const Complex& y){
    double xr = x.real();
    double xi = x.imag();
    double yr = y.real();
    double yi = y.imag();
    return Complex(xr + yr, xi + yi);
}

Complex operator-(const Complex& x,const Complex& y){
    double xr = x.real();
    double xi = x.imag();
    double yr = y.real();
    double yi = y.imag();
    return Complex(xr - yr, xi - yi);
}

Complex operator*(const Complex& x,const Complex& y){
    double xr = x.real();
    double xi = x.imag();
    double yr = y.real();
    double yi = y.imag();
    return Complex(xr*yr - xi*yi, xr*yi + xi*yr);
}

Complex operator/(const Complex& x, const double y){
    assert(y != 0);
    return Complex(x.real()/y, x.imag()/y);
}

Complex operator/(const Complex& x,const Complex& y){
    double norm = y.abs();
    assert(norm > 0);
    return x*~y / (norm*norm);
}

std::ostream& operator<<(std::ostream& output,
                                                 const Complex& x) {
    if (x.imag() == 0) {
        return output << x.real();
    }
    else if (x.real() == 0) {
        return output << x.imag() << "i";
    }
    else if (x.imag() > 0) {
        return output << x.real() << " + " << x.imag() << "i";
    }
    else {
        return output << x.real() << " - " << -x.imag() << "i";
    }
}
