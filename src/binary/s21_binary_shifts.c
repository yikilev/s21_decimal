// #include "../s21_decimal.h"
// #include "../helpers/s21_set_int_bit.c"
// #include "../helpers/s21_get_zero_decimal.c"
// #include "../helpers/s21_set_decimal_zero.c"
// #include "../helpers/s21_is_int_bit_set.c"
// #include "../helpers/s21_bit_is_set.c"
// #include "../helpers/s21_set_decimal_bit.c"

s21_decimal s21_int128_binary_shift_left_one(s21_decimal decimal) {
  s21_decimal result = s21_get_zero_decimal();
  int max_bit = 0;
  for (int i = 2; i >= 0; i--) {
    if (i != 0 && s21_is_int_bit_set(decimal.bits[i - 1], bits_in_byte - 1)) {
      max_bit = 1;
    }
    unsigned int result_i = decimal.bits[i];
    result_i = result_i << 1;
    if (max_bit) result_i = s21_set_int_bit(result_i, 0);
    result.bits[i] = result_i;
    max_bit = 0;
  }
  return result;
}

s21_decimal s21_int128_binary_shift_right_one(s21_decimal decimal) {
  s21_decimal result = s21_get_zero_decimal();
  int first_bit = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != 2 && s21_is_int_bit_set(decimal.bits[i + 1], 0)) {
      first_bit = 1;
    }
    unsigned int result_i = decimal.bits[i];
    result_i = result_i >> 1;
    if (first_bit) result_i = s21_set_int_bit(result_i, bits_in_byte - 1);
    result.bits[i] = result_i;
    first_bit = 0;
  }
  return result;
}

s21_decimal s21_int128_binary_shift_left(s21_decimal decimal, int shift) {
  s21_decimal result = decimal;
  while (shift > 0) {
    result = s21_int128_binary_shift_left_one(result);
    --shift;
  }

  return result;
}

s21_decimal s21_int128_binary_shift_right(s21_decimal decimal, int shift) {
  s21_decimal result = decimal;
  while (shift > 0) {
    result = s21_int128_binary_shift_right_one(result);
    --shift;
  }

  return result;
}

s21_big_decimal s21_int256_binary_shift_right(s21_big_decimal decimal,
                                              int shift) {
  s21_big_decimal result = decimal;
  int first_bit = 0;
  while (shift > 0) {
    first_bit = s21_bit_is_set(result.decimal[1], 0);
    result.decimal[0] = s21_int128_binary_shift_right_one(result.decimal[0]);
    result.decimal[1] = s21_int128_binary_shift_right_one(result.decimal[1]);
    if (first_bit) s21_set_decimal_bit(&result.decimal[0], 96 - 1);
    first_bit = 0;
    shift--;
  }

  return result;
}

s21_big_decimal s21_int256_binary_shift_left(s21_big_decimal decimal,
                                             int shift) {
  s21_big_decimal result = decimal;
  int max_bit = 0;
  while (shift > 0) {
    max_bit = s21_bit_is_set(result.decimal[0], 96 - 1);
    result.decimal[0] = s21_int128_binary_shift_left_one(result.decimal[0]);
    result.decimal[1] = s21_int128_binary_shift_left_one(result.decimal[1]);
    if (max_bit) s21_set_decimal_bit(&result.decimal[1], 0);
    max_bit = 0;
    shift--;
  }

  return result;
}

// int main() {
//   s21_decimal value1;

//   value1.bits[0] = 0x00000000;
//   value1.bits[1] = 0x00000007;
//   value1.bits[2] = 0x00000000;
//   value1.bits[3] = 0x00000000;

//   s21_decimal result = s21_int128_binary_shift_right(value1, 1);
//   printf("Results: %u %u %u %u\n", result.bits[3], result.bits[2],
//   result.bits[1], result.bits[0]); printf("Results: %x %x %x %x\n",
//   result.bits[3], result.bits[2], result.bits[1], result.bits[0]);

// //   s21_big_decimal value1;

// //   value1.decimal[0].bits[0] = 0x00000000;
// //   value1.decimal[0].bits[1] = 0x00000000;
// //   value1.decimal[0].bits[2] = 0x00000000;
// //   value1.decimal[0].bits[3] = 0x00000000;

// //   value1.decimal[1].bits[0] = 0x00000001;
// //   value1.decimal[1].bits[1] = 0x00000001;
// //   value1.decimal[1].bits[2] = 0x00000000;
// //   value1.decimal[1].bits[3] = 0x00000000;

// //   s21_big_decimal result = s21_int256_binary_shift_right(value1, 1);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[0],
// result.decimal[0].bits[0]);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[1],
// result.decimal[0].bits[1]);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[2],
// result.decimal[0].bits[2]);
// // //   printf("Results: %u %x \n", result.decimal[0].bits[3],
// result.decimal[0].bits[3]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[0],
// result.decimal[1].bits[0]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[1],
// result.decimal[1].bits[1]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[2],
// result.decimal[1].bits[2]);
// // //   printf("Results: %u %x \n", result.decimal[1].bits[3],
// result.decimal[1].bits[3]);

// //   printf("Results_young: %u %u %u %u \n", result.decimal[0].bits[3],
// result.decimal[0].bits[2], result.decimal[0].bits[1],
// result.decimal[0].bits[0]);
// //   printf("Results_older: %u %u %u %u \n", result.decimal[1].bits[3],
// result.decimal[1].bits[2], result.decimal[1].bits[1],
// result.decimal[1].bits[0]);

//   return 0;
// }

// #include "../helpers/s21_bit_is_set.c"
// #include "../helpers/s21_set_decimal_bit.c"
// #include "../s21_decimal.h"

// s21_decimal s21_binary_decimal_shift_left_one(s21_decimal value) {
//   s21_decimal result;
//   result = value;
//   for (int i = 94; i >= 0; i--) {
//     if (s21_bit_is_set(value, i)) {
//       s21_set_decimal_bit(&result, i + 1);
//     } else {
//       s21_set_decimal_bit_zero(&result, i + 1);
//     }
//   }
//   s21_set_decimal_bit_zero(&result, 0);
//   return result;
// }

// s21_big_decimal s21_binary_big_decimal_shift_left_one(s21_big_decimal value)
// {
//   s21_big_decimal result;
//   result = value;
//   s21_binary_decimal_shift_left_one(result.decimal[1]);
//   if (s21_bit_is_set(result.decimal[0], 95)) {
//     s21_set_decimal_bit(&result.decimal[1], 0);
//   } else {
//     s21_set_decimal_bit_zero(&result.decimal[1], 0);
//   }
//   s21_binary_decimal_shift_left_one(result.decimal[0]);
//   return result;
// }

// int main() {
//   s21_big_decimal value;
//   value.decimal[0].bits[0] = 0x00000002;
//   value.decimal[0].bits[1] = 0x00000001;
//   value.decimal[0].bits[2] = 0x00000001;
//   value.decimal[0].bits[3] = 0x80000001;
//   value.decimal[1].bits[0] = 0x00000001;
//   value.decimal[1].bits[1] = 0x00000001;
//   value.decimal[1].bits[2] = 0x00000001;
//   value.decimal[1].bits[3] = 0x00000001;

//   value = s21_binary_big_decimal_shift_left_one(value);
//   printf("value.decimal[0].bits[0] %u %x\n", value.decimal[0].bits[0],
//   value.decimal[0].bits[0]); printf("value.decimal[0].bits[1] %u %x\n",
//   value.decimal[0].bits[1], value.decimal[0].bits[1]);
//   printf("value.decimal[0].bits[2] %u %x\n", value.decimal[0].bits[2],
//   value.decimal[0].bits[2]); printf("value.decimal[0].bits[3] %u %x\n",
//   value.decimal[0].bits[3], value.decimal[0].bits[3]);
//   printf("value.decimal[1].bits[0] %u %x\n", value.decimal[1].bits[0],
//   value.decimal[1].bits[0]); printf("value.decimal[1].bits[1] %u %x\n",
//   value.decimal[1].bits[1], value.decimal[1].bits[1]);
//   printf("value.decimal[1].bits[2] %u %x\n", value.decimal[1].bits[2],
//   value.decimal[1].bits[2]); printf("value.decimal[1].bits[3] %u %x\n",
//   value.decimal[1].bits[3], value.decimal[1].bits[3]);

//   return 0;
// }

// int main() {
//     for (int i = 0; i < 10;){
//         printf("%d\n", i++);
//     }
//         printf("\n");

//     for (int i = 0; i < 10;){
//         printf("%d\n", ++i);
//     }
// }