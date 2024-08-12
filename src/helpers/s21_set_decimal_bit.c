#include "../s21_decimal.h"

void s21_set_decimal_bit(s21_decimal *value, int index) {
    value->bits[index/bits_in_byte] |= (1U << (index%bits_in_byte));
}

void s21_set_decimal_bit_zero(s21_decimal *value, int index){
    value->bits[index/bits_in_byte] &= ~(1U<<(index%bits_in_byte));
}
