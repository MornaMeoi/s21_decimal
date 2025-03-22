#include "../../s21_decimal.h"

int get_bit_big_decimal(big_s21_decimal dec, int i) {
  unsigned x = 0;
  x = dec.bits[i / 32];
  i %= 32;
  unsigned int one = 1;
  unsigned int y = one << i;
  x &= y;
  x >>= i;
  return x;
}
