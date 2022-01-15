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
    // constructors, destructor, assigment operator
    Vector();
    Vector(int dim, double init = 0);
    Vector(const Vector& rhs);
    ~Vector();
    Vector& operator=(const Vector& rhs);
    
    // return vector dimension
    int size() const;
    
    // read and write vector coefficients
    void set(int k, double value);
    double get(int k) const;
    
    // compute Euclidean norm
    double norm() const;
};

#endif
