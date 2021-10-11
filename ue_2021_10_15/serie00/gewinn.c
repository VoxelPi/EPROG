#include <stdio.h>

int main()
{
    double x = 0;
    int n = 0;

    printf("Money: ");
    scanf("%lf", &x);

    printf("Friends: ");
    scanf("%d", &n);

    // Calculate money / friend
    double y = x / n;
    printf("Money / Friend: %lf\n", y);
}
