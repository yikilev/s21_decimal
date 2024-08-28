#include "../s21_decimal.h"
// #include "../helpers/s21_get_zero_decimal.c"
#include "./s21_are_equal.c"
// #include "../helpers/s21_get_sign.c"
#include "../helpers/s21_is_int_bit_set.c"
#include "../helpers/s21_set_int_bit.c"
#include "../helpers/s21_get_decimal_ten_pow.c"
#include "../arithmetic/s21_decimal_levelling.c"
#include "../arithmetic/s21_abs.c"
// #include "../binary/s21_binary_compare.c"


int s21_is_less_handle(s21_decimal value1, s21_decimal value2) {
    s21_comparison_result code = S21_COMPARISON_ERROR;
    s21_decimal tmp1 = value1;
    s21_decimal tmp2 = value2;
    s21_big_decimal tmp1l;
    s21_big_decimal tmp2l;

    s21_decimal_levelling(tmp1, tmp2, &tmp1l, &tmp2l);
    int compare = s21_binary_compare_big_decimal(tmp1l, tmp2l);
    if (compare == -1) {
        code = S21_COMPARISON_OK;
    } else {
        code = S21_COMPARISON_ERROR;
    }
    return code;
}

int s21_is_less(s21_decimal value1, s21_decimal value2) {
    s21_comparison_result code = S21_COMPARISON_ERROR;
    int sign1 = s21_get_sign(value1);
    int sign2 = s21_get_sign(value2);

    if (s21_are_equal(value1, s21_get_zero_decimal()) && s21_are_equal(value2, s21_get_zero_decimal())) {
        code = S21_COMPARISON_ERROR;
    } else if (sign1 == 1 && sign2 == 0) {
        code = S21_COMPARISON_OK;
    } else if (sign1 == 0 && sign2 == 1) {
        code = S21_COMPARISON_ERROR;
    } else if (sign1 == 1 && sign2 == 1) {
        code = s21_is_less_handle(s21_abs(value2), s21_abs(value1));
    } else {
        code = s21_is_less_handle(value1, value2);
    }

    return code;
}

// int main() {
//   s21_decimal value1;
//   s21_decimal value2;

//   value1.bits[0] = 0xFFFFFFFF; 
//   value1.bits[1] = 0x00000000;
//   value1.bits[2] = 0x00000000;
//   value1.bits[3] = 0x00000000;

//   value2.bits[0] = 0xEFFFFFFF; 
//   value2.bits[1] = 0x00000000;
//   value2.bits[2] = 0x00000000;
//   value2.bits[3] = 0x00000000;
//   int result = s21_is_less(value1, value2);
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
