#include "s21_decimal.h"
#include "s21_set_decimal_zero.c"
#include "s21_set_decimal_sign.c"


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    s21_conversion_result code = S21_CONVERSION_OK;
    if (!dst) {
        code = S21_CONVERSION_ERROR;
    } else {
        s21_set_decimal_zero(dst);
        if (src<0) {
            src = -src;
            s21_set_decimal_sign(dst, 1);
        }
        dst->bits[0] = src;
    }
    return code;
}

// int main() {
//     int src = -12;
//     s21_decimal dst;
//     int code = s21_from_int_to_decimal(src,&dst);
//     printf("Байт0: %u %x\n", dst.bits[0], dst.bits[0]);
//     printf("Байт1: %u %x\n", dst.bits[1], dst.bits[1]);
//     printf("Байт2: %u %x\n", dst.bits[2], dst.bits[2]);
//     printf("Байт3: %u %x\n", dst.bits[3], dst.bits[3]);
//     printf("Код: %d", code);
// }