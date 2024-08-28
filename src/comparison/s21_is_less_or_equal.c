#include "../s21_decimal.h"
#include "./s21_is_less.c"
// #include "./s21_are_equal.c"


int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
    return s21_is_less(value1, value2) || s21_are_equal(value1, value2);
}

// int main() {
//   s21_decimal value1;
//   s21_decimal value2;

//   value1.bits[0] = 0xAFFFFCFF; 
//   value1.bits[1] = 0x00000000;
//   value1.bits[2] = 0x00000000;
//   value1.bits[3] = 0x00000000;

//   value2.bits[0] = 0xAFFFFAFF; 
//   value2.bits[1] = 0x00000000;
//   value2.bits[2] = 0x00000000;
//   value2.bits[3] = 0x00000000;
//   int result = s21_is_less_or_equal(value1, value2);
//   printf("\n\nResult: %u\n", result);
// //   s21_decimal result = value1;
// //   printf("\n\nResults: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
// //   printf("Results: %x %x %x %x\n\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
// //   print_decimal(&result);
// //   result = s21_remove_insignificant_zeros(value1);
// //   printf("\n\nResults: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
// //   printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
// //   print_decimal(&result);
//   return 0;
// }