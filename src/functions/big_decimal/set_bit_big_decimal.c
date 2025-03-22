#include "../../s21_decimal.h"

void setbit_big_decimal(big_s21_decimal *dec, int i, int bit) {
  unsigned int x = 0;
  int new_i = i;
  x = dec->bits[i / 32];
  i %= 32;
  unsigned int one = 1;
  unsigned int y = one << i;
  x = bit ? x | y : x & (~y);
  dec->bits[new_i / 32] = x;
  //   меняем i индекс 0 на 1 : меняем i индекс 1 на 0
}
