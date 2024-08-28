#include "../s21_decimal.h"

int s21_scale_big_decimal_to_decimal(s21_big_decimal value){
    // Чтобы узнать необходимую степень десятки, на которую надо поделить, нужно:
    // взять максимальный децимал, узнать во сколько раз наша хрень value больше чем максимальное число децимала
    // затем найти такую степень десятки (s21_get_decimal_ten_pow) которая 


    s21_decimal max_decimal = s21_get_max_decimal();
    
}

int s21_max(int value1, int value2) {
    int result = value2;
    if (value1 > value2) {
        result = value1;
    }

    return result;
}