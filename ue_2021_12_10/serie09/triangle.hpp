#ifndef INCLUDE_TRIANGLE__
#define INCLUDE_TRIANGLE__

#include <cmath>

// The class Triangle stores a triangle in R2

class Triangle {
private:
  // the coordinates of the nodes
  double x[2];
  double y[2];
  double z[2];
    
public:
  // define or change the nodes of a triangle,
  // e.g., triangle.setX(x1,x2) writes the
  // coordinates of the node x of the triangle
  void setX(double, double);
  void setY(double, double);
  void setZ(double, double);
    
  // return the area of the triangle
  double getArea();
  double getPerimeter();
  bool isEquilateral();
};

#endif
