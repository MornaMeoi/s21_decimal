#include "../../s21_decimal.h"

int s21_is_greater_or_equal_big_help(big_s21_decimal val1,
                                     big_s21_decimal val2) {
  return (s21_is_greater_big_help(val1, val2) ||
          s21_is_equal_big_help(val1, val2))
             ? 1
             : 0;
}
int s21_is_equal_big_help(big_s21_decimal val1, big_s21_decimal val2) {
  return s21_cmp_big_decimal_help(val1, val2) == 0 ? 1 : 0;
}
int s21_is_greater_big_help(big_s21_decimal val1, big_s21_decimal val2) {
  return s21_cmp_big_decimal_help(val1, val2) == 1 ? 1 : 0;
}