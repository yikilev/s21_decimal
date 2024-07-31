#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdio.h>
#include <check.h>


typedef struct s21_decimal {
    int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
    int bits[7];
} s21_big_decimal;


typedef union decimal_bit3{
    int i;
    struct {
        uint32_t empty2 : 16;
        uint32_t power : 8;
        uint32_t empty1 : 7;
        uint32_t sign : 1;
    } parts;
} decimal_bit3;


typedef enum s21_arithmetic_result {
    S21_ARITHMETIC_OK = 0,
    S21_ARITHMETIC_BIG = 1,
    S21_ARITHMETIC_SMALL = 2,
    S21_ARITHMETIC_ZERO_DIV = 3,
    S21_ARITHMETIC_ERROR = 4
} s21_arithmetic_result;


int s21_get_sign(s21_decimal value);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_set_decimal_zero(s21_decimal *value);

#define s21_mask_last_bit 0x00000001
#define s21_mask_first_bit 0x80000000
#define s21_minus 0x80000000
#define s21_scale 0x00ff0000




#endif
