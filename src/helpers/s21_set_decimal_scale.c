#include "../s21_decimal.h"

void s21_set_decimal_scale(s21_decimal *value, int scale){
    decimal_bit3 bit3;
    bit3.i = value->bits[3];
    bit3.parts.scale = scale;
    value->bits[3] = bit3.i;
}