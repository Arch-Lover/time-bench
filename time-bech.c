#include <time.h>
#include <stdio.h>
#include <stdint.h>

#define MILLION 1000000
#define BILLION 1000000000
//just small time benchmark

int main(void)
{
    struct timespec start, end;
    int64_t total_nanos = 0;

    // Start the timer
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    // Measure the time for the loop
    for (int i = 0; i < MILLION; i++)
    {
        // Perform some operation here if needed

        // Record the time after each clock_gettime call
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        // Calculate the elapsed time and add it to the total
        total_nanos += (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);

        // Update the start time for the next iteration
        start = end;
    }

    // Convert total nanoseconds to seconds
    double seconds = (double)total_nanos / (double)BILLION;

    // Print the total time taken by all clock_gettime calls
    printf("1 million clock_gettime calls took: %f seconds\n", seconds);

    return 0;
}
