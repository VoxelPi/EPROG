#ifndef INCLUDE_COMPLEX_VECTOR__
#define INCLUDE_COMPLEX_VECTOR__

#include "complex.hpp"
#include "vector.hpp"

class ComplexVector
{
private:
    int n;
    Complex *coeff;
public:
    ComplexVector();
    ComplexVector(int n, Complex init = Complex(0.0, 0.0));
    ComplexVector(const ComplexVector& rhs);
    ComplexVector& operator=(const ComplexVector& rhs);
    ~ComplexVector();

    // return vector dimension
    int size() const;
    
    // read and write vector coefficients
    Complex get(int i) const;
    void set(int i, const Complex& value);

    Vector realPart() const;
    Vector imaginaryPart() const;
};


#endif