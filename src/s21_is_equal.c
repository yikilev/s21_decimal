#include "s21_decimal.h"


int s21_is_equal(s21_decimal value1, s21_decimal value2){
    int flag = 1;
    for (int i = 0; i <3; i++){
        if (value1.bits[i] != value2.bits[i]) flag = 0;
    }
    return flag;
}
