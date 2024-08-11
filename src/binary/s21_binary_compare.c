#include "../s21_decimal.h"
#include "../helpers/s21_bit_is_set.c"
#include "../helpers/s21_set_decimal_zero.c"

int s21_binary_compare(s21_decimal value1, s21_decimal value2){
    int code = 0;
    
    for (int i = max_bits-1; i>=0; i--){
        int a = s21_bit_is_set(value1, i);
        int b = s21_bit_is_set(value2, i);
        if (a == 0 && b != 0) code = -1;
        if (a != 0 && b == 0) code = 1;
        if (code != 0) break;
    }

    return code;
}


// int main () {
//     s21_decimal value1, value2;
//     s21_set_decimal_zero(&value1);
//     s21_set_decimal_zero(&value2);
//     value1.bits[0] = 0x00000001;
//     value2.bits[0] = 0x00000001;

//     int c = s21_binary_compare(value1,value2);
//     printf("Результат сравнения: %d\n", c);
//     return 0;

// }