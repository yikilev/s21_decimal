#include "../s21_decimal.h"

s21_decimal s21_get_zero_decimal(void){
    s21_decimal decimal;
    s21_set_decimal_zero(&decimal);
    return decimal;
}