/**
 * UE 12.6
 */

#include <cassert>
#include <iostream>

#include "symmetric_matrix.hpp"

int main() {
    SymmetricMatrix A(5);

    A.set(2, 3, 4.0);
    A.set(4, 1, -2.5);

    assert(A.get(2, 3) == 4.0);
    assert(A.get(3, 2) == 4.0);
    assert(A.get(4, 1) == -2.5);
    assert(A.get(1, 4) == -2.5);

    std::cout << std::endl << "A:" << std::endl;
    A.printMatrix();

    Matrix B = (Matrix)A;
    std::cout << std::endl << "B:" << std::endl;
    B.printMatrix();

    B.set(1, 2, 1);
    B.set(2, 1, 1);
    B.set(3, 3, -1);
    std::cout << std::endl << "C:" << std::endl;
    SymmetricMatrix C = (SymmetricMatrix)B;
    C.printMatrix();

    return 0;
}