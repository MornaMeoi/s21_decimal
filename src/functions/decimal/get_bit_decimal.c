#include "../../s21_decimal.h"

int get_bit_decimal(s21_decimal dec, int i) {
  unsigned int x = 0;
  x = dec.bits[i / 32];
  i %= 32;
  unsigned int one = 1;
  unsigned int y = one << i;
  x &= y;
  x >>= i;
  return x;
}