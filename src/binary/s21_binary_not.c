#include "../helpers/s21_bit_is_set.c"
#include "../helpers/s21_set_decimal_bit.c"
#include "../helpers/s21_set_decimal_zero.c"
#include "../s21_decimal.h"

s21_decimal s21_binary_not(s21_decimal *value) {
  // s21_decimal value_copy;
  // for (int i = 0; i <= 3; i++) {
  //   value_copy.bits[i] = value.bits[i];
  // }
  for (int i = 95; i >= 0; i--) {
    if (s21_bit_is_set(*value, i)) {
      s21_set_decimal_bit_zero(value, i);
    } else {
      s21_set_decimal_bit(value, i);
    }
  }
  return *value;
}

// int main() {
//   s21_decimal value;
//   s21_set_decimal_zero(&value);
//   value.bits[0] = 0xffffffff;
//   value.bits[1] = 0x80000000;
//   s21_binary_not(&value);
//   printf("bit0: %d %.8x\n", value.bits[0], value.bits[0]);
//   printf("bit1: %d %.8x\n", value.bits[1], value.bits[1]);
//   printf("bit2: %d %.8x\n", value.bits[2], value.bits[2]);
//   printf("bit3: %d %.8x\n", value.bits[3], value.bits[3]);
//   printf("bit3: %d %.8x\n", INT32_MAX, INT32_MAX);
//   return 0;
// }