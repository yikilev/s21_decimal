#include "../s21_decimal.h"

/**
 * @brief Возвращает int с установленным битом в единицу на позиции index
 * 
 */
int s21_set_int_bit(int value, int index) {
    return (value | (1U << index));
}