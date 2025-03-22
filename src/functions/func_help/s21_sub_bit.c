#include "../../s21_decimal.h"
void s21_sub_bit(big_s21_decimal* value_1, big_s21_decimal* value_2,
                 big_s21_decimal* result) {
  for (int i = 0;
       i < (int)(sizeof(big_s21_decimal) / sizeof(unsigned) - 1) * 32; ++i) {
    unsigned int result_bit =
        get_bit_big_decimal(*value_1, i) - get_bit_big_decimal(*value_2, i);

    if (get_bit_big_decimal(*value_1, i) == 0 &&
        get_bit_big_decimal(*value_2, i) == 1) {
      int j = i + 1;
      while (get_bit_big_decimal(*value_1, j) != 1) {
        setbit_big_decimal(value_1, j, 1);
        j++;
      }
      setbit_big_decimal(value_1, j, 0);
      setbit_big_decimal(value_2, i, 0);
      setbit_big_decimal(value_1, i, 1);
      result_bit =
          get_bit_big_decimal(*value_1, i) - get_bit_big_decimal(*value_2, i);
    }
    setbit_big_decimal(result, i, result_bit);
  }
}