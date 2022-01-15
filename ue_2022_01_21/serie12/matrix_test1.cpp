/**
 * UE 12.1
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix A:" << std::endl;
    Matrix A(3);
    A.scanMatrix(3);

    std::cout << "Matrix B:" << std::endl;
    Matrix B(3);
    B.scanMatrix(3);

    std::cout << std::endl << "-A:" << std::endl;
    (-A).printMatrix();

    std::cout << std::endl << "A + B:" << std::endl;
    (A + B).printMatrix();

    std::cout << std::endl << "A - B:" << std::endl;
    (A - B).printMatrix();

    std::cout << std::endl << "A * B:" << std::endl;
    (A * B).printMatrix();
    return 0;
}
