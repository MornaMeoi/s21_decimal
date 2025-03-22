
#include "../../s21_decimal.h"
void div_add(big_s21_decimal value_1, big_s21_decimal* result, int i) {
  shift_left(result, 1);
  int bit = 0;
  if (i >= 0) {
    bit = get_bit_big_decimal(value_1, i);
  }
  setbit_big_decimal(result, 0, bit);
}