#include "../../s21_decimal.h"

int get_scale_big_decimal(big_s21_decimal dec) {
  unsigned int y = dec.bits[6];
  y <<= 1;
  y >>= 1;
  y >>= 16;
  return y;
}
