#include "../inc/unit_test.h"


void test_ints (void)
{
    int x = 7;
    int y = 19;

    test_init();

    test_cond (x == 7, "\'%d\' is not equal to 7", x);
    test_cond (y != 19, "\'%d\' is equal to 19", y);

    test_results();
}

void test_strs (void)
{
    const char* str1 = "Hello, world!";
    const char* str2 = "Hello, world!";
    const char* str3 = "Hello there, good looking!";

    test_init();

    test_strs_eq (str1, str2, "\'%s\' is not equal to \'%s\'", str1, str2);
    test_strs_eq (str2, str3, "\'%s\' is not equal to \'%s\'", str1, str3);
    test_strs_neq (str1, str2, " ");
    test_strs_neq (str2, str3, " ");

    test_results();
}


/*******************/


// Initialize once globally in main() file
int passed = 0,
    failed = 0;

int main (void)
{
    puts("");

    test_ints();
    test_strs();

    puts("");

    return 0;
}
