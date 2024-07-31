#include "s21_decimal.h"

int s21_is_equal(s21_decimal value1, s21_decimal value2){
    int flag = 1;
    for (int i = 0; i <4; i++){
        if (value1.bits[i] != value2.bits[i]) flag = 0;
    }
    return flag;
}

int s21_get_sign(s21_decimal value) {
    int sign = 0;
    value.bits[3] = value.bits[3] & s21_minus;
    if (value.bits[3] == s21_minus) {
        sign = 1;
    } else {
        sign = 0;
    }
    return sign;
}

int s21_decimal_is_correct(s21_decimal value) {
    s21_arithmetic_result code = S21_ARITHMETIC_OK;
    int mask_zero_bits = 0x7f00ffff;
    int SC = 0x00ff0000;
    int zero_bits = value.bits[3] & mask_zero_bits;
    printf("zero bits: %x\n",zero_bits);
    int scale = value.bits[3] & SC;
    if (zero_bits != 0 || scale>0x001C0000){
        code = S21_ARITHMETIC_ERROR;
    }

    return code;
}


int main(){
    int c = 0x0000001A;     //здесь 32 бита. каждый символ это 4 бита из шестнадцатеричной в двоичную.
    s21_decimal a, b;
    for (int i = 0; i<4; i++){
        b.bits[i] = 0x00000201;
    }
    a.bits[0] = 0x00000000;
    a.bits[1] = 0x00000000;
    a.bits[2] = 0x03420f00;
    a.bits[3] = 0x00100000;
    int flag = 1;
    flag = s21_is_equal(a,b);
    printf("flag: %d\n", flag);
    printf("%d\n",c);
    if (c == 26) {
        printf("YES\n");
    }
    printf("%x\n", a.bits[3]);
    int sign = s21_get_sign(a);
    printf("%d\n",sign);
    for (int x = 0; x<4; x++){
        printf("Число %d: %x\n",x,a.bits[x]);
    }
    printf("Число корректное: %d\n",s21_decimal_is_correct(a));
    printf("--------test_shift---------\n");
    int shift = 0x10000000;
    unsigned int shift2 = 0x80000000;
    int shift_right = shift>>4;
    int shift_left = shift<<3;
    unsigned int shift_right2 = shift>>4;
    unsigned int shift_left2 = shift<<4;
    printf("shift_right: %d  %x \n", shift_right, shift_right);
    printf(" shift_left: %d  %x \n", shift_left, shift_left);
    printf("unsigned shift_right: %d  %x \n", shift_right2, shift_right2);
    printf("unsigned shift_left: %d  %x \n", shift_left2, shift_left2);
    printf(" int_min: %d  %x \n", INT32_MIN, INT32_MIN);
    printf(" unsigned int_max: %d  %x \n", UINT32_MAX, UINT32_MAX);
    int ff = -100;
    printf("отрицательные числа в битах: %d  %x \n", ff, ff);
    
    return 0;
}
