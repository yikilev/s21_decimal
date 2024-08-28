#include "../s21_decimal.h"

int s21_decimal_is_correct(s21_decimal value) {
    s21_arithmetic_result code = S21_ARITHMETIC_OK;
    int mask_zero_bits = 0x7f00ffff;
    int SC = 0x00ff0000;
    int zero_bits = value.bits[3] & mask_zero_bits;
    // printf("zero bits: %x\n",zero_bits);
    int scale = value.bits[3] & SC;
    if (zero_bits != 0 || scale>0x001C0000){
        code = S21_ARITHMETIC_ERROR;
    }

    return code;
}
