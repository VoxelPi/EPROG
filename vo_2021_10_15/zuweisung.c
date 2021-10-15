# include <stdio.h>

int main() {
    int x = 1;
    int y = 2;

    int tmp = 0;

    printf("a) x=%d, y=%d, tmp=%d\n", x, y, tmp);

    tmp = x;
    x = y;
    y = tmp;

    printf("b) x=%d, y=%d, tmp=%d\n", x, y, tmp);

    return 0;
}