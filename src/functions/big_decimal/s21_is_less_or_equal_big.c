#include "../../s21_decimal.h"

int s21_is_less_or_equal_big(big_s21_decimal val1, big_s21_decimal val2) {
  return (s21_is_less_big(val1, val2) || s21_is_equal_big(val1, val2)) ? 1 : 0;
}
