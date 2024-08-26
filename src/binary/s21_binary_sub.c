// #include "../helpers/s21_get_zero_decimal.c"
// #include "../s21_decimal.h"
#include "./s21_binary_add.c"
#include "./s21_binary_not.c"
s21_decimal s21_binary_sub(s21_decimal value1, s21_decimal value2) {
  value2 = s21_binary_not(&value2);
  s21_decimal result = s21_get_zero_decimal();
  s21_decimal decimal_one = {0x1, 0x0, 0x0, 0x0};
  value2 = s21_binary_add(value2, decimal_one);
  result = s21_binary_add(value1, value2);
  return result;
}

// int main () {
//     s21_decimal value1 = {0x0,0x1,0x0,0x0};
//     s21_decimal value2 = {0x1,0x0,0x0,0x0};
//     s21_decimal result = s21_binary_sub(value1,value2);
//     printf("bit0: %u %x\n", result.bits[0], result.bits[0]);
//     printf("bit1: %u %x\n", result.bits[1], result.bits[1]);
//     printf("bit2: %u %x\n", result.bits[2], result.bits[2]);
//     printf("bit3: %u %x\n", result.bits[3], result.bits[3]);
//     return 0;
// }
