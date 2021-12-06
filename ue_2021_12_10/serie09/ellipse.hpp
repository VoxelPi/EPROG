#ifndef INCLUDE_ELLIPSE__
#define INCLUDE_ELLIPSE__

class Ellipse {
private:
    double center[2];
    double a;
    double b;

public:
    // Getters
    double getCenterX();
    double getCenterY();
    double getA();
    double getB();

    // Setters
    void setCenter(double x, double y);
    void setA(double a);
    void setB(double b);

    // Methods
    bool isInside(double x, double y);
    bool isCircle();
    void printFocalPoints();
    double getEccentricity();
};

#endif