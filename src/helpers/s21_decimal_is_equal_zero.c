#include "../s21_decimal.h"

int s21_decimal_is_equal_zero(s21_decimal value) {
    return value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0 && value.bits[3] == 0;
}