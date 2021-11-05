#include <stdio.h>

int main() {
    int a = 200;
    int b = 110;
    int tmp = 0;

    printf("gcd(%d,%d)=",a,b);

    while (b != 0) {
        tmp = a%b;
        a = b;
        b = tmp;
    }

    printf("%d\n",a);

    return 0;
}