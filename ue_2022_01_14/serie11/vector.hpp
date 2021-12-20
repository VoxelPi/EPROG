#ifndef INCLUDE_VECTOR_FIRST__
#define INCLUDE_VECTOR_FIRST__

#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

// The class Vector stores vectors in Rd. (EPROG VO 242-244) 

class Vector {
private:
  // dimension of the vector
  int dim;
  // dynamic coefficient vector
  double* coeff;
    
public:
  // constructors and destructor
  Vector();
  Vector(int dim, double init = 0);
  ~Vector();
    
  // return vector dimension
  int size();
  
  // read and write vector coefficients
  void set(int k, double value);
  double get(int k);
  
  // compute Euclidean norm
  double norm();
};

#endif
