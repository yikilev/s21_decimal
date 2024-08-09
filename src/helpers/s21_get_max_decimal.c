#include "../s21_decimal.h"

s21_decimal s21_get_max_decimal(void) {
    s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

    return result;
}