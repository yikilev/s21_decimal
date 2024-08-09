#include "../s21_decimal.h"

s21_decimal s21_create_decimal_from_data(int sign, int scale, int bit2, int bit1, int bit0){
    s21_decimal decimal;
    s21_set_decimal_zero(&decimal);
    decimal.bits[0] = bit0;
    decimal.bits[1] = bit1;
    decimal.bits[2] = bit2;
    s21_set_decimal_sign(&decimal,sign);
    s21_set_decimal_scale(&decimal,scale);

    return decimal;
}