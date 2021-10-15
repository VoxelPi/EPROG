#include <stdio.h>

int main()
{
    double x = 0;
    int n = 0;

    printf("Money: ");
    scanf("%lf", &x);

    printf("Friends: ");
    scanf("%d", &n);

    // Calculate money / person
    double y = x / (n + 1);
    printf("Money / Person: %lf\n", y);
}
