#include "../../s21_decimal.h"

void from_big_to_decimal(big_s21_decimal* big, s21_decimal* dec) {
  int count = 0;
  unsigned int scale_res = get_scale_big_decimal(*big);
  while (big->bits[6] != 0 && big->bits[5] != 0 && big->bits[4] != 0 &&
         big->bits[3] != 0) {
    div_ten(big);
    count++;
  }
  dec->bits[0] = big->bits[0];
  dec->bits[1] = big->bits[1];
  dec->bits[2] = big->bits[2];
  set_scale_decimal(dec, scale_res - count);
  set_sign_decimal(dec, get_sign_big_decimal(*big));
}