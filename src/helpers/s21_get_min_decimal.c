#include "../s21_decimal.h"

s21_decimal s21_get_min_decimal(void) {
    s21_decimal result = {{0x1, 0x0, 0x0, 0x001C0000}};

    return result;
}