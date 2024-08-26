#include "../s21_decimal.h"
#include "./s21_binary_sub.c"
#include "./s21_binary_shifts.c"
#include "./s21_binary_compare.c"
#include "../helpers/s21_get_zero_decimal.c"
#include "../helpers/s21_get_decimal_non_zero_index.c"


s21_decimal s21_binary_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal *remainder) {
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
        partial_remainder = s21_int128_binary_shift_right(partial_remainder, left1 - left2);
    }

    result = quotient;
    if (remainder != NULL) {
        *remainder = partial_remainder;
    }

    return result;
}


// int main() {
//     s21_decimal value1 = {0xffffffff, 0xffffffff, 0xffffff, 0x0};
//     s21_decimal value2 = {0xffffffff, 0xfff, 0x0, 0x0};
//     s21_decimal remainder = s21_get_zero_decimal();
//     s21_decimal result = s21_binary_div(value1, value2, &remainder);

//     printf("result: %u %x\n", result.bits[0], result.bits[0]);
//     printf("result: %u %x\n", result.bits[1], result.bits[1]);
//     printf("result: %u %x\n", result.bits[2], result.bits[2]);
//     printf("result: %u %x\n", result.bits[3], result.bits[3]);
//     printf("remainder: %u %x\n", remainder.bits[0], remainder.bits[0]);
//     printf("remainder: %u %x\n", remainder.bits[1], remainder.bits[1]);
//     printf("remainder: %u %x\n", remainder.bits[2], remainder.bits[2]);
//     printf("remainder: %u %x\n", remainder.bits[3], remainder.bits[3]);

//     return 0;
// }