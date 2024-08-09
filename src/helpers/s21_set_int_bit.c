#include "../s21_decimal.h"

int s21_set_int_bit(int value, int index){
    return (value | (1U << index));
}