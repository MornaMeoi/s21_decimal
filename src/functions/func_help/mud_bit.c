
#include "../../s21_decimal.h"
void mud_bit(big_s21_decimal val1, big_s21_decimal val2, big_s21_decimal* res) {
  null_big_decimal(res);
  for (int i = find_1(val2); i >= 0; i--) {
    // printf("\nSVl1: %d\n", get_bit_big_decimal(val2, i));
    if (get_bit_big_decimal(val2, i)) {
      s21_add_bit(*res, val1, res);
    }
    if (i != 0) shift_left(res, 1);
  }
}
