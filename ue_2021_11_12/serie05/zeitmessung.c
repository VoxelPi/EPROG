/*
 * Aufgabe 5.8
 * Peter Smek, 09.11.2021
 */

#include <stdio.h>
#include <time.h>

/**
 * Measures the time to calculate (a_N)².
 */ 
double time_a2(int N) {
    // Get start time.
    clock_t t_start = clock();

    // Calculate a_n.
    double a_n = 0;
    for (int n = 0; n <= N; ++n) {
        a_n += 1.0 / ((n + 1) * (n + 1));
    }

    double a_n2 = a_n * a_n;

    // Get current time and calculate runtime.
    clock_t t_runtime = clock() - t_start;
    //printf("a_n = %f, a_n² = %f", a_n, a_n2);
    return t_runtime / (double)CLOCKS_PER_SEC;
}
 
/**
 * Measures the time to calculate b_N.
 */ 
double time_b(int N) {
    // Get start time.
    clock_t t_start = clock();

    // Calculate b_n.
    double b_n = 0;
    for (int n = 0; n < N; ++n) {
        for (int k = 0; k < n; ++k) {
            b_n += 1.0 / ((k + 1) * (k + 1) * (n - k + 1) * (n - k + 1));
        }
    }

    // Get current time and calculate runtime.
    clock_t t_runtime = clock() - t_start;
    //printf("a_n = %f", b_n);
    return t_runtime / (double)CLOCKS_PER_SEC;
}

int main() {
    printf("   N   │      (a_n)²     │          b_n\n");
    printf("━━━━━━━┿━━━━━━━━━━━━━━━━━┿━━━━━━━━━━━━━━━━━\n");
    int N = 1;
    for (int i = 0; i <= 5; ++i) {
        printf("%7d│%15fs │%15fs\n", N, time_a2(N), time_b(N));
        N *= 10;
    }
    return 0;
}