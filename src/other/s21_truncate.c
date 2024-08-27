#include "../s21_decimal.h"
#include "../binary/s21_binary_shifts.c"
#include "../binary/s21_binary_div.c"
#include "../helpers/s21_decimal_is_correct.c"
#include "../helpers/s21_decimal_get_inf.c"
#include "../helpers/s21_get_decimal_scale.c"
#include "../helpers/s21_get_decimal_ten_pow.c"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_other_result code = S21_OTHER_OK;
  if (result == NULL) {
    code = S21_OTHER_ERROR;
  } else if(!s21_decimal_is_correct(value)){
    *result = s21_decimal_get_inf();
    code = S21_OTHER_ERROR; 
  } else {
    int scale = s21_get_decimal_scale(*result);
    *result = s21_binary_div(value, s21_get_decimal_ten_pow(scale), NULL);
    printf("[%d] = {%x, %x, %x, %x}\n", 1, result->bits[3], result->bits[2], result->bits[1], result->bits[0]);
  }

  return code;
}

int main() {
  s21_decimal value1;

  value1.bits[0] = 0x00000000;
  value1.bits[1] = 0x00000007;
  value1.bits[2] = 0x00000000;
  value1.bits[3] = 0x00000000;
 

  s21_decimal result;
  s21_truncate(value1, &result);
  printf("Results: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  
//   s21_big_decimal value1;

//   value1.decimal[0].bits[0] = 0x00000000;
//   value1.decimal[0].bits[1] = 0x00000000;
//   value1.decimal[0].bits[2] = 0x00000000;
//   value1.decimal[0].bits[3] = 0x00000000;

//   value1.decimal[1].bits[0] = 0x00000001;
//   value1.decimal[1].bits[1] = 0x00000001;
//   value1.decimal[1].bits[2] = 0x00000000;
//   value1.decimal[1].bits[3] = 0x00000000;
 

//   s21_big_decimal result = s21_int256_binary_shift_right(value1, 1);
// //   printf("Results: %u %x \n", result.decimal[0].bits[0], result.decimal[0].bits[0]);
// //   printf("Results: %u %x \n", result.decimal[0].bits[1], result.decimal[0].bits[1]);
// //   printf("Results: %u %x \n", result.decimal[0].bits[2], result.decimal[0].bits[2]);
// //   printf("Results: %u %x \n", result.decimal[0].bits[3], result.decimal[0].bits[3]);
// //   printf("Results: %u %x \n", result.decimal[1].bits[0], result.decimal[1].bits[0]);
// //   printf("Results: %u %x \n", result.decimal[1].bits[1], result.decimal[1].bits[1]);
// //   printf("Results: %u %x \n", result.decimal[1].bits[2], result.decimal[1].bits[2]);
// //   printf("Results: %u %x \n", result.decimal[1].bits[3], result.decimal[1].bits[3]);

//   printf("Results_young: %u %u %u %u \n", result.decimal[0].bits[3], result.decimal[0].bits[2], result.decimal[0].bits[1], result.decimal[0].bits[0]);
//   printf("Results_older: %u %u %u %u \n", result.decimal[1].bits[3], result.decimal[1].bits[2], result.decimal[1].bits[1], result.decimal[1].bits[0]);



  return 0;
}