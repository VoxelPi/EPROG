#include <stdio.h>

int main() {
    int x = 0;

    printf("Input x=");
    scanf("%d", &x);

    if (x > 0) {
        if (x % 2 != 0) {
            printf("x=%d is odd\n", x);
        } else {
            printf("x=%d is even\n", x);
        }
    } else {
        printf("Error: Input has to be positive!\n");
    }

    return 0;
}