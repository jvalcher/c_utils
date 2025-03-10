#include <stdio.h>
#include "../inc/benchmark.h"

#define R     "\033[1;0m"
#define CYAN  "\033[1;36m"



int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main (void)
{
    int n, runs = 100;
    bm_data_t data;

    // seconds
    bm_init (data);
    for (n = 0; n < runs; n++) {
        start (data);
        fibonacci (30);
        stop_sec (data);
    }
    printf (CYAN " fibonacci" R "() averaged " SEC " seconds over %d runs\n",
        data.avg_time, runs);

    // milliseconds
    bm_init (data);
    for (n = 0; n < runs; n++) {
        start (data);
        fibonacci (30);
        stop_msec (data);
    }
    printf (CYAN " fibonacci" R "() averaged " MSEC " milliseconds over %d runs\n",
        data.avg_time, runs);

    // microseconds
    bm_init (data);
    for (n = 0; n < runs; n++) {
        start (data);
        fibonacci (30);
        stop_usec (data);
    }
    printf (CYAN " fibonacci" R "() averaged " USEC " microseconds over %d runs\n",
        data.avg_time, runs);

    return 0;
}
