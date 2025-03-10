
/*
    Unit testing library
    ---------
    - Single header
    - Formatted info messages
    - Custom test failure messages

            test_strs_eq (str1, str2 "\'%s\' is not equal to \'%s\'", str1, str2);
            test_strs_eq (str1, str2, " ");     // single space for no message

    - Example usage:

        ------- tests.c -------

        #include "tests.h"
        #include "unit_test.h"

        void run_tests_01 ()
        {
            test_init();

            test_cond     (x > 5, "Test failed");
            test_strs_eq  (str1, str2, "...");
            test_strs_neq (str1, str2, "...");

            test_results();
        }

        ------- main.c -------

        #include "tests.h"

        int passed = 0,
            failed = 0;

        int main ()
        {
            run_tests_01();
            return 0;
        }
*/

#ifndef UNIT_TEST
#define UNIT_TEST

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define R       "\033[1;0m"         // reset to default
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m"
#define DIV     "---------------------\n"



// Initialize once in main() file
extern int passed;
extern int failed;


/*
    Reset statistics; print function and file header
    --------
    - Run at start of every test function
*/
#define test_init() ({\
\
    passed = 0; \
    failed = 0; \
\
    printf (\
        DIV CYAN "%s" R " :: " PURPLE "%s" R "()\n" DIV, \
        __FILE__, __func__ \
    ); \
})


/*
    Print test statistics
    --------
    - Run at the end of every test function
*/
#define test_results() ({ \
    printf (\
        "Passed: " GREEN "%d" R ",  Failed: " RED "%d\n" R "\n", \
        passed, failed \
    ); \
})



/*
    Print test failed message
    -------
    - Used by test functions below
    - Output:
        - Condition tested
        - Line number
        - Custom error message
    - Printed between test_init() and test_results() output
*/
#define print_test_failed(...) ({ \
    printf (CYAN "  Line " YELLOW "%d" R "  ", __LINE__); \
    printf (__VA_ARGS__); \
    printf ("\n"); \
})



/****************
  Test functions
 ****************/

#define FAIL printf("\t" RED "FAIL" R "  ")

/*
    Test conditional statement
*/
#define test_cond(condition, ...) ({ \
    if (!(condition)) { \
        FAIL; \
        printf("(%s)", #condition); \
        print_test_failed(__VA_ARGS__); \
        ++failed; \
    } else { \
        ++passed; \
    } \
})


/*
    Test if strings equal
*/
#define test_strs_eq(str1, str2, ...) ({ \
    if (strcmp((str1), (str2)) != 0) { \
        FAIL; \
        printf("(%s == %s)", #str1, #str2); \
        print_test_failed(__VA_ARGS__); \
        ++failed; \
    } else { \
        ++passed; \
    } \
})


/*
    Test if strings not equal
*/
#define test_strs_neq(str1, str2, ...) ({ \
    if (strcmp((str1), (str2)) == 0) { \
        FAIL; \
        printf("(%s != %s)", #str1, #str2); \
        print_test_failed(__VA_ARGS__); \
        ++failed; \
    } else { \
        ++passed; \
    } \
})


#endif

