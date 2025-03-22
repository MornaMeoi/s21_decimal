#include "../../s21_decimal.h"

int s21_cmp_big_decimal_help(big_s21_decimal big_val1,
                             big_s21_decimal big_val2) {
  int result = EQUAL;
  for (int i = 192; i >= 0; i--) {
    if (get_bit_big_decimal(big_val1, i) > get_bit_big_decimal(big_val2, i)) {
      result = GREATER;
      i = -1;
    } else if (get_bit_big_decimal(big_val1, i) <
               get_bit_big_decimal(big_val2, i)) {
      result = LESS;
      i = -1;
    }
  }
  return result;
}
