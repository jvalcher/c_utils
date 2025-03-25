
# C Utilities
Miscellaneous C language utilities
<br><br>

## Singler header libraries

### test.h
- Unit testing library
- Example usage:
```c
int passed = 0,
    failed = 0;
test_init();
test_cond     (y != 19, "\'y\' is equal to 19", y);
test_strs_eq  (str2, str3, "\'%s\' is not equal to \'%s\'", str2, str3);
test_strs_neq (str1, str2, " ");
test_results();
```
- Example output:
<p><img margin-left="auto" src="./images/test.png"></p>
<br>


### benchmark.h
- Calculates multi-run average in seconds, milliseconds, microseconds
- Example usage:
```c
bm_data_t data;
bm_init (data);
for (int n = 0; n < 100; n++) {
    bm_start (data);
    fibonacci (30);
    bm_stop (data);
}
bm_print_results (data, "fibonacci (30)");
```
- Example output:
<p><img margin-left="auto" src="./images/benchmark.png"></p>
<br>


### bits.h
- Print bits in variable with n bytes
- Example usage:
```c
int num1 = 123456789;
print_bits(num1, sizeof(num1));
```
- Example output:
```bash
00000111 01011011 11001101 00010101
```
<br>
