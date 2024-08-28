#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdio.h>
#include <check.h>


typedef struct s21_decimal {
    int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
    s21_decimal decimal[2];
} s21_big_decimal;


typedef union decimal_bit3{
    int i;
    struct {
        uint32_t empty2 : 16;
        uint32_t scale : 8;
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

typedef enum s21_conversion_result {
    S21_CONVERSION_OK = 0,
    S21_CONVERSION_ERROR = 1,
} s21_conversion_result;

typedef enum s21_other_result {
    S21_OTHER_OK = 0,
    S21_OTHER_ERROR = 1,
} s21_other_result;

typedef struct s21_decimal_256 {
    s21_decimal decimals[2];
} s21_decimal_256;

int s21_get_sign(s21_decimal value);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_set_decimal_zero(s21_decimal *value);
void s21_set_decimal_sign(s21_decimal * value, int sign);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_bit_is_set(s21_decimal value, int index);
s21_decimal s21_create_decimal_from_array(int bit0, int bit1, int bit2, int bit3);
s21_decimal s21_create_decimal_from_data(int sign, int scale, int bit2, int bit1, int bit0);
int s21_decimal_is_correct(s21_decimal value);
int s21_decimal_is_even(s21_decimal value);
int s21_get_decimal_non_zero_index(s21_decimal value);
int s21_get_decimal_scale(s21_decimal value);
s21_decimal s21_get_max_decimal(void);
s21_decimal s21_get_max_int(void);
s21_decimal s21_get_min_decimal(void);
s21_decimal s21_decimal_get_int_min(void);
int s21_get_sign(s21_decimal value);
s21_decimal s21_get_zero_decimal(void);
int s21_reset_int_bit(int value, int index);
void s21_set_decimal_bit(s21_decimal *value, int index);
void s21_set_decimal_scale(s21_decimal *value, int scale);
void s21_set_decimal_sign(s21_decimal * value, int sign);
void s21_set_decimal_zero(s21_decimal *value);
int s21_set_int_bit(int value, int index);
int s21_binary_compare(s21_decimal value1, s21_decimal value2);
s21_decimal s21_binary_add(s21_decimal value1, s21_decimal value2);
s21_big_decimal s21_binary_mult(s21_decimal value1, s21_decimal value2);
void s21_set_decimal_bit_zero(s21_decimal *value, int index);
s21_decimal s21_binary_not(s21_decimal *value);
s21_big_decimal s21_decimal_to_big_decimal(s21_decimal value);
void s21_set_big_decimal_zero(s21_big_decimal *value);
s21_big_decimal s21_binary_add_big_decimal(s21_big_decimal value1, s21_big_decimal value2);
int s21_add_helper(s21_decimal value1, s21_decimal value2, s21_decimal *result, int perenos);
int s21_is_int_bit_set(int number, int index);
s21_decimal s21_int128_binary_shift_left_one(s21_decimal decimal);
s21_decimal s21_int128_binary_shift_right_one(s21_decimal decimal);
s21_decimal s21_int128_binary_shift_left(s21_decimal decimal, int shift);
s21_big_decimal s21_int256_binary_shift_left(s21_big_decimal decimal, int shift);
s21_decimal s21_decimal_get_inf(void);
s21_decimal s21_get_decimal_ten(void);
s21_decimal s21_get_decimal_one(void);
s21_decimal s21_get_decimal_ten_pow(int pow);
int s21_truncate(s21_decimal value, s21_decimal *result);
s21_decimal s21_int128_binary_shift_right(s21_decimal decimal, int shift);
s21_big_decimal s21_int256_binary_shift_right(s21_big_decimal decimal, int shift);
s21_decimal s21_remove_insignificant_zeros(s21_decimal value);
int s21_decimal_is_equal_zero(s21_decimal value)

#define s21_mask_last_bit 0x00000001
#define s21_mask_first_bit 0x80000000
#define s21_minus 0x80000000
#define s21_plus 0x7fffffff
#define s21_scale 0x00ff0000
#define bits_in_byte 32
#define max_bits 128



#endif
