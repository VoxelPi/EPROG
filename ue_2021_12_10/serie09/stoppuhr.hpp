#ifndef INCLUDE_STOPPUHR__
#define INCLUDE_STOPPUHR__

#include "time.h"

class Stoppuhr {
private:
    int state;
    clock_t start;
    clock_t stop;

public:
    void pushButtonStartStop();
    void pushButtonReset();

    void printElapsedTime();
};

#endif