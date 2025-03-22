#include "../../s21_decimal.h"

int s21_is_not_equal_big(big_s21_decimal val1, big_s21_decimal val2) {
  return s21_cmp_big_decimal(val1, val2) != 0 ? 1 : 0;
}
