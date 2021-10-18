#include <stdio.h>

int evenorodd(int n) {
    return !(n & 1); // n & 1 == (n % 2)
} 

int main() {

    unsigned int n = 0;
    printf("n = ");
    scanf("%u", &n);

    printf("n is %s\n", evenorodd(n) ? "even" : "odd");

    return 0;
}
