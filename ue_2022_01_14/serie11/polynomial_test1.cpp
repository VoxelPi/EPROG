/**
 * Aufgabe 11.7
 */

#include <cassert>
#include <iostream>

#include "polynomial.hpp"

int main() {
    int p_n = 0, q_n = 0;

    std::cout << "Polynomial p: ";
    std::cout << "deg(p) = ";
    std::cin >> p_n;
    Polynomial p(p_n);
    p.scanPoly(p_n);
    p.printPoly();

    std::cout << std::endl;
    std::cout << "Polynomial q: ";
    std::cout << "deg(q) = ";
    std::cin >> q_n;
    Polynomial q(q_n);
    q.scanPoly(q_n);
    q.printPoly();

    std::cout << std::endl;
    Polynomial prod = prodPolynomials(p, q);
    std::cout << "(p * q) = ";
    prod.printPoly();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}