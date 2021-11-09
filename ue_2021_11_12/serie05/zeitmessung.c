/*
 * Aufgabe 5.8
 * Peter Smek, 09.11.2021
 */

#include <stdio.h>
#include <time.h>

double time_a2(int N) {
    clock_t t_start = clock();

    double a_n = 0;
    for (int n = 0; n <= N; ++n) {
        a_n += 1.0 / ((n + 1) * (n + 1));
    }

    double a_n2 = a_n * a_n;

    clock_t t_runtime = clock() - t_start;
    //printf("a_n = %f, a_n² = %f", a_n, a_n2);
    return t_runtime / (double)CLOCKS_PER_SEC;
}
 
double time_b(int N) {
    clock_t t_start = clock();

    double b_n = 0;
    for (int n = 0; n < N; ++n) {
        for (int k = 0; k < n; ++k) {
            b_n += 1.0 / ((k + 1) * (k + 1) * (n - k + 1) * (n - k + 1));
        }
    }

    clock_t t_runtime = clock() - t_start;
    //printf("a_n = %f", b_n);
    return t_runtime / (double)CLOCKS_PER_SEC;
}

int main() {
    printf("   N   │     (a_n)²    │         b_n\n");
    printf("━━━━━━━┿━━━━━━━━━━━━━━━┿━━━━━━━━━━━━━━━\n");
    int N = 1;
    for (int i = 0; i <= 5; ++i) {
        printf("%7d│%15f│%15f\n", N, time_a2(N), time_b(N));
        N *= 10;
    }
    return 0;
}