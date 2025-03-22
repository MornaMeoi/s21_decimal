#include "../../s21_decimal.h"

void set_scale_big_decimal(big_s21_decimal* dec, int scale) {
  unsigned sign = get_sign_big_decimal(*dec);
  unsigned scl_new = scale << 16;
  if (scale != 0) {
    dec->bits[6] = 0;
    dec->bits[6] |= scl_new;
  } else
    dec->bits[6] = 0;
  set_sign_big_decimal(dec, sign);
}
