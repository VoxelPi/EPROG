/**
 * UE 12.3
 */

#include <cassert>
#include <iostream>

#include "matrix.hpp"
#include "vector.hpp"

void scanVector(Vector& vector) {
    double input = 0;

    for (int i = 0; i < vector.size(); ++i) {
        input = 0;
        std::cout << "  vector[" << i << "] = ";
        std::cin >> input;
        vector.set(i, input);
    }
}

void printVector(const Vector& vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << "  vector[" << i << "] = " << vector.get(i) << std::endl;
    }
}

int main() {
    std::cout << "Matrix A =" << std::endl;
    Matrix A(3);
    A.scanMatrix(3);

    std::cout << "Vector x =" << std::endl;
    Vector x(3);
    scanVector(x);

    std::cout << "Scalar s = ";
    double s = 0.0;
    std::cin >> s;

    std::cout << std::endl << "~A:" << std::endl;
    (~A).printMatrix();

    std::cout << std::endl << "A * x:" << std::endl;
    printVector(A * x);

    std::cout << std::endl << "A * s:" << std::endl;
    (A * s).printMatrix();

    std::cout << std::endl << "s * A:" << std::endl;
    (s * A).printMatrix();

    return 0;
}
