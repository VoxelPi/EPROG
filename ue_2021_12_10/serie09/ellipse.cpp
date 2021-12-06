#include "ellipse.hpp"

#include <cmath>
#include <iostream>

double Ellipse::getCenterX() {
    return center[0];
}

double Ellipse::getCenterY() {
    return center[1];
}

double Ellipse::getA() {
    return a;
}

double Ellipse::getB() {
    return b;
}

void Ellipse::setCenter(double x, double y) {
    this->center[0] = x;
    this->center[1] = y;
}

void Ellipse::setA(double a) {
    this->a = a;
}

void Ellipse::setB(double b) {
    this->b = b;
}

bool Ellipse::isInside(double x, double y) {
    double distance = ((x - center[0]) * (x - center[0]) / (a * a)) + ((y - center[1]) * (y - center[1]) / (b * b));
    if (distance <= 1) {
        if (distance == 1) {
            std::cout << "Point lies on the ellipse." << std::endl;
        }
        return true;
    } else {
        return false;
    }
}

bool Ellipse::isCircle() {
    return a == b;
}

void Ellipse::printFocalPoints() {
    double b1_x = 0, b1_y = 0, b2_x = 0, b2_y = 0;
    if (a > b) {
        double c = std::sqrt(a * a - b * b);

        b1_x = center[0] - c;
        b1_y = center[1];

        b2_x = center[0] + c;
        b2_y = center[1];
    } else if (a < b) {
        double c = std::sqrt(a * a - b * b);

        b1_x = center[0];
        b1_y = center[1] - c;

        b2_x = center[0];
        b2_y = center[1] + c;
    } else {
        b1_x = center[0];
        b1_y = center[0];

        b2_x = center[0];
        b2_y = center[0];
    }

    std::cout << "b1 = (" << b1_x << ", " << b1_y << "), ";
    std::cout << "b2 = (" << b2_x << ", " << b2_y << ")" << std::endl;
}

double Ellipse::getEccentricity() {
    double min, max;
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    return std::sqrt(1 - (min / max) * (min / max));
}