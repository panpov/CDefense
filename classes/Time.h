#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <sys/time.h>
#include <time.h>

// CITE: Casual Coder (https://www.youtube.com/watch?v=O2Zr9aUrYfo&ab_channel=CasualCoder)
// DESC: Explained how to make game run according to a timeout value instead of key presses

class Time {
public:
    static time_t milliseconds();
};

#endif // TIME_H