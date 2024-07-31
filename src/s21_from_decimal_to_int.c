#include "s21_decimal.h"
#include "s21_set_decimal_zero.c"
#include "s21_set_decimal_sign.c"


/*
Чтобы перевести число из децимала в инт надо:
1) проверить указатель dst
2) мантисса может быть любой, поэтому надо чтобы скейл делал мантиссу меньше чем в 32 бита, то есть если число которое лежит в 
*/

int s21_from_decimal_to_int(s21_decimal src, int *dst){
    s21_conversion_result code = S21_CONVERSION_OK;
    if(!dst){
        code = S21_CONVERSION_ERROR;
    } else {
        if 
    }


    // if (!dst) {
    //     code = S21_CONVERSION_ERROR;
    // } else {
    //     s21_set_decimal_zero(dst);
    //     if (src<0) {
    //         src = -src;
    //         s21_set_decimal_minus_sign(dst);
    //     }
    //     dst->bits[0] = src;
    // }
    return code;
}