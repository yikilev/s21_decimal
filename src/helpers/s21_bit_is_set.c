#include "../s21_decimal.h"

int s21_bit_is_set(s21_decimal value, int index){
    int code = 0;
    if (value.bits[index/bits_in_byte] &= (1U << (index%bits_in_byte))) code = 1;
    return code;
}