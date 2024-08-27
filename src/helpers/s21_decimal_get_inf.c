#include "../s21_decimal.h"

s21_decimal s21_decimal_get_inf(void) {
    s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
    return result;
}