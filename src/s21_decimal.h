#include <stdio.h>

typedef struct {
    int bits[4];
} s21_decimal;

typedef struct {
    int bits[8];
} s21_big_decimal;

typedef union s21_decimal_service {
    int service;
    struct {
        __uint32_t empty : 16;
        __uint32_t exp : 8;
        __uint32_t empty_ : 7;
        __uint32_t sign : 1;
    } areas;
} s21_decimal_service;

typedef union s21_float_binary{
        float f;
        unsigned int i;
} s21_float_binary;


void print_decimal(s21_decimal *number);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_set_bit_to_one(int number, int index);
int s21_set_bit_to_zero(int number, int index);
void s21_set_sign(int sign, s21_decimal *dst);
void s21_print_binary(int number);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
void s21_print_binary_int(int number);
void s21_print_binary_float(unsigned number);
void print_float_decimal(s21_decimal *number);