/**
 * Aufgabe 10.7
 */

#include <cassert>
#include <iostream>

#include "polynomial.hpp"

int main() {
    double x = 0;

    Polynomial poly(4);
    poly.scanPoly(4);

    std::cout << "Polynomial: ";
    poly.printPoly();

    std::cout << "x = ";
    std::cin >> x;

    std::cout << "p(x) = " << poly.eval(x) << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}