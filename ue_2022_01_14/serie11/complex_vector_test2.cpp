/**
 * Aufgabe 11.6
 */

#include <cassert>
#include <iostream>

#include "complex_vector.hpp"

int main() {
    ComplexVector A(5);
    A.set(0, Complex(1, 2));
    A.set(1, Complex(-4, 5));
    A.set(2, Complex(11, 0));
    A.set(3, Complex(-9, 0.001));
    A.set(4, Complex(2.5, 23));

    Vector real = A.realPart();
    Vector imag = A.imaginaryPart();

    std::cout << "Real part of A:" << std::endl;
    for (int i = 0; i < real.size(); ++i) {
        std::cout << "real[" << i << "] = " << real.get(i) << std::endl;
    }

    std::cout << std::endl << "Imaginary part of A:" << std::endl;
    for (int i = 0; i < imag.size(); ++i) {
        std::cout << "imag[" << i << "] = " << imag.get(i) << std::endl;
    }

    return 0;
}