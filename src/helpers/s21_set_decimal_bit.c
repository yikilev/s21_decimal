#include "../s21_decimal.h"

void set_decimal_bit(s21_decimal *value, int index) {
    value->bits[index/bits_in_byte] |= (1U << (index%bits_in_byte));
}
