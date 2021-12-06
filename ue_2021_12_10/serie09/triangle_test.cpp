/**
 * Aufgabe 9.3
 */

#include <cmath>
#include <iostream>

#include "triangle.hpp"

int main() {
    std::cout << "Triangle:" << std::endl;
    Triangle triangle;
    triangle.setX(0.0, 0.0);
    triangle.setY(1.0, 0.0);
    triangle.setZ(0.0, 1.0);
    std::cout << "  area = " << triangle.getArea() << std::endl;
    std::cout << "  perimeter = " << triangle.getPerimeter() << std::endl;
    std::cout << "  is equilateral = " << triangle.isEquilateral() << std::endl;

    std::cout << std::endl << "Equilateral triangle:" << std::endl;
    Triangle equilateral;
    equilateral.setX(-1.0, 0.0);
    equilateral.setY(1.0, 0.0);
    equilateral.setZ(0.0, std::sqrt(3));
    std::cout << "  area = " << equilateral.getArea() << std::endl;
    std::cout << "  perimeter = " << equilateral.getPerimeter() << std::endl;
    std::cout << "  is equilateral = " << equilateral.isEquilateral() << std::endl;
    return 0;
}
