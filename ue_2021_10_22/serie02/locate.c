#include <stdio.h>

int main() {

    double L = 0; // Square
    double x = 0, y = 0; // Point

    do {
        printf("L = ");
        scanf("%lf", &L);
    } while (L <= 0);

    printf("x = ");
    scanf("%lf", &x);

    printf("y = ");
    scanf("%lf", &y);

    if (x < 0 || x > L || y < 0 || y > L) {
        printf("Point lies outside of the square.\n");
    } else if (x == 0 || x == L || y == 0 || y == L) {
        printf("Point lies on the edge of the square.\n");
    } else {
        printf("Point lies inside the square.\n");
    }

    return 0;
}
