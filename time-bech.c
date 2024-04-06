#include <time.h>
#include <stdio.h>
#include <stdint.h>

#define MILLION 1000000
#define BILLION 1000000000

int main(void)
{
    struct timespec start, end;
    int64_t total_nanos = 0;

    // Start the timer
    if (clock_gettime(CLOCK_MONOTONIC_RAW, &start) == -1) {
        perror("clock_gettime");
        return 1;
    }

    // Measure the time for the loop
    for (int i = 0; i < MILLION; i++)
    {
        // Record the time after each clock_gettime call
        if (clock_gettime(CLOCK_MONOTONIC_RAW, &end) == -1) {
            perror("clock_gettime");
            return 1;
        }

        // Calculate the elapsed time and add it to the total
        total_nanos += (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);

        // Update the start time for the next iteration
        start = end;
    }

    // Convert total nanoseconds to seconds
    double seconds = (double)total_nanos / (double)BILLION;

    // Print the total time taken by all clock_gettime calls
    printf("A small time benchmark by MojArch\n\n1 million clock_gettime calls took: %.9f seconds\n", seconds);

    return 0;
}
