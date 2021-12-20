#include "vector.hpp"

/**
 * (EPROG VO 242-244) 
 */ 

Vector::Vector() {
    dim = 0;
    coeff = (double*) 0;
    std::cout << "allocate empty vector" << "\n";
}

Vector::Vector(int dim, double init) {
    assert(dim>0);
    this->dim = dim;
    coeff = (double*) malloc(dim*sizeof(double));
    assert(coeff != (double*) 0);
    for (int j=0; j<dim; ++j) {
        coeff[j] = init;
    }
    std::cout << "allocate vector, length " << dim << "\n";
}

Vector::~Vector() {
    if (dim > 0) {
        free(coeff);
    }
    std::cout << "free vector, length " << dim << "\n";
}

Vector::Vector(const Vector& rhs) {
    dim = rhs.dim;
    if (dim == 0) {
        coeff = (double*) 0;
    }
    else {
        // copy coefficient vector
        coeff = (double*) malloc(dim*sizeof(double));
        for (int j=0; j<dim; ++j) {
            coeff[j] = rhs.coeff[j];
        }
    }
    std::cout << "copy constructor, length " << dim << "\n";
}

Vector& Vector::operator=(const Vector& rhs) {
    // check for self-assignemnt
    if (this != &rhs) {
        // if necessary, free memory and allocate new memory
        if (dim != rhs.dim) {
            free(coeff);
            dim = rhs.dim;
            coeff = (double*) malloc(dim*sizeof(double));
        }
        // copy coefficient vector
        for (int j=0; j<dim; ++j) {
            coeff[j] = rhs.coeff[j];
        }
    }
    std::cout << "assignment, length " << dim << "\n";
    // return self-reference for assignment chains
    return *this;
}

int Vector::size() const {
    return dim;
}

void Vector::set(int k, double value) {
    assert(k>=0 && k<dim);
    coeff[k] = value;
}

double Vector::get(int k) const {
    assert(k>=0 && k<dim);
    return coeff[k];
}

double Vector::norm() const {
    double norm = 0;
    for (int j=0; j<dim; ++j) {
        norm = norm + coeff[j]*coeff[j];
    }
    return sqrt(norm);
}
