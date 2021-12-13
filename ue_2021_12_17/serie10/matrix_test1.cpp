/**
 * Aufgabe 10.1
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix A:" << std::endl;
    Matrix A;
    std::cout << "Size: " << A.size() << "x" << A.size() << std::endl;

    std::cout << "Matrix B:" << std::endl;
    Matrix B(4);
    std::cout << "Size: " << B.size() << "x" << B.size() << std::endl;
    B.set(1, 2, 5);
    assert(B.get(1, 2) == 5);

    std::cout << "Matrix C:" << std::endl;
    Matrix C(4, 1);
    std::cout << "Size: " << B.size() << "x" << B.size() << std::endl;
    assert(C.get(1, 2) == 1);
    return 0;
}