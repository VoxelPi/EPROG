#include <stdio.h>

int main() {
    int counter = 5;

    do {
        printf("%d ", counter);
        // counter = counter - 1;
    } while (--counter > 0);
    printf("\n");

    return 0;    
}