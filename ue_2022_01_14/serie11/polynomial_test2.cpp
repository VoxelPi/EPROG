/**
 * Aufgabe 11.8
 */

#include <cassert>
#include <iostream>

#include "polynomial.hpp"

int main() {
    int p_n = 0;

    std::cout << "Polynomial p: ";
    std::cout << "deg(p) = ";
    std::cin >> p_n;
    Polynomial p(p_n);
    p.scanPoly(p_n);
    p.printPoly();

    double alpha = 0.0, beta = 0.0;
    std::cout << "Alpha: ";
    std::cin >> alpha;
    std::cout << "Beta: ";
    std::cin >> beta;

    std::cout << std::endl;
    std::cout << "p.computeIntegral(alpha, beta) = " << p.computeIntegral(alpha, beta) << std::endl;

    return 0;
}