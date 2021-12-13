/**
 * Aufgabe 10.2
 */

#include <cassert>
#include <iostream>

#include "polynomial.hpp"

int main() {
    Polynomial poly(4);

    // Check if degree of the polynomial is correct.
    assert(poly.degree() == 4);

    // Check if coeffient is initialized to 0.
    assert(poly.getCoeff(3) == 0);

    // Check if coefficient can be changed.
    poly.setCoeff(3, 1.5);
    assert(poly.getCoeff(3) == 1.5);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}