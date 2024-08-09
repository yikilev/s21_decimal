#include "../s21_decimal.h"

s21_decimal s21_get_max_int(void) {
    // MAX_INT = 2147483647
    s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

    return result;
}