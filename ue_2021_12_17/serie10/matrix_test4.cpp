/**
 * Aufgabe 10.5
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix:" << std::endl;
    Matrix A;

    A.scanMatrix(3);
    A.printMatrix();

    std::cout << "A.columnSumNorm() = " << A.columnSumNorm() << std::endl;
    std::cout << "A.rowSumNorm()    = " << A.rowSumNorm() << std::endl;
    std::cout << "A.frobeniusNorm() = " << A.frobeniusNorm() << std::endl;
    std::cout << "A.maxNorm()       = " << A.maxNorm() << std::endl;
    return 0;
}