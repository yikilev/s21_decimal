#include "s21_decimal.h"

int main() {
    int max_value = 2147483647;
    printf("\n%d\n", max_value + 2147483647);
}

/* 
01111111111111111111111111111111(2^31 - 1)
+
00000000000000000000000000000001(1)
=
10000000000000000000000000000000(2^31)
*/