#include "Time.h"

/**
* @brief Gets the current time in milliseconds
* @return the current time in milliseconds
*/
time_t Time::milliseconds() {
    // Create time value object
    struct timeval curr_time;

    // Get current time of day in microseconds
    gettimeofday(&curr_time, nullptr);

    // Convert current time into milliseconds and return
    return (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
}