#include "../s21_decimal.h"

void s21_set_decimal_sign(s21_decimal * value, int sign) {
s21_set_decimal_bit    if (sign == 0) value->bits[3] &= s21_plus;
}