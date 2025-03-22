#include "../../s21_decimal.h"

int is_zero_decimal(s21_decimal dec) {
  int res = 1;
  if (dec.bits[0] == 0 && dec.bits[1] == 0 && dec.bits[2] == 0) res = 0;
  return res;
}