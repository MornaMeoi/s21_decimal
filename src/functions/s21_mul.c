#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  null_decimal(result);
  int error = 4;
  big_s21_decimal val1 = {0}, val2 = {0}, res = {0};
  convert_to_big(value_1, &val1);
  convert_to_big(value_2, &val2);
  unsigned int sign_1 = get_sign_big_decimal(val1);
  unsigned int sign_2 = get_sign_big_decimal(val2);
  unsigned scale_1 = get_scale_big_decimal(val1);
  unsigned scale_2 = get_scale_big_decimal(val2);
  unsigned int sign;

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
    if (sign_1 == sign_2 && sign_1 == 1)
      sign = 0;
    else
      sign = sign_2 | sign_1;
    cout_1(val1) <= cout_1(val2) ? mul_bit(val2, val1, &res)
                                 : mul_bit(val1, val2, &res);
    set_scale_big_decimal(&res, scale_2 + scale_1);
    unsigned int s = sign;
    set_sign_big_decimal(&res, s);
    from_big_to_decimal(&res, result);
    error = 0;
  }
  return error;
}