#include <stdio.h>
#include "../inc/benchmark.h"



int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main (void)
{
    bm_time_t   time;
    bm_result_t result;

    // seconds
    start (time);
    fibonacci (30);
    result = stop_sec (time);
        //
    printf ("Fibonacci time: " SEC " seconds\n", result);

    // milliseconds
    start (time);
    fibonacci (30);
    result = stop_msec (time);
        //
    printf ("Fibonacci time: " MSEC " milliseconds\n", result);

    // microseconds
    start (time);
    fibonacci (30);
    result = stop_usec (time);
        //
    printf ("Fibonacci time: " USEC " microseconds\n", result);

    return 0;
}
