#include <stdio.h>
#include <assert.h>

void test(int x, int y) {
    assert(x<y);
    printf("It holds x < y\n");
}

int main() {
    int x = 0;
    int y = 0;

    printf("x = ");
    scanf("%d",&x);

    printf("y = ");
    scanf("%d",&y);

    test(x,y);

    return 0;
}