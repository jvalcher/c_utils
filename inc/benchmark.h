#ifndef BENCHMARK_H
#define BENCHMARK_H

/*
    Benchmarking library
    --------
    - Calculates runtime averages in seconds, milliseconds, microseconds
    - Single header

    - Data types:

        bm_data_t

    - Functions:

        void start     (bm_data_t data)
        void stop_sec  (bm_data_t data)
        void stop_msec (bm_data_t data)
        void stop_usec (bm_data_t data)

    - Format specifier strings:

        SEC, MSEC, USEC

    - Example usage:

int runs = 100;
bm_data_t data;

bm_init (data);
for (int n = 0; n < runs; n++) {
    start (data);
    fibonacci (30);
    stop_msec (data);
}

printf ("fibonacci(): averaged " MSEC " milliseconds over %d runs\n",
    data.avg_time, runs);
*/

#include <sys/time.h>


/*
    Data types
*/
typedef struct bm_data {
    struct timeval start_time;
    int    count;
    double time;
    double avg_time;
} bm_data_t;


/*
    Format specifier strings
*/
#define  SEC "%.6f"
#define MSEC "%.3f"
#define USEC "%.f"


/*
    Functions
*/

// Initialize bm_data_t struct
#define bm_init(data) ({ \
    data.count = 0; \
    data.time = 0.0; \
    data.avg_time = 0.0; \
})

// Get start time
#define start(data) ({ \
    gettimeofday(&(data).start_time, ((void*)0) ); \
})


// Calculate running average time
#define calc_avg_time(data) ({ \
    data.count += 1; \
    data.avg_time = data.avg_time + ((data.time - data.avg_time) / data.count); \
})

// Get stop time, calculate average runtime in seconds
#define stop_sec(data) ({ \
    struct timeval start_time = (data).start_time; \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
    data.time = (stop_time.tv_sec - start_time.tv_sec) + \
        ((stop_time.tv_usec - start_time.tv_usec) / 1000000.0); \
    calc_avg_time(data); \
})


// Get stop time, calculate average runtime in milliseconds
#define stop_msec(data) ({ \
    struct timeval start_time = data.start_time; \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
    data.time = ((stop_time.tv_sec - start_time.tv_sec) * 1000.0) + \
        ((stop_time.tv_usec - start_time.tv_usec) / 1000.0); \
    calc_avg_time(data); \
})


// Get stop time, calculate average runtime in microseconds
#define stop_usec(data) ({ \
    struct timeval start_time = data.start_time; \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
    data.time = (stop_time.tv_sec - start_time.tv_sec) * 1000000.0 + \
        stop_time.tv_usec - start_time.tv_usec; \
    calc_avg_time(data); \
})



#endif

