#include "../inc/benchmark.h"

#define R     "\033[1;0m"
#define CYAN  "\033[1;36m"



int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main (void)
{
    int runs;
    bm_data_t data;
    double results[3];

    runs = 100;
    bm_init (data);
    for (int n = 0; n < runs; n++) {
        bm_start (data);
        fibonacci (30);
        bm_stop (data);
    }

    bm_print_results(data, "fibonacci (30)");

    results[0] = bm_get_secs (data);
    results[1] = bm_get_msecs (data);
    results[2] = bm_get_usecs (data);

    for (int i = 0; i < 3; i++) {
        printf ("results[%d]: %f\n", i, results[i]);
    }

    puts("");

    return 0;
}
