#include "../s21_decimal.h"

int s21_decimal_is_zero(s21_decimal value){
    int code = 1;

    if (value.bits[0] == 0x0 && value.bits[1] == 0x0 && value.bits[2] == 0x0 && value.bits[3] == 0x0){
        code = 0;
    }
    return code;
}