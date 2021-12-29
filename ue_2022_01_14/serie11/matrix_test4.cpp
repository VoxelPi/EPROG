/**
 * Aufgabe 11.5
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    int n;
    double lb = 0.0, ub = 0.0;
    std::cout << "Matrix size: ";
    std::cin >> n;
    std::cout << "lb: ";
    std::cin >> lb;
    std::cout << "ub: ";
    std::cin >> ub;

    Matrix A(n, lb, ub);

    std::cout << "Matrix:" << std::endl;
    A.printMatrix();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(A.get(i, j) >= lb && A.get(i, j) <= ub);
        }
    }

    return 0;
}