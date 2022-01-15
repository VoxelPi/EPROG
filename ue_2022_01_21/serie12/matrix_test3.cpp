/**
 * UE 12.4
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix A =" << std::endl;
    Matrix A(3);
    A.scanMatrix(3);

    // Test A.printMatrix();
    std::cout << std::endl << "A.printMatrix():" << std::endl;
    A.printMatrix();

    // Test std::cout << A;
    std::cout << std::endl << "std::cout << A:" << std::endl << A << std::endl;

    return 0;
}
