#include "polynomial.hpp"

#include <cassert>
#include <iostream>

int main() {
    Polynomial p(3);
    p[0] = 8.0;
    p[1] = -3.2;
    p[2] = 1.5;
    p[3] = 0.1;

    Polynomial q(2);
    q[0] = -4.0;
    q[1] = -2.0;
    q[2] = 1.0;

    std::cout << "p: " << p << std::endl;
    std::cout << "q: " << q << std::endl;

    std::cout << "p + q: " << (p + q) << std::endl;
    std::cout << "p * 2: " << (p * 2) << std::endl;
    std::cout << "2 * p: " << (2 * p) << std::endl;
    std::cout << "p * q: " << (p * q) << std::endl;

    std::cout << "p': " << p.diff() << std::endl;
    std::cout << "p'': " << p.diff().diff() << std::endl;
    std::cout << "p''': " << p.diff().diff().diff() << std::endl;
    std::cout << "p'''': " << p.diff().diff().diff().diff() << std::endl;
    std::cout << "p''''': " << p.diff().diff().diff().diff().diff() << std::endl;

    std::cout << "p.degree(): " << p.degree() << std::endl;

    std::cout << "p.quad(-1.9, 1.5): " << p.quad(-1.9, 1.5) << std::endl;

    double x = root(q, 3.0, 1e-6);

    std::cout << "q.root(): " << x << std::endl;
    std::cout << "q(1.0): " << q(1.0) << std::endl;
    std::cout << "q(" << x << "): " << q(x) << std::endl;

    return 0;
}