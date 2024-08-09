#include "../s21_decimal.h"

int s21_get_sign(s21_decimal value) {
    int sign = 0;
    value.bits[3] = value.bits[3] & s21_minus;
    if (value.bits[3] == s21_minus) {
        sign = 1;
    } else {
        sign = 0;
    }
    return sign;
}
