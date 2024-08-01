#include "s21_decimal.h"
#include <limits.h>

int main() {
    // int max_value = 2147483647;
    // unsigned max_value = 4294967295;
    s21_decimal number = {{0, 0, 0, 0}};
    // int src = -2147483647;

    // u.f = 0.15625;
    float src = __FLT_MAX__;
    s21_from_float_to_decimal(src, &number);
    // s21_print_binary_float(u.i);
    // s21_print_binary_float(src);

    // printf("\n%d\n", max_value + 2147483647);
    // print_decimal(&number);
    // number.bits[1] = set_bit_to_one(number.bits[1], 0);
    // number.bits[1] = set_bit_to_zero(number.bits[1], 0);
    // print_decimal(&number);
    // s21_from_int_to_decimal(src, &number);
    // print_decimal(&number);
    // printf("%.6E\n", 0.000000000012F);
    // s21_print_binary_int(src);
    // printf("%d\n", number.bits[3] | number.bits[3]);
}
/* 
01111111111111111111111111111111 (2^31 - 1)
    +
00000000000000000000000000000001 (1)
    =
10000000000000000000000000000000 (2^31)
*/

void print_decimal(s21_decimal *number) {
    for (int i = 3; i >= 0; i--) {
        s21_print_binary_int(number->bits[i]);
        i == 0 ? printf("\n") : printf(".");
    }
}

void print_float_decimal(s21_decimal *number) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 31; j >= 0; j--) {
            if ((i == 3 && j == 23) || (i == 3 && j == 15) || (i == 3 && j == 30) || (i == 0 && j == 22)) printf(" ");
            printf("%d", (number->bits[i] >> j) & 1);
        }
        i == 0 ? printf("\n") : printf(".");
    }
}

/*На вход 32 битное число */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int sign = 0;
    if (src < 0) {
        src = -src;
        src = INT_MAX - src + 1;
        sign = 1;
    }
    for (int index = 0; index <= 32; index++) {
        if ((src >> index) % 2 == 0) {
            dst->bits[0] = s21_set_bit_to_zero(dst->bits[0], index);
        } else if ((src >> index) % 2 == 1) {
            dst->bits[0] = s21_set_bit_to_one(dst->bits[0], index);
        }
    }
    s21_set_sign(sign, dst);
    return 0;
}

/*На вход 32 битное число */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int result = 0;
    if (dst == NULL) {
        result = 1;
    } else {
        s21_float_binary number;
        s21_decimal_service service = {dst->bits[3]};
        number.f = src;
        // service.service = dst->bits[3];
        int sign = 0;
        if (src < 0) {
           sign = 1;
           src = -src;
        }
        // printf("DECIMAL NUMBER BINARY:\n");
        // print_float_decimal(dst);
        printf("FLOAT NUMBER BINARY:\n");
        for (int j = 31; j >= 0; j--) {
            int current_bit = (number.i >> j) & 1;
            if (j == 30 || j == 22) printf(" ");
            // printf("%d", (number.i >> j) & 1);
            if (j >= 23 && j <= 30) {
                // printf("%d", (number.i >> j) & 1);
                service.areas.exp = service.areas.exp | (current_bit << (j - 23));
                // service.areas.exp = 255;
            }

            if (j >= 0 && j <= 22) {
                // printf("%d", (number.i >> j) & 1);
                dst->bits[0] = dst->bits[0] | (current_bit << j);
                // service.areas.exp = 255;
            }
        }
        // s21_set_sign(sign, dst);
        service.areas.sign = sign;
        dst->bits[3] = service.service;
        printf("\nDECIMAL NUMBER BINARY:\n");
        print_float_decimal(dst);
        printf("\n");
        s21_print_binary_float(number.i);
    }
    return result;
}



int s21_set_bit_to_one(int number, int index) {
    return number | (1 << index);
}

int s21_set_bit_to_zero(int number, int index) {
    return number & ~(1 << index);
}

void s21_set_sign(int sign, s21_decimal *dst) {
    s21_decimal_service service = {dst->bits[3]};
    service.areas.sign = sign == 1 ? 1 : 0;
    dst->bits[3] = service.service;
}

void s21_print_binary_int(int number) {
    for (int j = 31; j >= 0; j--) {
            printf("%d", (number >> j) & 1);
    }
}

void s21_print_binary_float(unsigned number) {
    for (int j = 31; j >= 0; j--) {
            if (j == 30 || j == 22) printf(" ");
            printf("%d", (number >> j) & 1);
    }
    printf("\n");
}



// void s21_print_binary_int(int number) {
//     char result[33];
//     result[32] = '\0'; 
//     for (int index = 0; index < 32; index++) {
//         if (((number >> index) & 1) == 0) result[31 - index] = '0';
//         if (((number >> index) & 1) == 1) result[31 - index] = '1';
//     }
//     printf("%s\n", result);
// }