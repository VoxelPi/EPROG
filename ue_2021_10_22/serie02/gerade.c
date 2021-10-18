#include <stdio.h>

int main() {

    double m = 0, q = 0;

    do {
        printf("m = ");
        scanf("%lf", &m);
    } while (!m);

    printf("q = ");
    scanf("%lf", &q);

    double x = -q / m; // m*x + q = 0

    printf("line intersects the x axis at (x=%f, y=0)\n", x);

    return 0;
}
