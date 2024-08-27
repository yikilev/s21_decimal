// #include "../helpers/s21_get_zero_decimal.c"
#include "../helpers/s21_get_decimal_one.c"
#include "../helpers/s21_set_decimal_zero.c"
#include "../s21_decimal.h"
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

s21_big_decimal s21_binary_sub_big_decimal(s21_big_decimal value1,
                                           s21_big_decimal value2) {
  s21_big_decimal result;
  s21_set_big_decimal_zero(&result);

  value2.decimal[0] = s21_binary_not(&value2.decimal[0]);
  value2.decimal[1] = s21_binary_not(&value2.decimal[1]);
  s21_big_decimal big_decimal_one;
  big_decimal_one.decimal[0] = s21_get_decimal_one();
  s21_set_decimal_zero(&big_decimal_one.decimal[1]);

  value2 = s21_binary_add_big_decimal(value2, big_decimal_one);
  result = s21_binary_add_big_decimal(value1, value2);
  return result;
}

// int main () {
//     s21_big_decimal value1;
//     s21_big_decimal value2;
//     value1.decimal[0].bits[0] = 0x00000000;
//     value1.decimal[0].bits[1] = 0x00000000;
//     value1.decimal[0].bits[2] = 0x00000000;
//     value1.decimal[0].bits[3] = 0x00000000;
//     value1.decimal[1].bits[0] = 0x00000000;
//     value1.decimal[1].bits[1] = 0x00000000;
//     value1.decimal[1].bits[2] = 0x00000000;
//     value1.decimal[1].bits[3] = 0x00000000;

//     value2.decimal[0].bits[0] = 0x00000009;
//     value2.decimal[0].bits[1] = 0x00000000;
//     value2.decimal[0].bits[2] = 0x00000000;
//     value2.decimal[0].bits[3] = 0x00000000;
//     value2.decimal[1].bits[0] = 0x00000000;
//     value2.decimal[1].bits[1] = 0x00000000;
//     value2.decimal[1].bits[2] = 0x00000000;
//     value2.decimal[1].bits[3] = 0x00000000;

//     s21_big_decimal result = s21_binary_sub_big_decimal(value1,value2);
//     s21_binary_not(&(result.decimal[0]));
//     s21_binary_not(&(result.decimal[1]));

//     printf("result: %u %x\n", result.decimal[0].bits[0],
//     result.decimal[0].bits[0]); printf("result: %u %x\n",
//     result.decimal[0].bits[1], result.decimal[0].bits[1]); printf("result: %u
//     %x\n", result.decimal[0].bits[2], result.decimal[0].bits[2]);
//     printf("result: %u %x\n", result.decimal[0].bits[3],
//     result.decimal[0].bits[3]); printf("result: %u %x\n",
//     result.decimal[1].bits[0], result.decimal[1].bits[0]); printf("result: %u
//     %x\n", result.decimal[1].bits[1], result.decimal[1].bits[1]);
//     printf("result: %u %x\n", result.decimal[1].bits[2],
//     result.decimal[1].bits[2]); printf("result: %u %x\n",
//     result.decimal[1].bits[3], result.decimal[1].bits[3]);

//     return 0;
// }
