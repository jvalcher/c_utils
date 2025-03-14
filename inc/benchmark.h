/*
    Benchmarking library
    --------
    - Calculates runtime averages in seconds, milliseconds, microseconds
    - Single header

    - Data types:

        bm_data_t

    - Functions:

        void bm_start (bm_data_t data)
        void bm_stop  (bm_data_t data)

        double bm_get_secs  (bm_data_t data)
        double bm_get_msecs (bm_data_t data)
        double bm_get_usecs (bm_data_t data)

        void bm_print_results (bm_data_t data, char* title)

    - Usage:

        bm_data_t data;
        double results[3];

        bm_init (data);

        for (int n = 0; n < 100; n++) {
            bm_start (data);
            fibonacci (30);
            bm_stop (data);
        }

        bm_print_results (data, "fibonacci (30)");

        results[0] = bm_get_secs (data);
        results[1] = bm_get_msecs (data);
        results[2] = bm_get_usecs (data);

    - Output:

        --------------------------
        fibonacci (30)  (100 runs)
        --------------------------
          seconds:       0.005334
          milliseconds:  5.334
          microseconds:  5334
*/
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <stdio.h>
#include <sys/time.h>

#define R       "\033[1;0m"         // reset to default
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m"
#define DIV     "--------------------------\n"



typedef struct bm_data {
    struct timeval start_time;
    int    count;
    double time_sec;
    double avg_time_sec;
    double avg_time_msec;
    double avg_time_usec;
} bm_data_t;



/*
    Initialize bm_data_t struct
*/
#define bm_init(data) ({ \
    data.count = 0; \
    data.time_sec = 0.0; \
    data.avg_time_sec = 0.0; \
    data.avg_time_msec = 0.0; \
    data.avg_time_usec = 0.0; \
})


/*
    Get start time
*/
#define bm_start(data) ({ \
    gettimeofday(&(data).start_time, ((void*)0) ); \
})


/*
    Get stop time and update average runtimes (seconds, milliseconds, microseconds)
*/
#define bm_stop(data) ({ \
\
    struct timeval start_time = (data).start_time; \
    struct timeval stop_time; \
    gettimeofday(&stop_time, ((void*)0) ); \
\
    data.time_sec = (stop_time.tv_sec - start_time.tv_sec) + \
        ((stop_time.tv_usec - start_time.tv_usec) / 1000000.0); \
\
    data.count += 1; \
    data.avg_time_sec = data.avg_time_sec + ((data.time_sec - data.avg_time_sec) / data.count); \
    data.avg_time_msec = data.avg_time_sec * 1000; \
    data.avg_time_usec = data.avg_time_sec * 1000000; \
})


/*
    Print formatted results
*/
#define  SEC "%.6f"
#define MSEC "%.3f"
#define USEC "%.f"

#define bm_print_results(data,msg) ({ \
    printf ("\n" DIV CYAN "%s" R "  (" YELLOW "%d" R " runs)\n" DIV \
            "  seconds:       " SEC  "\n" \
            "  milliseconds:  " MSEC "\n" \
            "  microseconds:  " USEC "\n\n", \
        msg, data.count, data.avg_time_sec, data.avg_time_msec, data.avg_time_usec); \
})


/*
    Get average runtime values
*/
#define bm_get_secs(data)  (data).avg_time_sec

#define bm_get_msecs(data) (data).avg_time_msec

#define bm_get_usecs(data) (data).avg_time_usec


#endif

