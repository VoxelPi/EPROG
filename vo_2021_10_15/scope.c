#include <stdio.h>

int main() {
    int x = 7;
    printf("a) %d\n", x);
    x = 9;
    printf("b) %d\n", x);
    {
        int x = 17;
        printf("c) %d\n", x);
    }
    printf("d) %d\n", x);

    return 0;
}