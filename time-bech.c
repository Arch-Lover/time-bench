  1 #include <time.h>
  2 #include <stdio.h>
  3 #include <stdint.h>
  4 
  5 #define MILLION 1000000
  6 #define BILLION 1000000000
  7 //just small time benchmark
  8 
  9 int main(void)
 10 {
 11     struct timespec start, end;
 12     int64_t total_nanos = 0;
 13 
 14     // Start the timer
 15     clock_gettime(CLOCK_MONOTONIC_RAW, &start);
 16 
 17     // Measure the time for the loop
 18     for (int i = 0; i < MILLION; i++)
 19     {
 20         // Perform some operation here if needed
 21 
 22         // Record the time after each clock_gettime call
 23         clock_gettime(CLOCK_MONOTONIC_RAW, &end);
 24 
 25         // Calculate the elapsed time and add it to the total
 26         total_nanos += (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);
 27 
 28         // Update the start time for the next iteration
 29         start = end;
 30     }
 31 
 32     // Convert total nanoseconds to seconds
 33     double seconds = (double)total_nanos / (double)BILLION;
 34 
 35     // Print the total time taken by all clock_gettime calls
 36     printf("1 million clock_gettime calls took: %f seconds\n", seconds);
 37 
 38     return 0;
 39 }
