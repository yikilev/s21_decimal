#include "../s21_decimal.h"

s21_decimal s21_abs(s21_decimal value) {
    s21_decimal result = value;
    s21_set_decimal_sign(&result, 0);
    return result;
}