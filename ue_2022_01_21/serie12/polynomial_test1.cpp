/**
 * UE 12.5
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

    std::cout << "Polynomial q: ";
    std::cout << "deg(q) = ";
    std::cin >> q_n;
    Polynomial q(q_n);
    q.scanPoly(q_n);

    std::cout << "p == q: ";
    if (p == q) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}