#include <stdio.h>

int main() {
    int result = 0;

    int a = 3;
    int b = 2;
    int c = 1;

    result = (a > b > c);
    printf("a) result=%d\n", result);

    result = (a > b) && (b > c);
    printf("b) result=%d\n", result);

    return 0;
}