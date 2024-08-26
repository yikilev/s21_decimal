#include "../s21_decimal.h"

/**
 * @brief Проверяет установлен ли бит на позиции index в единицу
 * 
 */
int s21_is_int_bit_set(int number, int index) {
    return !!(number & (1U << index));
}