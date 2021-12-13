#ifndef INCLUDE_MATRIX__
#define INCLUDE_MATRIX__

class Matrix
{
private:
    int n;
    double *coeff;
public:
    Matrix();
    Matrix(int n, double init = 0.0);
    ~Matrix();

    // return matrix dimension
    int size();

    // read and write matrix coefficients.
    double get(int i, int j);
    void set(int i, int j, double value);
};


#endif