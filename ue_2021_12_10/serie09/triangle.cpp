#include "triangle.hpp"

void Triangle::setX(double x0, double x1) {
    x[0] = x0;
    x[1] = x1;
}

void Triangle::setY(double y0, double y1) {
    y[0] = y0;
    y[1] = y1;
}

void Triangle::setZ(double z0, double z1) {
    z[0] = z0;
    z[1] = z1;
}

double Triangle::getArea() {
    return 0.5 * fabs((y[0] - x[0]) * (z[1] - x[1]) - (z[0] - x[0]) * (y[1] - x[1]));
}

double Triangle::getPerimeter() {
    double side_xy = std::sqrt((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
    double side_yz = std::sqrt((y[0] - z[0]) * (y[0] - z[0]) + (y[1] - z[1]) * (y[1] - z[1]));
    double side_zx = std::sqrt((z[0] - x[0]) * (z[0] - x[0]) + (z[1] - x[1]) * (z[1] - x[1]));

    return side_xy + side_yz + side_zx;
}

bool Triangle::isEquilateral() {
    double side_xy = std::sqrt((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
    double side_yz = std::sqrt((y[0] - z[0]) * (y[0] - z[0]) + (y[1] - z[1]) * (y[1] - z[1]));
    double side_zx = std::sqrt((z[0] - x[0]) * (z[0] - x[0]) + (z[1] - x[1]) * (z[1] - x[1]));

    return std::fabs(side_xy - side_yz) <= 1e-6 && std::fabs(side_yz - side_zx) <= 1e-6;
}