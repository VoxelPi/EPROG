#include <stdio.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort.
void sort(double *array, unsigned int n) {
    for (int i_end = 0; i_end < (n - 1); ++i_end) {
        for (int i = 0; i < (n - 1 - i_end); ++i) {
            if (array[i] > array[i + 1]) {
                swap(array + i, array + i + 1);
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
