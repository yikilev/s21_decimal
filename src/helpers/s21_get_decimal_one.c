#include "../s21_decimal.h"

s21_decimal s21_get_decimal_one(void) {
    s21_decimal result = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
    return result;
}