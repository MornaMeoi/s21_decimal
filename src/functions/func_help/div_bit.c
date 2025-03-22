#include "../../s21_decimal.h"

void div_bit(big_s21_decimal value_1, big_s21_decimal value_2,
             big_s21_decimal* result, big_s21_decimal* temp) {
  temp->bits[6] = value_2.bits[6];
  null_big_decimal(temp);
  null_big_decimal(result);
  for (int i = find_1(value_1); i >= 0; i--) {
    div_add(value_1, temp, i);
    temp->bits[6] = value_2.bits[6];
    if (s21_is_greater_or_equal_big_help(*temp, value_2) == 1) {
      big_s21_decimal temp2 = *temp;
      big_s21_decimal value_2_2 = value_2;
      s21_sub_bit(&temp2, &value_2_2, temp);
      shift_left(result, 1);
      setbit_big_decimal(result, 0, 1);
    } else {
      shift_left(result, 1);
      setbit_big_decimal(result, 0, 0);
    }
  }
}
