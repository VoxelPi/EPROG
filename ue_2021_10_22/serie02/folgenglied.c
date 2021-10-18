#include <stdio.h>

int main() {

    unsigned int n = 0;
    printf("n = ");
    scanf("%u", &n);

    double a_n = 1.0 / (n + 2);

    printf("a_n = %f\n", a_n);

    return 0;
}
