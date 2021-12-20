/**
 * Aufgabe 11.1
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix A:" << std::endl;
    Matrix A(4);

    Matrix B = A; // Copy constructor
    B.set(1, 2, 3.0);
    assert(B.get(1, 2) == 3.0);
    assert(A.get(1, 2) == 0.0);

    Matrix C;
    C = A; // Assignment operator
    C.set(2, 3, 4.0);
    assert(C.get(2, 3) == 4.0);
    assert(A.get(2, 3) == 0.0);

    std::cout << std::endl << "Matrix A:" << std::endl;
    A.printMatrix();

    std::cout << std::endl << "Matrix B:" << std::endl;
    B.printMatrix();

    std::cout << std::endl << "Matrix C:" << std::endl;
    C.printMatrix();
    return 0;
}