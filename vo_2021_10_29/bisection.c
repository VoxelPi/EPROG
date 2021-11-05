#include <stdio.h>

double f(double x) {
    return x*x + 1 / (2 + x) - 2;
}

double bisection(double a, double b, double tol){
    double fa = f(a);
    double m = 0.5*(a+b);
    double fm = 0;

    while (b - a > 2*tol) {
        m = 0.5*(a+b);
        fm = f(m);
        if (fa*fm <= 0) {
            b = m;
        } else {
            a = m;
            fa = fm;
        }
    }
    return m;
}

int main() {
    double a = 0;
    double b = 10;
    double tol = 1e-12;
    double x = bisection(a, b, tol);

    printf("Approximate zero of the function x=%g\n",x);
    printf("Function value f(x)=%g\n",f(x));

    return 0;
}