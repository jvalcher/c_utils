#!/bin/bash

# Run all tests

CC () {
    gcc -g -Wall -Wextra $@
}


CC ./test_unit_test.c && ./a.out

