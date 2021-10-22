#include <stdio.h>

// Bubble sort.
void sort(double *array, unsigned int n) {
    for (int i_end = 0; i_end < (n - 1); ++i_end) {
        for (int i = 0; i < (n - 1 - i_end); ++i) {
            if (array[i] > array[i + 1]) {
                // Swap
                double temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main() {

    double x = 0, y = 0, z = 0;

    printf("x = ");
    scanf("%lf", &x);

    printf("y = ");
    scanf("%lf", &y);

    printf("z = ");
    scanf("%lf", &z);

    double numbers[] = { x, y, z};
    sort(numbers, 3);
    printf("%f %f %f\n", numbers[2], numbers[1], numbers[0]);

    return 0;
}
