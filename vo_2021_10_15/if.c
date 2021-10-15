#include <stdio.h>

int main() {
    int x = 0;
    printf("Input= x=");
    scanf("%d", &x);

    if (x < 0) {
        printf("x=%d is negative\n", x);
    }

    if (x > 0) {
        printf("x=%d is positive\n", x);
    }

    return 0;
}