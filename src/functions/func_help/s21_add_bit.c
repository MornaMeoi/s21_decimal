#include "../../s21_decimal.h"

void s21_add_bit(big_s21_decimal value_1, big_s21_decimal value_2,
                 big_s21_decimal *result) {
  unsigned temp = 0;
  for (int i = 0;
       i < (int)(sizeof(big_s21_decimal) / sizeof(unsigned) - 1) * 32; ++i) {
    unsigned result_bit = get_bit_big_decimal(value_1, i) +
                          get_bit_big_decimal(value_2, i) + temp;
    temp = result_bit / 2;
    result_bit %= 2;
    setbit_big_decimal(result, i, result_bit);
  }
}