// #include "../helpers/s21_set_decimal_bit.c"
// #include "../helpers/s21_set_decimal_zero.c"
// #include "../s21_decimal.h"

// void s21_set_decimal_zero(s21_decimal *value) {
//   for (int i = 0; i < 4; i++) {
//     value->bits[i] = 0x00000000;
//   }
// }

// void set_decimal_bit(s21_decimal *value, int index) {
//   if (index >= 0 && index <= 127) {
//     value->bits[index / bits_in_byte] |= (1U << (index % bits_in_byte));
//   }
// }
int s21_add_helper(s21_decimal value1, s21_decimal value2, s21_decimal *result,
                   int perenos) {
  for (int i = 0; i < 3; i++) {
    unsigned int temp_res = 0x00000000;
    unsigned int pervoe = value1.bits[i];
    unsigned int vtoroe = value2.bits[i];
    int sum_bits = 0;
    int temp_sum = 0;
    int temp_bit = 0;
    int bit1 = 0, bit2 = 0;
    for (int j = 0; j < 32; j++) {
      bit1 = pervoe & s21_mask_last_bit;
      bit2 = vtoroe & s21_mask_last_bit;
      pervoe = pervoe >> 1;
      vtoroe = vtoroe >> 1;
      sum_bits = bit1 + bit2 + perenos;
      if (sum_bits == 3) {
        perenos = 1;
        temp_sum = 1;
      } else if (sum_bits == 2) {
        perenos = 1;
        temp_sum = 0;
      } else {
        temp_sum = sum_bits;
        perenos = 0;
      }
      if (j != 0) {
        temp_res = temp_res << 1;
      }
      temp_res = temp_res | temp_sum;
    }
    for (int k = 0; k < 32; k++) {
      if (k != 0) {
        result->bits[i] = result->bits[i] << 1;
        temp_res = temp_res >> 1;
      }
      temp_bit = temp_res & s21_mask_last_bit;
      result->bits[i] = result->bits[i] | temp_bit;
    }
  }
  return perenos;
}

s21_decimal s21_binary_add(s21_decimal value1, s21_decimal value2) {
  int perenos = 0;
  s21_decimal result;
  s21_set_decimal_zero(&result);
  s21_add_helper(value1, value2, &result, perenos);
  return result;
}

s21_big_decimal s21_binary_add_big_decimal(s21_big_decimal value1,
                                           s21_big_decimal value2) {
  int perenos = 0;
  s21_big_decimal result;
  s21_set_decimal_zero(&result.decimal[0]);
  s21_set_decimal_zero(&result.decimal[1]);
  perenos = s21_add_helper(value1.decimal[0], value2.decimal[0],
                           &result.decimal[0], perenos);
  s21_add_helper(value1.decimal[1], value2.decimal[1], &result.decimal[1],
                 perenos);
  return result;
}

// int main() {
//   s21_big_decimal value1;
//   s21_big_decimal value2;

//   value1.decimal[0].bits[0] = 0x00000001;
//   value1.decimal[0].bits[1] = 0x00000000;
//   value1.decimal[0].bits[2] = 0x80000000;
//   value1.decimal[0].bits[3] = 0x00000000;
//   value1.decimal[1].bits[0] = 0x00000002;
//   value1.decimal[1].bits[1] = 0x00000000;
//   value1.decimal[1].bits[2] = 0x00000000;
//   value1.decimal[1].bits[3] = 0x001A0000;
//   value2.decimal[0].bits[0] = 0x00000009;
//   value2.decimal[0].bits[1] = 0x00000000;
//   value2.decimal[0].bits[2] = 0x80000000;
//   value2.decimal[0].bits[3] = 0x00000000;
//   value2.decimal[1].bits[0] = 0x00000000;
//   value2.decimal[1].bits[1] = 0x00000000;
//   value2.decimal[1].bits[2] = 0x00000000;
//   value2.decimal[1].bits[3] = 0x00000000;
//   // s21_set_decimal_zero(&chislo1);
//   // s21_set_decimal_zero(&chislo2);
//   // chislo1.bits[0] = 0x00000004;
//   // chislo2.bits[0] = 0xf0000008;
//   // chislo1.bits[1] = 0xf1111118;
//   // chislo2.bits[1] = 0xf0000008;
//   // chislo1.bits[2] = 0xf1111118;
//   // chislo2.bits[2] = 0xf0000008;

//   s21_big_decimal result = s21_binary_add_big_decimal(value1, value2);
//   printf("Результат: %u  %x\n", result.decimal[0].bits[0],
//   result.decimal[0].bits[0]); printf("Результат: %u  %x\n",
//   result.decimal[0].bits[1], result.decimal[0].bits[1]); printf("Результат:
//   %u  %x\n", result.decimal[0].bits[2], result.decimal[0].bits[2]);
//   printf("Результат: %u  %x\n", result.decimal[0].bits[3],
//   result.decimal[0].bits[3]); printf("Результат: %u  %x\n",
//   result.decimal[1].bits[0], result.decimal[1].bits[0]); printf("Результат:
//   %u  %x\n", result.decimal[1].bits[1], result.decimal[1].bits[1]);
//   printf("Результат: %u  %x\n", result.decimal[1].bits[2],
//   result.decimal[1].bits[2]); printf("Результат: %u  %x\n",
//   result.decimal[1].bits[3], result.decimal[1].bits[3]);

//   return 0;
// }