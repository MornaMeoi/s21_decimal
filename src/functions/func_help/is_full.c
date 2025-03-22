
#include "../../s21_decimal.h"
int is_full(big_s21_decimal dec) {
  s21_decimal t = {0};
  int error = 1;
  from_big_to_decimal(&dec, &t);
  for (int i = 0; i < 96; i++) {
    if (get_bit_decimal(t, i) != 1) {
      error = 0;
      i = 100;
    }
  }
  return error;
}
