#include "complex_vector.hpp"

ComplexVector::ComplexVector() {
    this->n = 0;
    this->coeff = (Complex*)NULL;
}

ComplexVector::ComplexVector(int n, Complex init) {
    assert(n > 0);
    this->n = n;

    // Allocate coefficient array.
    this->coeff = new Complex[n];
    assert(this->coeff != (Complex*)NULL);

    for (int i = 0; i < n; ++i) {
        this->coeff[i] = init;
    }
}

ComplexVector::ComplexVector(const ComplexVector& rhs) {
    this->n = rhs.n;
    this->coeff = new Complex[rhs.n];
    assert(this->coeff != (Complex*)NULL);

    for (int i = 0; i < rhs.n; ++i) {
        this->coeff[i] = rhs.coeff[i];
    }
}

ComplexVector& ComplexVector::operator=(const ComplexVector& rhs) {
    this->n = rhs.n;
    delete[] this->coeff;
    this->coeff = new Complex[rhs.n];
    assert(this->coeff != (Complex*)NULL);

    for (int i = 0; i < rhs.n; ++i) {
        this->coeff[i] = rhs.coeff[i];
    }

    return *this;
}

ComplexVector::~ComplexVector() {
    delete[] this->coeff;
    this->coeff = NULL;
}

int ComplexVector::size() const {
    return n;
}

Complex ComplexVector::get(int i) const {
    assert(i >= 0 && i < n);

    return coeff[i];
}

void ComplexVector::set(int i, const Complex& value) {
    assert(i >= 0 && i < n);

    this->coeff[i] = value;
}

Vector ComplexVector::realPart() const {
    Vector real(n);
    
    for (int i = 0; i < n; ++i) {
        real.set(i, coeff[i].real());
    }

    return real;
}

Vector ComplexVector::imaginaryPart() const {
    Vector imag(n);
    
    for (int i = 0; i < n; ++i) {
        imag.set(i, coeff[i].imag());
    }

    return imag;
}