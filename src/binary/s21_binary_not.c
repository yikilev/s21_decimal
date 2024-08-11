#include "../s21_decimal.h"
#include "../helpers/s21_bit_is_set.c"
#include "../helpers/s21_set_decimal_bit.c"
#include "../helpers/s21_set_decimal_zero.c"

s21_decimal s21_binary_not(s21_decimal value){
    for (int i = 2; i>=0; i--){
        // if (s21_bit_is_set(value,i)) {set_decimal_bit()}
        value.bits[i] = ~value.bits[i];
    }
    return value;
}



int main() {
    s21_decimal value;
    s21_set_decimal_zero(&value);
    value.bits[0] = 0x00000002;
    s21_binary_not(value);
    printf("bit1: %d %x", value.bits[])
    return 0;
}