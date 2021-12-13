/**
 * Aufgabe 10.4
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix:" << std::endl;
    Matrix A;

    A.scanMatrix(3);
    A.printMatrix();
    std::cout << "tr(A) = " << A.trace() << std::endl;
    return 0;
}