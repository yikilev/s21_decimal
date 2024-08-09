#include "../s21_decimal.h"

int s21_get_decimal_scale(s21_decimal value){
    decimal_bit3 bit3;
    bit3.i = value.bits[3];
    unsigned int scale = bit3.parts.scale;
    return scale;
}


// int main(){

//     s21_decimal decimal;
//     decimal.bits[3] = 0x00811000;
//     decimal.bits[2] = 0x00000000;
//     decimal.bits[1] = 0x00000000;
//     decimal.bits[0] = 0x00000000;

//     int scale = s21_get_decimal_scale(decimal);
//     printf("скейл: %d\n", scale);
//     return 0;
// }