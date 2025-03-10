
/*
    Unit testing macro functions
    ---------
    - Formatted info messages
    - Custom test failure messages

            test_strs_eq (str1, str2 "\'%s\' is not equal to \'%s\'", str1, str2);
            test_strs_eq (str1, str2, " ");     // single space for no message

    - Example usage:

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

        ------------------
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
    Initialize test statistics; print function and file header
    --------
    - Run at start of every test function
*/
#define test_init() \
do { \
    passed = 0; \
    failed = 0; \
\
    printf (\
        DIV CYAN "%s" R " :: " PURPLE "%s" R "()\n" DIV, \
        __FILE__, __func__ \
    ); \
\
} while (0)


/*
    Print test statistics
    --------
    - Run at the end of every test function
*/
#define test_results() \
do { \
    printf (\
        "Passed: " GREEN "%d" R ",  Failed: " RED "%d\n" R "\n", \
        passed, failed \
    ); \
} while (0)



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
#define print_test_failed(...) \
do { \
    printf (CYAN "  Line " YELLOW "%d" R "  ", __LINE__); \
    printf (__VA_ARGS__); \
    printf ("\n"); \
} while (0)



/****************
  Test functions
 ****************/

#define FAIL printf("\t" RED "FAIL" R "  ")

/*
    Test conditional statement
*/
#define test_cond(condition, ...) \
do { \
    if (!(condition)) { \
        FAIL; \
        printf("(%s)", #condition); \
        print_test_failed(__VA_ARGS__); \
        ++failed; \
    } else { \
        ++passed; \
    } \
} while (0)


/*
    Test if strings equal
*/
#define test_strs_eq(str1, str2, ...) \
do { \
    if (strcmp((str1), (str2)) != 0) { \
        FAIL; \
        printf("(%s == %s)", #str1, #str2); \
        print_test_failed(__VA_ARGS__); \
        ++failed; \
    } else { \
        ++passed; \
    } \
} while (0)


/*
    Test if strings not equal
*/
#define test_strs_neq(str1, str2, ...) \
do { \
    if (strcmp((str1), (str2)) == 0) { \
        FAIL; \
        printf("(%s != %s)", #str1, #str2); \
        print_test_failed(__VA_ARGS__); \
        ++failed; \
    } else { \
        ++passed; \
    } \
} while (0)


#endif

