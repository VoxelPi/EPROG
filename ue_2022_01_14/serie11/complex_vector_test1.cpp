/**
 * Aufgabe 11.2
 */

#include <cassert>
#include <iostream>

#include "complex_vector.hpp"

int main() {
    ComplexVector A(10);
    ComplexVector B = A;
    ComplexVector C;
    C = A;

    B.set(1, Complex(2.0, 3.0));
    assert(A.get(1).real() == 0.0 && A.get(1).imag() == 0.0);
    assert(B.get(1).real() == 2.0 && B.get(1).imag() == 3.0);

    C.set(2, Complex(4.0, 5.0));
    assert(A.get(2).real() == 0.0 && A.get(2).imag() == 0.0);
    assert(C.get(2).real() == 4.0 && C.get(2).imag() == 5.0);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}