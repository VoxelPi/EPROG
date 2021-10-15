#include <stdio.h>

int main() {
    int var1 = -5;
    double var2 = 1e-32;
    int var3 = 5;

    if (var1 >= 0) {
        printf("var1 >= 0\n");
    } else {
        printf("var1 < 0\n");
    }

    if (var2) {
        printf("var2 != 0, ie. cond. is true\n");
    } else {
        printf("var 2 == 0, i.e. cond. is false\n");
    }

    if ((var1 < var2) && (var2 < var3)) {
        printf("var2 lies between the others\n");
    }

    return 0;
}