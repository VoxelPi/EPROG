#include <stdio.h>

int main() {

    double a = 0, b = 0, c = 0;

    do {
        printf("a = ");
        scanf("%lf", &a);
    } while (a <= 0);

    do {
        printf("b = ");
        scanf("%lf", &b);
    } while (b <= 0);

    do {
        printf("c = ");
        scanf("%lf", &c);
    } while (c <= 0);

    int special = 0;

    // Check if triangle is valid.
    if (a + b < c || b + c < a || c + a < b) {
        printf("Impossible triangle.\n");

        // Skip further checks, because triangle is invalid.
        return 0;
    }

    // Check if triangle is one-dimensional.
    if (a + b == c || b + c == a || c + a == b) {
        printf("One-dimensional triangle.\n");
    }

    // Check if triangle is a equilateral triangle.
    if (a == b && b == c) {
        printf("Equilateral triangle.\n");
        special = 1;
    }

    // Check if triangle is a isosceles triangle. (gleichschenkliges)
    if (a == b || b == c || c == a) {
        printf("Isosceles triangle.\n");
        special = 1;
    }

    // Check if triangle is a right-angled triangle.
    if ((a*a + b*b == c*c) || (b*b + c*c == a*a) || (c*c + a*a == b*b)) {
        printf("Right-angled triangle.\n");
        special = 1;
    }

    // Else
    if (!special) {
        printf("Irregular triangle.\n");
    }

    return 0;
}
