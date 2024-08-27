#include "../s21_decimal.h"

int s21_get_decimal_non_zero_index(s21_decimal value){
    int index = -1;

    for (int i = 95; i>=0; i--){
        if (s21_bit_is_set(value,i)) {
            index = i;
            break;
            }
    }
    return index;
}