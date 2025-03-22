#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  big_s21_decimal val1 = {0}, val2 = {0}, res = {0};
  null_big_decimal(&val1);
  null_big_decimal(&val2);
  convert_to_big(value_1, &val1);
  convert_to_big(value_2, &val2);

  normalization(&val1, &val2);

  int error = 4, sign;
  if (is_full(val1) == 1) {
    if (get_sign_big_decimal(val1) == 0) {
      error = 1;

    } else {
      error = 2;
    }
  } else if (is_full(val2) == 1) {
    if (get_sign_big_decimal(val2) == 0) {
      error = 1;

    } else {
      error = 2;
    }
  } else {
    unsigned scale = get_scale_big_decimal(val1);
    int sign1 = get_sign_big_decimal(val1);
    int sign2 = get_sign_big_decimal(val2);
    if (sign1 == sign2) {
      s21_add_bit(val1, val2, &res);
      sign = get_sign_big_decimal(val1);
      error = 0;
    } else if (sign1 < sign2) {
      error = 0;
      set_sign_big_decimal(&val1, 0);
      set_sign_big_decimal(&val2, 0);
      if (s21_is_greater_or_equal_big(val1, val2) == 1) {
        s21_sub_bit(&val1, &val2, &res);
        sign = 0;
      } else {
        s21_sub_bit(&val2, &val1, &res);
        sign = 1;
      }
    } else {
      error = 0;
      set_sign_big_decimal(&val1, 0);
      set_sign_big_decimal(&val2, 0);
      if (s21_is_greater_or_equal_big(val2, val1) == 1) {
        s21_sub_bit(&val2, &val1, &res);
        sign = 0;
      } else {
        s21_sub_bit(&val1, &val2, &res);
        sign = 1;
      }
    }
    int s = sign;
    set_sign_big_decimal(&res, s);
    set_scale_big_decimal(&res, scale);

    from_big_to_decimal(&res, result);
  }

  return error;
}
