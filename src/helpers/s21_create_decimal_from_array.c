#include "../s21_decimal.h"

s21_decimal s21_create_decimal_from_array(int bit0, int bit1, int bit2, int bit3){
    s21_decimal decimal;
    decimal.bits[0] = bit0;
    decimal.bits[1] = bit1;
    decimal.bits[2] = bit2;
    decimal.bits[3] = bit3;
    return decimal;
}