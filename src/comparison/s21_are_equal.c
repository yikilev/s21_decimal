#include "../s21_decimal.h"
#include "../other/s21_remove_insignificant_zeros.c"


int s21_are_equal(s21_decimal value1,s21_decimal value2) {
    s21_comparison_result code = S21_CONVERSION_ERROR;
    value1 = s21_remove_insignificant_zeros(value1);
    value2 = s21_remove_insignificant_zeros(value2);
    if (value1.bits[0] == 0 && value1.bits[1] == 0
        && value1.bits[2] == 0 && value2.bits[0] == 0
        && value2.bits[1] == 0 && value2.bits[2] == 0)
        code = S21_CONVERSION_OK;
    else 
        code = value1.bits[0] == value2.bits[0] && value1.bits[1] == value2.bits[1] && value1.bits[2] == value2.bits[2] && value1.bits[3] == value2.bits[3];
    return code;
}

// int main() {
//   s21_decimal value1;
//   s21_decimal value2;

//   value1.bits[0] = 0xFFFFFFFF; 
//   value1.bits[1] = 0x00000000;
//   value1.bits[2] = 0x00000000;
//   value1.bits[3] = 0x00000000;

//   value2.bits[0] = 0xFFFFFFFF; 
//   value2.bits[1] = 0x00000000;
//   value2.bits[2] = 0x00000000;
//   value2.bits[3] = 0x00000000;
//   int result = s21_are_equal(value1, value2);
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