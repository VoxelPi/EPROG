#ifndef INCLUDE_POLYNOMIAL__
#define INCLUDE_POLYNOMIAL__

/**
 * cDouble data type.
 */ 
typedef struct _cDouble_ {
    double a;
    double b;
} cDouble;

/**
 * Creates a new complex number equals to a + i*b.
 */ 
cDouble* newCDouble(double a, double b);

/**
 * Deletes the given complex number.
 */ 
cDouble* delCDouble(cDouble *z);

/**
 * Sets the real part of the given complex number z to a.
 */ 
void setCDoubleReal(cDouble* z, double a);

/**
 * Returns the real part of the given complex number z.
 */ 
double getCDoubleReal(cDouble* z);

/**
 * Sets the imaginary part of the given complex number z to i * b.
 */ 
void setCDoubleImag(cDouble* z, double b);

/**
 * Returns the imaginary part of the given complex number z.
 */ 
double getCDoubleImag(cDouble* z);

/**
 * Reads a complex number from stdin.
 */ 
cDouble* scanCDouble();

/**
 * Prints the complex number z to stdout.
 */ 
void printCDouble(cDouble *z);

#endif