#include <stdio.h>

int main() {
    unsigned int n = 0;
    printf("n = ");
    scanf("%u", &n);

//                      (n & 1)
    printf("n is %s\n", (n % 2) ? "odd" : "even");

    return 0;
}

// int evenorodd(int n) {
//     return !(n & 1); // n & 1 == (n % 2)
// } 

// int main() {

//     unsigned int n = 0;
//     printf("n = ");
//     scanf("%u", &n);

//     printf("n is %s\n", evenorodd(n) ? "even" : "odd");

//     return 0;
// }
