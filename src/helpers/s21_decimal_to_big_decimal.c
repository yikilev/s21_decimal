// #include "../s21_decimal.h"
// #include "./s21_set_decimal_zero.c"



s21_big_decimal s21_decimal_to_big_decimal(s21_decimal value) {
    s21_big_decimal result;
    s21_set_big_decimal_zero(&result);
    result.decimal[0] = value;
    return result;
}


// int main(){

//     s21_decimal value1 = {0x5, 0x4, 0x3, 0x2};
//     s21_big_decimal value = s21_decimal_to_big_decimal(value1);
//     printf("decimal[0]. bits[0]: %d %x\n", value.decimal[0].bits[0], value.decimal[0].bits[0]);
//     printf("decimal[0]. bits[1]: %d %x\n", value.decimal[0].bits[1], value.decimal[0].bits[1]);
//     printf("decimal[0]. bits[2]: %d %x\n", value.decimal[0].bits[2], value.decimal[0].bits[2]);
//     printf("decimal[0]. bits[3]: %d %x\n", value.decimal[0].bits[3], value.decimal[0].bits[3]);
//     printf("decimal[1]. bits[0]: %d %x\n", value.decimal[1].bits[0], value.decimal[1].bits[0]);
//     printf("decimal[1]. bits[1]: %d %x\n", value.decimal[1].bits[1], value.decimal[1].bits[1]);
//     printf("decimal[1]. bits[2]: %d %x\n", value.decimal[1].bits[2], value.decimal[1].bits[2]);
//     printf("decimal[1]. bits[3]: %d %x\n", value.decimal[1].bits[3], value.decimal[1].bits[3]);

//     return 0;
// }