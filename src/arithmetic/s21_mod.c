#include "../s21_decimal.h"
#include "../helpers/s21_get_zero_decimal.c"
#include "../helpers/s21_get_sign.c"
#include "../helpers/s21_decimal_is_correct.c"
#include "../arithmetic/s21_arithmetic_helpers.c"

int s21_mod(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
    s21_arithmetic_result code = S21_ARITHMETIC_OK;

    if (result == NULL) {
        code = S21_ARITHMETIC_ERROR;
    } else if (!s21_decimal_is_correct(value1) || !s21_decimal_is_correct(value2)) {
        code = S21_ARITHMETIC_ERROR;
        *result = s21_decimal_get_inf();
    } else if (s21_is_equal(value2, s21_get_zero_decimal())) {
        code = S21_ARITHMETIC_ZERO_DIV;
        *result = s21_decimal_get_inf();
    } else if (s21_is_less(s21_abs(value1), s21_abs(value2))) {
        code = S21_ARITHMETIC_OK;
        *result = value1;
    } else {
        *result = s21_get_zero_decimal();

        int sign1 = s21_decimal_get_sign(value1);
        int power1 = s21_decimal_get_power(value1);
        int power2 = s21_decimal_get_power(value2);
        int max_power = s21_max(power1, power2);
        s21_big_decimal value1l;
        s21_big_decimal value2l;
        s21_big_decimal remainder = s21_decimal_to_big_decimal(s21_get_zero_decimal());

        s21_decimal_leveling(value1, value2, &value1l, &value2l);
        s21_int256_binary_division(value1l, value2l, &remainder);
        s21_decimal_set_power(&remainder.decimal[0], max_power);

        *result = remainder.decimal[0];
        // Выставляем знак результата, анализируя входные данные
        s21_decimal_set_sign(result, sign1);
    }

    return code;
}


int main() {
  s21_decimal value1;
  s21_decimal value2;

  value1.bits[0] = 0x00000004;
  value1.bits[1] = 0x00000000;
  value1.bits[2] = 0x00000000;
  value1.bits[3] = 0x00000000;
  value1.bits[0] = 0x00000000;
  value1.bits[1] = 0x00000000;
  value1.bits[2] = 0x00000000;
  value1.bits[3] = 0x00000000;

  value2.bits[0] = 0x00000002;
  value2.bits[1] = 0x00000000;
  value2.bits[2] = 0x00000000;
  value2.bits[3] = 0x00000000;
  value2.bits[0] = 0x00000000;
  value2.bits[1] = 0x00000000;
  value2.bits[2] = 0x00000000;
  value2.bits[3] = 0x00000000;

  s21_decimal result;
  s21_mod(value1, value2, &result);

  printf("Results: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);


  return 0;
}

// int main() {
//   s21_decimal value1;

//   value1.bits[0] = 0x00000000;
//   value1.bits[1] = 0x00000007;
//   value1.bits[2] = 0x00000000;
//   value1.bits[3] = 0x00080000;
 

//   s21_decimal result = s21_get_zero_decimal();
//   int code = s21_truncate(value1, &result);
//   printf("code %d\n", code);
//   printf("Results: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
//   printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  
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

//   return 0;
// }