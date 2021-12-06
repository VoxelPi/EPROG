/**
 * Aufgabe 9.1
 */

#include <cassert>
#include <iostream>

#include "ellipse.hpp"

int main() {
    // Test ellipse.
    Ellipse ellipse;
    std::cout << "Ellipse:" << std::endl;

    // Test get and set center.
    ellipse.setCenter(1.5, 2.5);
    assert(ellipse.getCenterX() == 1.5);
    assert(ellipse.getCenterY() == 2.5);
    std::cout << "  center = (" << ellipse.getCenterX() << ", " << ellipse.getCenterY() << ")" << std::endl;

    // Test get and set A.
    ellipse.setA(5);
    assert(ellipse.getA() == 5);
    std::cout << "  a = " << ellipse.getA() << std::endl;

    // Test get and set B.
    ellipse.setB(2);
    assert(ellipse.getB() == 2);
    std::cout << "  b = " << ellipse.getB() << std::endl;

    // Test Ellipse methods.
    std::cout << std::endl;
    std::cout << "  is circle: " << ellipse.isCircle() << std::endl;
    std::cout << "  focal points: ";
    ellipse.printFocalPoints();
    std::cout << "  eccentricity = " << ellipse.getEccentricity() << std::endl;

    // Test isInside.
    std::cout << std::endl;
    std::cout << "  (0, 0) inside ellipse: " << ellipse.isInside(0.0, 0.0) << std::endl;
    std::cout << "  (1.5, 2.5) inside ellipse: " << ellipse.isInside(1.5, 2.5) << std::endl;
    std::cout << "  (6.5, 2.5) inside ellipse: " << ellipse.isInside(6.5, 2.5) << std::endl;

    // Test circle.
    Ellipse circle;
    std::cout << std::endl << "Circle:" << std::endl;

    // Test get and set center.
    circle.setCenter(0.0, 0.0);
    assert(circle.getCenterX() == 0.0);
    assert(circle.getCenterY() == 0.0);
    std::cout << "  center = (" << circle.getCenterX() << ", " << circle.getCenterY() << ")" << std::endl;

    // Test get and set A.
    circle.setA(1.0);
    assert(circle.getA() == 1.0);
    std::cout << "  a = " << circle.getA() << std::endl;

    // Test get and set B.
    circle.setB(1.0);
    assert(circle.getB() == 1.0);
    std::cout << "  b = " << circle.getB() << std::endl;

    // Test Ellipse methods.
    std::cout << std::endl;
    std::cout << "  is circle: " << circle.isCircle() << std::endl;
    std::cout << "  focal points: ";
    circle.printFocalPoints();
    std::cout << "  eccentricity = " << circle.getEccentricity() << std::endl;

    return 0;
}