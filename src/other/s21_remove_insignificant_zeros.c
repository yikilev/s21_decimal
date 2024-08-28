// #include "../s21_decimal.h"
#include "../binary/s21_binary_div.c"

s21_decimal s21_remove_insignificant_zeros(s21_decimal value) {
    s21_decimal result = value;
    int scale = s21_get_decimal_scale(value);
    int sign = s21_get_sign(value);
    if (scale > 0 && s21_decimal_is_correct(value)) {
        s21_decimal remainder = s21_get_zero_decimal();
        s21_decimal tmp = value;
        while(scale > 0) {
            tmp = s21_binary_div(tmp, s21_get_decimal_ten(), &remainder);
            if (s21_decimal_is_equal_zero(remainder)) {
                result = tmp;
                scale--;
            } else {
                break;
            }
            s21_set_decimal_scale(&result, scale);
            s21_decimal_set_sign(&result, sign);
        }
    }
}

void s21_print_binary_int(int number) {
    for (int j = 31; j >= 0; j--) {
            printf("%d", (number >> j) & 1);
    }
}

void print_decimal(s21_decimal *number) {
    for (int i = 3; i >= 0; i--) {
        s21_print_binary_int(number->bits[i]);
        i == 0 ? printf("\n") : printf(".");
    }
}


int main() {
  s21_decimal value1;

  value1.bits[0] = 0x00000005; 
  value1.bits[1] = 0x00000000;
  value1.bits[2] = 0x00000000;
  value1.bits[3] = 0x00000000;

  s21_decimal result;
  result = s21_remove_insignificant_zeros(value1);
  print_decimal(&result);
  printf("\n\nResults: %u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  printf("Results: %x %x %x %x\n", result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
  
  return 0;
}