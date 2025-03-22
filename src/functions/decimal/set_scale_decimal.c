#include "../../s21_decimal.h"

void set_scale_decimal(s21_decimal* dec, int scale) {
  unsigned sign = get_sign_decimal(*dec);
  unsigned scle_new = scale << 16;
  if (scale != 0) {
    dec->bits[3] = 0;
    dec->bits[3] |= scle_new;
  } else
    dec->bits[3] = 0;
  set_sign_decimal(dec, sign);
}
