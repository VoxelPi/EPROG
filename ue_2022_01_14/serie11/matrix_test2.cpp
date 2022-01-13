/**
 * Aufgabe 11.3
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    int n;
    std::cout << "Matrix size: ";
    std::cin >> n;

    std::cout << "Matrix:" << std::endl;
    Matrix A(n);
    A.scanMatrix(n);

    std::cout << "Matrix.det() = " << A.det() << std::endl;

    return 0;
}