#include "../s21_decimal.h"
#include "../binary/s21_binary_mult.c"
// #include "../binary/s21_binary_add.c"
// #include "../binary/s21_binary_shifts.c"
// #include "../helpers/s21_get_decimal_scale.c"
// #include "../helpers/s21_decimal_to_big_decimal.c"
// #include "../helpers/s21_get_decimal_ten_pow.c"
// #include "../helpers/s21_set_decimal_zero.c"
// #include "../helpers/s21_bit_is_set.c"
// #include "../helpers/s21_get_zero_decimal.c"
// #include "../helpers/s21_set_decimal_bit.c"

void s21_decimal_levelling(s21_decimal value1, s21_decimal value2, s21_big_decimal *result1, s21_big_decimal *result2){
    int scale1 = s21_get_decimal_scale(value1);
    int scale2 = s21_get_decimal_scale(value2);
    value1.bits[3] = 0x0;
    value2.bits[3] = 0x0;

    if (scale1 > scale2) {
        *result1 = s21_decimal_to_big_decimal(value1);
        *result2 = s21_binary_mult(value2, s21_get_decimal_ten_pow(scale1-scale2));
    } else if (scale2 > scale1){
        *result2 = s21_decimal_to_big_decimal(value2);
        *result1 = s21_binary_mult(value1, s21_get_decimal_ten_pow(scale2-scale1));        
    } else {
        *result1 = s21_decimal_to_big_decimal(value1);
        *result2 = s21_decimal_to_big_decimal(value2);
    }
}

// int main () {
//     s21_decimal value1 = {0x31, 0x0, 0x0, 0x00010000};
//     s21_decimal value2 = {0x5, 0x0, 0x0, 0x00000000};
//     s21_big_decimal result1;
//     s21_big_decimal result2;
//     s21_set_big_decimal_zero(&result1);
//     s21_set_big_decimal_zero(&result2);

//     s21_decimal_levelling(value1, value2, &result1, &result2);

//     printf("result1: %8d %.8x\n", result1.decimal[0].bits[0], result1.decimal[0].bits[0]);
//     printf("result1: %8d %.8x\n", result1.decimal[0].bits[1], result1.decimal[0].bits[1]);
//     printf("result1: %8d %.8x\n", result1.decimal[0].bits[2], result1.decimal[0].bits[2]);
//     printf("result1: %8d %.8x\n", result1.decimal[0].bits[3], result1.decimal[0].bits[3]);
//     printf("result1: %8d %.8x\n", result1.decimal[1].bits[0], result1.decimal[1].bits[0]);
//     printf("result1: %8d %.8x\n", result1.decimal[1].bits[1], result1.decimal[1].bits[1]);
//     printf("result1: %8d %.8x\n", result1.decimal[1].bits[2], result1.decimal[1].bits[2]);
//     printf("result1: %8d %.8x\n", result1.decimal[1].bits[3], result1.decimal[1].bits[3]);

//     printf("----------------------------------------------------------\n");
//     printf("result2: %d %x\n", result2.decimal[0].bits[0], result2.decimal[0].bits[0]);
//     printf("result2: %d %x\n", result2.decimal[0].bits[1], result2.decimal[0].bits[1]);
//     printf("result2: %d %x\n", result2.decimal[0].bits[2], result2.decimal[0].bits[2]);
//     printf("result2: %d %x\n", result2.decimal[0].bits[3], result2.decimal[0].bits[3]);
//     printf("result2: %d %x\n", result2.decimal[1].bits[0], result2.decimal[1].bits[0]);
//     printf("result2: %d %x\n", result2.decimal[1].bits[1], result2.decimal[1].bits[1]);
//     printf("result2: %d %x\n", result2.decimal[1].bits[2], result2.decimal[1].bits[2]);
//     printf("result2: %d %x\n", result2.decimal[1].bits[3], result2.decimal[1].bits[3]);


// }