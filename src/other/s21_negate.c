#include "../s21_decimal.h"
#include "../helpers/s21_set_decimal_sign.c"
#include "../helpers/s21_get_sign.c"
#include "../helpers/s21_decimal_is_correct.c"

int s21_negate(s21_decimal value, s21_decimal *result) {
    s21_other_result code = S21_OTHER_OK;
    if (result == NULL) {
        code = S21_OTHER_ERROR;
    } else {
        *result = value; 
        s21_set_decimal_sign(result, !s21_get_sign(value));
        if (!s21_decimal_is_correct(value)) {
            code = S21_OTHER_ERROR;
        }
    }
    return code;
}

// void s21_print_binary_int(int number) {
//     for (int j = 31; j >= 0; j--) {
//             printf("%d", (number >> j) & 1);
//     }
// }

// void print_decimal(s21_decimal *number) {
//     for (int i = 3; i >= 0; i--) {
//         s21_print_binary_int(number->bits[i]);
//         i == 0 ? printf("\n") : printf(".");
//     }
// }

// int main() {
//   s21_decimal value1;

//   value1.bits[0] = 0xFFFFFFFF;
//   value1.bits[1] = 0x00000000;
//   value1.bits[2] = 0x00000000;
//   value1.bits[3] = 0x00A80000;

//   s21_decimal result;
//   s21_negate(value1, &result);
//   print_decimal(&result);
// //   printf("Results: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
// //   printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  
// //   s21_big_decimal value1;

// //   value1.decimal[0].bits[0] = 0x00000000;
// //   value1.decimal[0].bits[1] = 0x00000000;
// //   value1.decimal[0].bits[2] = 0x00000000;
// //   value1.decimal[0].bits[3] = 0x00000000;

// //   value1.decimal[1].bits[0] = 0x00000001;
// //   value1.decimal[1].bits[1] = 0x00000001;
// //   value1.decimal[1].bits[2] = 0x00000000;
// //   value1.decimal[1].bits[3] = 0x00000000;
 

// //   s21_big_decimal result = s21_int256_binary_shift_right(value1, 1);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[0], result.decimal[0].bits[0]);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[1], result.decimal[0].bits[1]);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[2], result.decimal[0].bits[2]);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[3], result.decimal[0].bits[3]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[0], result.decimal[1].bits[0]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[1], result.decimal[1].bits[1]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[2], result.decimal[1].bits[2]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[3], result.decimal[1].bits[3]);

// //   printf("Results_young: %u %u %u %u \n", result.decimal[0].bits[3], result.decimal[0].bits[2], result.decimal[0].bits[1], result.decimal[0].bits[0]);
// //   printf("Results_older: %u %u %u %u \n", result.decimal[1].bits[3], result.decimal[1].bits[2], result.decimal[1].bits[1], result.decimal[1].bits[0]);

//   return 0;
// }