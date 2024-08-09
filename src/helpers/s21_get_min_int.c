#include "../s21_decimal.h"

s21_decimal s21_decimal_get_int_min(void) {
    // MIN_INT = -2147483648
    s21_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};

    return result;
}