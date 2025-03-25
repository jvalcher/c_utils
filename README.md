
# C Utilities

## Singler header libraries

### test.h
- __Description__:  Single header unit testing library
- __Example usage__:
```c
int passed = 0,
    failed = 0;
test_init();
test_cond     (x > 5, "Test failed: \'%d\' is not greater than 5", x);
test_strs_eq  (str1, str2, "\'%s\' not equal to \'%s\'", str1, str2);
test_strs_neq (str2, str3, " ");
test_results();
```
- __Example output__:
<p align="center"><img margin-left="auto" src="./images/test.png"></p>

### benchmark.h
- __Description__:  Single header benchmarking library that calculates multi-run average in seconds, milliseconds, microseconds
- __Example usage__:
```c
bm_data_t data;
bm_init (data);
for (int n = 0; n < 100; n++) {
    bm_start (data);
    fibonacci (30);
    bm_stop (data);
}
bm_print_results (data, "fibonacci(30) x 100");
```
- __Example output__:
<p align="center"><img margin-left="auto" src="./images/benchmark.png"></p>

### bits.h
- __Description__:  Bitwise library
- __Example usage__:
```c
int n = 123456789;
print_bits(n, sizeof(n));
```
- __Example output__:
```bash
00000111 01011011 11001101 00010101
```

<br>
