#include "../s21_decimal.h"
#include "../helpers/s21_set_int_bit.c"
#include "../helpers/s21_get_zero_decimal.c"
#include "../helpers/s21_set_decimal_zero.c"
#include "../helpers/s21_is_int_bit_set.c"

s21_decimal s21_int128_binary_shift_left_one(s21_decimal decimal) {
    s21_decimal result = s21_get_zero_decimal();
    int max_bit = 0;
    for (int i = 2; i >= 0; i--) {
        if (i != 0 && s21_is_int_bit_set(decimal.bits[i - 1], bits_in_byte - 1)) {
            max_bit = 1;
        }
        unsigned int result_i = decimal.bits[i];
        result_i = result_i << 1;
        if (max_bit) result_i = s21_set_int_bit(result_i, 0);
        result.bits[i] = result_i;
        max_bit = 0;
    }
    return result;
}

s21_decimal s21_int128_binary_shift_left(s21_decimal decimal, int shift) {
    s21_decimal result = decimal;
    while (shift > 0) {
        result = s21_int128_binary_shift_left_one(result);
        --shift;
    }

    return result;
}

s21_big_decimal s21_int256_binary_shift_left(s21_big_decimal decimal, int shift) {
    s21_big_decimal result = decimal;
    int max_bit = 0;
    while (shift > 0) {
        max_bit = s21_bit_is_set(result.decimal[0], 96 - 1);
        result.decimal[0] = s21_int128_binary_shift_left_one(result.decimal[0]);
        result.decimal[1] = s21_int128_binary_shift_left_one(result.decimal[1]);
        if (max_bit) s21_set_decimal_bit(&result.decimal[1], 0);
        max_bit = 0;
    }

    return result;
}

int main() {
//   s21_decimal value1;

//   value1.bits[0] = 0x80000001;
//   value1.bits[1] = 0x80000004;
//   value1.bits[2] = 0x00000003;
//   value1.bits[3] = 0x00000000;
 

//   s21_decimal result = s21_int128_binary_shift_left(value1, 2);
//   printf("Results: %d %d %d %d\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
//   printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  
  s21_decimal value1;

  value1.bits[0] = 0x80000001;
  value1.bits[1] = 0x80000004;
  value1.bits[2] = 0x00000003;
  value1.bits[3] = 0x00000000;
 

  s21_decimal result = s21_int128_binary_shift_left(value1, 2);
  printf("Results: %d %d %d %d\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);



  return 0;
}