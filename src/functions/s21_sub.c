#include "../s21_decimal.h"
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  big_s21_decimal res = {0};
  int answer = 4;
  unsigned sing = 0, scale = 0;
  big_s21_decimal val1 = {0}, val2 = {0};

  convert_to_big(value_1, &val1);
  convert_to_big(value_2, &val2);

  normalization(&val1, &val2);

  int sign1 = get_sign_big_decimal(val1);
  int sign2 = get_sign_big_decimal(val2);
  scale = get_scale_big_decimal(val2);

  set_sign_big_decimal(&val1, 0);
  set_sign_big_decimal(&val2, 0);
  if (is_full(val1) == 1) {
    if (sign1 == 1)
      answer = 2;
    else
      answer = 1;
  } else if (is_full(val2) == 1) {
    if (sign2 == 1)
      answer = 2;
    else
      answer = 1;
  } else if (sign1 == sign2) {
    if (s21_is_greater_or_equal_big(val1, val2) == 1) {
      sing = sign1;
      s21_sub_bit(&val1, &val2, &res);
    } else {
      if (sign2 == 1)
        sing = 0;
      else
        sing = 1;
      s21_sub_bit(&val2, &val1, &res);
    }
    answer = 0;
  } else if (sign1 < sign2) {
    sing = 0;
    s21_add_bit(val1, val2, &res);
    answer = 0;
  } else {
    sing = 1;
    s21_add_bit(val2, val1, &res);
    answer = 0;
  }
  set_sign_big_decimal(&res, sing);
  set_scale_big_decimal(&res, scale);
  from_big_to_decimal(&res, result);
  return answer;
}