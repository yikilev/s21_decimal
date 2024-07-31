// #include "s21_decimal.h"

// // s21_decimal s21_binary_shift_left(s21_decimal value, int shift) {}
// void s21_set_decimal_zero(s21_decimal *value) {
//     for (int i = 0; i<4; i++) {
//         value->bits[i] = 0x00000000;
//     }
// }

// s21_decimal s21_binary_add(s21_decimal value1, s21_decimal value2) {
//   int perenos = 0;
//   s21_decimal result;
//   s21_set_decimal_zero(&result);
//   for (int i = 0; i < 3; i++) {
//     unsigned int temp_res = 0x00000000;
//     unsigned int pervoe = value1.bits[i];
//     unsigned int vtoroe = value2.bits[i];
//     // int mask_copy = s21_mask_last_bit;
//     int sum_bits = 0;
//     int temp_sum = 0;
//     int temp_bit = 0;
//     for (int j = 0; j < 32; j++) {
//       int bit1 = pervoe & s21_mask_last_bit;
//       int bit2 = vtoroe & s21_mask_last_bit;
//       pervoe = pervoe >> 1;
//       vtoroe = vtoroe >> 1;
//       sum_bits = bit1 + bit2 + perenos;
//       if (sum_bits == 3) {
//         perenos = 1;
//         temp_sum = 1;
//       } else if (sum_bits == 2) {
//         perenos = 1;
//         temp_sum = 0;
//       } else {
//         temp_sum = sum_bits;
//       }
//       if (j != 0) {
//         temp_res = temp_res << 1;
//       }
//       temp_res = temp_res | temp_sum;
//       temp_bit = temp_res & s21_mask_last_bit;
//       if (j != 0) result.bits[i] << 1;
//       result.bits[i] = result.bits[i] | temp_bit;
//     }

//   }
//   return result;
// }

// int main() {
//   s21_decimal chislo1, chislo2;
//   s21_set_decimal_zero(&chislo1);
//   s21_set_decimal_zero(&chislo2);
//   chislo1.bits[0] = 0x00000008;
//   chislo2.bits[0] = 0x0fffffff;
//   s21_decimal result = s21_binary_add(chislo1,chislo2);
//   printf("Результат: %d  %x\n", result.bits[0], result.bits[0]);
//   printf("Результат: %d  %x\n", result.bits[1], result.bits[1]);
//   printf("Результат: %d  %x\n", result.bits[2], result.bits[2]);
//   printf("Результат: %d  %x\n", result.bits[3], result.bits[3]);
//   return 0;
// }

#include "s21_decimal.h"

// s21_decimal s21_binary_shift_left(s21_decimal value, int shift) {}
void s21_set_decimal_zero(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0x00000000;
  }
}

s21_decimal s21_binary_add(s21_decimal value1, s21_decimal value2) {
  int perenos = 0;
  s21_decimal result;
  s21_set_decimal_zero(&result);
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
        result.bits[i] = result.bits[i] << 1;
        temp_res = temp_res >> 1;
      }
      temp_bit = temp_res & s21_mask_last_bit;
      result.bits[i] = result.bits[i] | temp_bit;
    }
  }
  return result;
}

int main() {
  s21_decimal chislo1, chislo2;
  s21_set_decimal_zero(&chislo1);
  s21_set_decimal_zero(&chislo2);
  chislo1.bits[0] = 0x00000001;
  chislo2.bits[0] = 0x00000001;
  s21_decimal result = s21_binary_add(chislo1, chislo2);
  printf("Результат: %d  %x\n", result.bits[0], result.bits[0]);
  printf("Результат: %d  %x\n", result.bits[1], result.bits[1]);
  printf("Результат: %d  %x\n", result.bits[2], result.bits[2]);
  printf("Результат: %d  %x\n", result.bits[3], result.bits[3]);
  return 0;
}