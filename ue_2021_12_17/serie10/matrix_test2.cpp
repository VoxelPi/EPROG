/**
 * Aufgabe 10.3
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"

int main() {
    std::cout << "Matrix:" << std::endl;
    Matrix A(2);
    A.set(0, 0, 0.0);
    A.set(0, 1, -1.0);
    A.set(1, 0, 1.0);
    A.set(1, 1, 0.0);

    Vector x(2);
    x.set(0, 2.0);
    x.set(1, 3.0);

    Vector Ax = A.multiplyLeft(x);
    Vector xA = A.multiplyRight(x);

    std::cout << "A*x = (" << Ax.get(0) << ", " << Ax.get(1) << ")" << std::endl;
    std::cout << "x*A = (" << xA.get(0) << ", " << xA.get(1) << ")" << std::endl;
    return 0;
}