#include <stdio.h>

int main() {
    double r = 0;
    double x1 = 0;
    double x2 = 0;
    double z1 = 0;
    double z2 = 0;
    double dist2 = 0;

    printf("Radius of the circle r=");
    scanf("%lf", &r);

    printf("Center of the circle: x = (x1,x2)\n");
    printf(" x1=");
    scanf("%lf",&x1);
    printf(" x2=");
    scanf("%lf",&x2);
    printf("Point in the plane: z = (z1,z2)\n");
    printf(" z1=");
    scanf("%lf",&z1);
    printf(" z2=");
    scanf("%lf",&z2);

    dist2 = (x1 - z1) * (x1 - z1) + (x2 - z2) * (x2 - z2);
    if (dist2 < r * r) {
        printf("z is inside the circle\n");
    } else {
        if (dist2 > r*r) {
            printf("z is outside of the circle\n");
        } else {
            printf("z lies on the boundary of the circle\n");
        }
    }

    return 0;
}