/**
 * Aufgabe 9.8
 */

#include <iostream>

#include "stoppuhr.hpp"

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
    Stoppuhr stoppuhr;

    // Test methods.
    stoppuhr.printElapsedTime();
    stoppuhr.pushButtonStartStop();
    stoppuhr.printElapsedTime();
    stoppuhr.pushButtonStartStop();
    stoppuhr.printElapsedTime();

    // Measure time to execute function.
    std::cout << std::endl << "Starting measurement" << std::endl;
    stoppuhr.pushButtonReset();
    stoppuhr.pushButtonStartStop();

    // Function to measure.
    time_b(100000);

    stoppuhr.pushButtonStartStop();
    stoppuhr.printElapsedTime();
    return 0;
}