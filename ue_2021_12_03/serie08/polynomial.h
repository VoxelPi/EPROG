#ifndef INCLUDE_POLYNOMIAL__
#define INCLUDE_POLYNOMIAL__

/**
 * Polynomial data type.
 */ 
typedef struct _Polynomial_ {
    int degree;
    double *coefficients;
} Polynomial;

/**
 * Creates a new polynomial.
 */ 
Polynomial* newPoly(int degree);

/**
 * Deletes the given polynomial.
 */ 
Polynomial* delPoly(Polynomial *polynomial);

/**
 * Returns the degree of the given polynomial.
 */
int getPolyDegree(Polynomial *polynomial);

/**
 * Returns the i_th coefficient of the given polynomial.
 */ 
double getPolyCoefficient(Polynomial *polynomial, int i_coefficient);

/**
 * Sets the i_th coefficient of the given polynomial to value.
 */ 
void setPolyCoefficient(Polynomial *polynomial, int i_coefficient, double value);

Polynomial* scanPoly();

void printPoly(Polynomial *polynomial);

#endif