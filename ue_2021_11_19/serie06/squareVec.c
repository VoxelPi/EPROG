/*
 * Aufgabe 6.7
 * Peter Smek, 14.11.2021
 */

#include <stdio.h>

// int squareVec(double vec, int n) {
//     int j = 0;
//     for(j = 1, j < dim; --j) {
//         *vec[j] = &vec[j] * &vec[j];
//     }
//     return vec;
// }

void squareVec(double vec[], int n) {
    int j = 0;
    for(j = 0; j < n; ++j) {
        vec[j] = vec[j] * vec[j];
    }
}

int main() {
    double vec[3] = { -1.0, 2.0, 0.0 };
    int j = 0;

    squareVec(vec, 3);
    for(j = 0; j < 3; ++j) {
        printf("vec[%d] = %f ", j, vec[j]);
    }
    printf("\n");

    return 0;
}
