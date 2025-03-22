#include "../../s21_decimal.h"

void shift_left(big_s21_decimal* decimal, int step) {
  unsigned temp = 0;
  for (int i = 0; i < (int)(sizeof(big_s21_decimal) / sizeof(unsigned) - 1);
       ++i) {
    unsigned copy = decimal->bits[i];
    decimal->bits[i] <<= step;
    decimal->bits[i] |= temp;
    temp = copy >> (32 - step);
  }
}