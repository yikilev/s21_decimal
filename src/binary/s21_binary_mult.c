#include "../helpers/s21_set_decimal_zero.c"
#include "../s21_decimal.h"
#include "./s21_binary_add.c"
#include "./s21_binary_shifts.c"
#include "../helpers/s21_decimal_to_bigdecimal.c"

s21_big_decimal s21_binary_mult(s21_decimal value0, s21_decimal value2) {
  s21_big_decimal result;
  s21_set_big_decimal_zero(&result);
  s21_big_decimal value1 = s21_decimal_to_big_decimal(value0);
  for (int i = 0; i < 96; i++) {
    if (s21_bit_is_set(value2, i)) {
      result = s21_binary_add_big_decimal(result, value1);
    }
    value1 = s21_int256_binary_shift_left(value1, 1);
  }

  return result;
}

int main() {
  s21_big_decimal result;
  s21_set_big_decimal_zero(&result);

  s21_decimal value1 = {0x80000000, 0x0, 0x0, 0x0};
  s21_decimal value2 = {0x2, 0x0, 0x0, 0x0};
  // s21_decimal value1 = {0x5,0x0,0x0,0x0};
  // s21_decimal value2 = {0x2,0x0,0x0,0x0};
  result = s21_binary_mult(value1, value2);

  printf("Результат: %u  %x\n", result.decimal[0].bits[0],
         result.decimal[0].bits[0]);
  printf("Результат: %u  %x\n", result.decimal[0].bits[1],
         result.decimal[0].bits[1]);
  printf("Результат: %u  %x\n", result.decimal[0].bits[2],
         result.decimal[0].bits[2]);
  printf("Результат: %u  %x\n", result.decimal[0].bits[3],
         result.decimal[0].bits[3]);
  printf("Результат: %u  %x\n", result.decimal[1].bits[0],
         result.decimal[1].bits[0]);
  printf("Результат: %u  %x\n", result.decimal[1].bits[1],
         result.decimal[1].bits[1]);
  printf("Результат: %u  %x\n", result.decimal[1].bits[2],
         result.decimal[1].bits[2]);
  printf("Результат: %u  %x\n", result.decimal[1].bits[3],
         result.decimal[1].bits[3]);

  return 0;
}