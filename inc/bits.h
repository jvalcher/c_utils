/*
    Bitwise library
    --------
    - Functions:

        print_bits (variable, num_bytes)

    - Example usage:

        int n = 123456789;
        print_bits(n, sizeof(n));   // => 00000111 01011011 11001101 00010101
*/
#ifndef BITS_H
#define BITS_H

#include <stdio.h>


/*
    Print bits in groups of 8 for <variable> with <num_bytes>
*/
#define print_bits(variable,num_bytes) do {          \
    int bits = num_bytes * 8;                        \
    for (int i = 1; i <= bits; i++) {                \
        printf("%d", (variable >> (bits - i) & 1));  \
        if (i % 8 == 0)                              \
            printf(" ");                             \
    }                                                \
    printf("\n");                                    \
} while (0)


#endif
