#include "s21_decimal.h"

void s21_set_decimal_sign(s21_decimal * value, int sign) {
    if (sign == 1) value->bits[3] |= s21_minus;
    if (sign == 0) value->bits[3] &= s21_plus;
}