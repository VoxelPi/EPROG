/**
 * UE 12.7
 */

#include <cassert>
#include <iostream>

#include "diagonal_matrix.hpp"

int main() {
    DiagonalMatrix A(5);

    A.set(1, 1, 4.0);
    A.set(4, 4, -2.5);
    // A.set(2, 4, -2.5);

    assert(A.get(2, 3) == 0.0);
    assert(A.get(1, 1) == 4.0);
    assert(A.get(4, 4) == -2.5);

    std::cout << std::endl << "A:" << std::endl;
    A.printMatrix();

    Matrix B = (Matrix)A;
    std::cout << std::endl << "B:" << std::endl;
    B.printMatrix();

    B.set(3, 3, -1);
    // B.set(3, 2, -1);
    std::cout << std::endl << "C:" << std::endl;
    DiagonalMatrix C = (DiagonalMatrix)B;
    C.printMatrix();

    return 0;
}