// #include "../s21_decimal.h"

void s21_set_decimal_zero(s21_decimal *value) {
    for (int i = 0; i<4; i++) {
        value->bits[i] = 0x00000000;
    }
}

void s21_set_big_decimal_zero(s21_big_decimal *value){
    s21_set_decimal_zero(&(value->decimal[0]));
    s21_set_decimal_zero(&(value->decimal[1]));
}