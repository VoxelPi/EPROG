/**
 * Aufgabe 10.6
 */

#include <cassert>
#include <iostream>

#include "polynomial.hpp"

int main() {
    int k = 0;

    Polynomial poly(4);
    poly.scanPoly(4);

    std::cout << "Polynomial: ";
    poly.printPoly();

    std::cout << "k = ";
    std::cin >> k;

    Polynomial derivative = poly.diff(k);
    std::cout << k << "-Derivative: ";
    derivative.printPoly();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}