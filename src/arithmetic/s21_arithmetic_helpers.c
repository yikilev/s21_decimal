#include "../s21_decimal.h"

int s21_scale_big_decimal_to_decimal(s21_big_decimal value){
    // Чтобы узнать необходимую степень десятки, на которую надо поделить, нужно:
    // взять максимальный децимал, узнать во сколько раз наша хрень value больше чем максимальное число децимала
    // затем найти такую степень десятки (s21_get_decimal_ten_pow) которая 


    s21_decimal max_decimal = s21_get_max_decimal();
    
}