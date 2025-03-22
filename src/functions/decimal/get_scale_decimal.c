#include "../../s21_decimal.h"

int get_scale_decimal(s21_decimal dec) {
  unsigned y = dec.bits[3];
  y <<= 1;
  y >>= 1;
  y >>= 16;
  return y;
}
