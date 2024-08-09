#include "../s21_decimal.h"


int s21_decimal_is_even(s21_decimal value){
    int code = 1;
    if ((unsigned int)value.bits[0] % 2 == 0) code = 0;
    return code;
}


// int main(){
//     s21_decimal decimal;
//     decimal.bits[3] = 0x00000000;
//     decimal.bits[2] = 0x00000000;
//     decimal.bits[1] = 0x00000000;
//     decimal.bits[0] = 0x0000000e;
//     int c = s21_decimal_is_even(decimal);
//     printf("четность: %d\n", c);

//     return 0;
// }