/**
 * Aufgabe 11.1
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

    std::cout << "Matrix.isDiagonal() = " << A.isDiagonal() << std::endl;
    std::cout << "Matrix.isSymmetric() = " << A.isSymmetric() << std::endl;
    std::cout << "Matrix.isSkewSymmetric() = " << A.isSkewSymmetric() << std::endl;

    return 0;
}