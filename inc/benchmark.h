#ifndef BENCHMARK_H
#define BENCHMARK_H

/*
    Benchmarking library
    --------
    Data types:

        bm_time_t    (struct timeval)
        bm_result_t  (double)

    Functions:

        void        start     (bm_time_t time)
        bm_result_t stop_sec  (bm_time_t time)
        bm_result_t stop_msec (bm_time_t time)
        bm_result_t stop_usec (bm_time_t time)

    Format specifier strings:

        SEC, MSEC, USEC

    Example usage:

        bm_time_t   time;
        bm_result_t result;

        start (time);
        fibonacci (30);
        result = stop_msec (time);

        printf ("Fibonacci time: " MSEC " milliseconds\n", result);
*/

#include <sys/time.h>


/*
    Data types
*/
typedef struct timeval  bm_time_t;
typedef double          bm_result_t;


/*
    Format specifier strings
*/
#define  SEC "%.6f"
#define MSEC "%.3f"
#define USEC "%.f"


/*
    Functions
*/

// Get start time
#define start(start_time) ({ \
    gettimeofday(&start_time, ((void*)0) ); \
})


// Get stop time, return result in seconds
#define stop_sec(start_time) ({ \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
    (stop_time.tv_sec - start_time.tv_sec) + \
        ((stop_time.tv_usec - start_time.tv_usec) / 1000000.0); \
})


// Get stop time, return result in milliseconds
#define stop_msec(start_time) ({ \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
    ((stop_time.tv_sec - start_time.tv_sec) * 1000.0) + \
        ((stop_time.tv_usec - start_time.tv_usec) / 1000.0); \
})


// Get stop time, return result in microseconds
#define stop_usec(start_time) ({ \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
    (stop_time.tv_sec - start_time.tv_sec) * 1000000.0 + \
        stop_time.tv_usec - start_time.tv_usec; \
})



#endif

