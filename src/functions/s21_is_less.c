#include "../s21_decimal.h"

int s21_is_less(s21_decimal val1, s21_decimal val2) {
  return s21_cmp_decimal(val1, val2) == -1 ? 1 : 0;
}