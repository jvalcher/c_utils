#include <stdio.h>

#include "../inc/bits.h"

int
main (void)
{
    char c = 'A';
    printf("\n%c: ", c);
    print_bits(c, 1);

    int n = 123456789;
    printf("%d: ", n);
    print_bits(n, sizeof(n));
    puts("");
}
