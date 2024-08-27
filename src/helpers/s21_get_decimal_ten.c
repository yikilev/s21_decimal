#include "../s21_decimal.h"
// #include "./s21_get_decimal_one.c"
// #include "../binary/s21_binary_mult.c"

s21_decimal s21_get_decimal_ten(void) {
    s21_decimal result = {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}};
    return result;
}

// int main() {
//     s21_decimal ten = s21_get_decimal_ten();
//     s21_big_decimal result;
//     result.decimal[0] = s21_get_decimal_one();
//     s21_set_decimal_zero(&result.decimal[1]);
//     for (int i = 0; i <= 38; i++) {
//         printf("[%d] = {%x, %x, %x, %x}\n", i, result.decimal[0].bits[0], result.decimal[0].bits[1], result.decimal[0].bits[2], result.decimal[0].bits[3]);
//         result = s21_binary_mult(result.decimal[0], ten);
//         // printf("[%d] = {%x, %x, %x, %x}\n", 1, result.bits[3], result.bits[2], result.bits[1], result.bits[0]);
//     }
// }
