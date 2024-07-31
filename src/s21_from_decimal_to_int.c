#include "s21_decimal.h"
#include "s21_set_decimal_zero.c"
#include "s21_set_decimal_sign.c"


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