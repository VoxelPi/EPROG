#include "stoppuhr.hpp"

#include <iostream>
#include "cstdio"

void Stoppuhr::pushButtonStartStop() {
    if (state == 0) {
        start = clock();
        state = 1;
    } else if (state == 1) {
        stop = clock();
        state = 2;
    }
}

void Stoppuhr::pushButtonReset() {
    this->start = 0;
    this->stop = 0;
    this->state = 0;
}

void Stoppuhr::printElapsedTime() {
    // Measurement has not started yet.
    if (state == 0) {
        std::cout << "00:00:00.000" << std::endl;
        return;
    }

    // Calculated elapsed ticks.
    long long elapsed_ticks;
    if (state == 1) {
        // Measurement is still running.
        elapsed_ticks = clock() - start;
    } else {
        // Measurement is over.
        elapsed_ticks = stop - start;
    }

    int hours = elapsed_ticks / (CLOCKS_PER_SEC * 60 * 60);
    elapsed_ticks -= hours * CLOCKS_PER_SEC * 60 * 60; 

    int minutes = elapsed_ticks / (CLOCKS_PER_SEC * 60);
    elapsed_ticks -= minutes * CLOCKS_PER_SEC * 60;

    double seconds = (double)elapsed_ticks / CLOCKS_PER_SEC;

    printf("%02d:%02d:%06.3f\n", hours, minutes, seconds);
}