#include <stdio.h>

int main() {
    double x1 = 0;
    double x2 = 0;
    double tmp = 0;

    printf("Unsorted input:\n");
    printf("  x1=");
    scanf("%lf", &x1);
    printf("  x2=");
    scanf("%lf", &x2);

    if (x1 > x2) {
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    printf("Sorted output (ascending order):\n");
    printf("  x1=%f\n", x1);
    printf("  x2=%f\n", x2);

    return 1;
}