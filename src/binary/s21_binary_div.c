#include "../helpers/s21_get_decimal_non_zero_index.c"
#include "../helpers/s21_get_zero_decimal.c"
#include "../s21_decimal.h"
#include "./s21_binary_compare.c"
#include "./s21_binary_shifts.c"
#include "./s21_binary_sub.c"
#include "../helpers/s21_decimal_to_big_decimal.c"
#include "../helpers/s21_decimal_is_zero.c"
// #include "../helpers/s21_bit_is_set.c"


s21_decimal s21_binary_div(s21_decimal decimal1, s21_decimal decimal2,
                           s21_decimal *remainder) {
  s21_decimal result;

  s21_decimal partial_remainder = s21_get_zero_decimal();
  s21_decimal quotient = s21_get_zero_decimal();
  s21_decimal zero_decimal = s21_get_zero_decimal();
  if (!s21_binary_compare(decimal1, zero_decimal)) {
    quotient = s21_get_zero_decimal();
    partial_remainder = s21_get_zero_decimal();
  } else if (s21_binary_compare(decimal1, decimal2) == -1) {
    quotient = s21_get_zero_decimal();
    partial_remainder = decimal1;
  } else {
    int left1 = s21_get_decimal_non_zero_index(decimal1);
    int left2 = s21_get_decimal_non_zero_index(decimal2);
    int shift = left1 - left2;

    s21_decimal shifted_divisor = s21_int128_binary_shift_left(decimal2, shift);
    s21_decimal dividend = decimal1;

    int need_subtraction = 1;

    while (shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder = s21_binary_sub(dividend, shifted_divisor);
      } else {
        partial_remainder = s21_binary_add(dividend, shifted_divisor);
      }

      quotient = s21_int128_binary_shift_left(quotient, 1);
      if (s21_bit_is_set(partial_remainder, 95) == 0) {
        s21_set_decimal_bit(&quotient, 0);
      }

      dividend = s21_int128_binary_shift_left(partial_remainder, 1);

      if (s21_bit_is_set(partial_remainder, 95) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    if (s21_bit_is_set(partial_remainder, 95)) {
      partial_remainder = s21_binary_add(partial_remainder, shifted_divisor);
    }
    partial_remainder =
        s21_int128_binary_shift_right(partial_remainder, left1 - left2);
  }

  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}

s21_big_decimal s21_binary_div_big_decimal(s21_big_decimal decimal1,
                                           s21_big_decimal decimal2,
                                           s21_big_decimal *remainder) {
  s21_big_decimal result;

  s21_big_decimal partial_remainder =
      s21_decimal_to_big_decimal(s21_get_zero_decimal());
  s21_big_decimal quotient = s21_decimal_to_big_decimal(s21_get_zero_decimal());
  if (!s21_decimal_is_zero(decimal1.decimal[0]) &&
      !s21_decimal_is_zero(decimal1.decimal[1])) {
    quotient = s21_decimal_to_big_decimal(s21_get_zero_decimal());
    partial_remainder = s21_decimal_to_big_decimal(s21_get_zero_decimal());
  } else if (s21_binary_compare_big_decimal(decimal1, decimal2) == -1) {
    quotient = s21_decimal_to_big_decimal(s21_get_zero_decimal());
    partial_remainder = decimal1;
  } else {
    int left1 = s21_get_decimal_non_zero_index(decimal1.decimal[1]);
    if (left1 == -1) {
      left1 = s21_get_decimal_non_zero_index(decimal1.decimal[0]);
    } else {
      left1 = max_bits + left1 - 1;
    }

    int left2 = s21_get_decimal_non_zero_index(decimal2.decimal[1]);
    if (left2 == -1) {
      left2 = s21_get_decimal_non_zero_index(decimal2.decimal[0]);
    } else {
      left2 = max_bits + left2 - 1;
    }

    int shift = left1 - left2;

    s21_big_decimal shifted_divisor =
        s21_int256_binary_shift_left(decimal2, shift);
    s21_big_decimal dividend = decimal1;

    int need_subtraction = 1;

    while (shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder =
            s21_binary_sub_big_decimal(dividend, shifted_divisor);
      } else {
        partial_remainder =
            s21_binary_add_big_decimal(dividend, shifted_divisor);
      }

      quotient = s21_int256_binary_shift_left(quotient, 1);
      if (s21_bit_is_set(partial_remainder.decimal[1], 95) == 0) {
        s21_set_decimal_bit(&(quotient.decimal[0]), 0);
      }

      dividend = s21_int256_binary_shift_left(partial_remainder, 1);

      // Если старший бит частичного остатка равен 0, то на следующей итерации
      // необходимо проводить вычитание (Шаг 5 алгоритма)
      if (s21_bit_is_set(partial_remainder.decimal[1], 95) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    // Определяем, требуется ли коррекция остатка (п.8 алгоритма)
    if (s21_bit_is_set(partial_remainder.decimal[1], 95)) {
      partial_remainder =
          s21_binary_add_big_decimal(partial_remainder, shifted_divisor);
    }
    // Возвращаем на место частичный остаток (п.9 алгоритма)
    partial_remainder =
        s21_int256_binary_shift_right(partial_remainder, left1 - left2);
  }

  // Заполняем переменные результата (частное и остаток)
  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}

int main() {
  s21_big_decimal value1;
  s21_big_decimal value2;
  s21_big_decimal remainder;
  remainder.decimal[0] = s21_get_zero_decimal();
  remainder.decimal[1] = s21_get_zero_decimal();

  value1.decimal[0].bits[0] = 0x00000000;
  value1.decimal[0].bits[1] = 0x00000000;
  value1.decimal[0].bits[2] = 0x00000000;
  value1.decimal[0].bits[3] = 0x00000000;
  value1.decimal[1].bits[0] = 0x00000003;
  value1.decimal[1].bits[1] = 0x00000000;
  value1.decimal[1].bits[2] = 0x00000000;
  value1.decimal[1].bits[3] = 0x00000000;

  value2.decimal[0].bits[0] = 0x00000002;
  value2.decimal[0].bits[1] = 0x00000000;
  value2.decimal[0].bits[2] = 0x00000000;
  value2.decimal[0].bits[3] = 0x00000000;
  value2.decimal[1].bits[0] = 0x00000000;
  value2.decimal[1].bits[1] = 0x00000000;
  value2.decimal[1].bits[2] = 0x00000000;
  value2.decimal[1].bits[3] = 0x00000000;

  s21_big_decimal result =
      s21_binary_div_big_decimal(value1, value2, &remainder);

  printf("result: %u %x\n", result.decimal[0].bits[0],
         result.decimal[0].bits[0]);
  printf("result: %u %x\n", result.decimal[0].bits[1],
         result.decimal[0].bits[1]);
  printf("result: %u %x\n", result.decimal[0].bits[2],
         result.decimal[0].bits[2]);
  printf("result: %u %x\n", result.decimal[0].bits[3],
         result.decimal[0].bits[3]);
  printf("result: %u %x\n", result.decimal[1].bits[0],
         result.decimal[1].bits[0]);
  printf("result: %u %x\n", result.decimal[1].bits[1],
         result.decimal[1].bits[1]);
  printf("result: %u %x\n", result.decimal[1].bits[2],
         result.decimal[1].bits[2]);
  printf("result: %u %x\n", result.decimal[1].bits[3],
         result.decimal[1].bits[3]);

  printf("------------------------------\n");

  printf("remainder: %u %x\n", remainder.decimal[0].bits[0],
         remainder.decimal[0].bits[0]);
  printf("remainder: %u %x\n", remainder.decimal[0].bits[1],
         remainder.decimal[0].bits[1]);
  printf("remainder: %u %x\n", remainder.decimal[0].bits[2],
         remainder.decimal[0].bits[2]);
  printf("remainder: %u %x\n", remainder.decimal[0].bits[3],
         remainder.decimal[0].bits[3]);
  printf("remainder: %u %x\n", remainder.decimal[1].bits[0],
         remainder.decimal[1].bits[0]);
  printf("remainder: %u %x\n", remainder.decimal[1].bits[1],
         remainder.decimal[1].bits[1]);
  printf("remainder: %u %x\n", remainder.decimal[1].bits[2],
         remainder.decimal[1].bits[2]);
  printf("remainder: %u %x\n", remainder.decimal[1].bits[3],
         remainder.decimal[1].bits[3]);

  return 0;
}