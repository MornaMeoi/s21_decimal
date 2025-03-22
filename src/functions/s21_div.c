#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  null_decimal(result);
  int error = 4;
  big_s21_decimal val1 = {0}, val2 = {0}, res = {0}, temp = {0}, res_temp = {0},
                  temp_isp = {0}, res_itog = {0};
  null_big_decimal(&res);
  null_big_decimal(&temp);
  null_big_decimal(&res_temp);
  null_big_decimal(&temp_isp);
  null_big_decimal(&val1);
  null_big_decimal(&val2);
  null_big_decimal(&res_itog);

  convert_to_big(value_1, &val1);
  convert_to_big(value_2, &val2);
  normalization(&val1, &val2);
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
  } else if (is_zero_decimal(value_2) == 0)
    error = 3;
  else {
    if (sign_1 == sign_2 && sign_1 == 1)
      sign = 0;
    else
      sign = sign_2 | sign_1;
    div_bit(val1, val2, &res, &temp);
    int len = 0;
    int k = 0;
    while (is_zero_big_decimal(temp) != 0 && k < 7) {
      k++;
      mud_ten(&temp);
      len++;
      null_big_decimal(&temp_isp);
      temp_isp = temp;
      div_bit(temp_isp, val2, &res_temp, &temp);
      mud_ten(&res);
      null_big_decimal(&res_itog);
      res_itog = res;
      s21_add_bit(res_itog, res_temp, &res);
    }
    big_s21_decimal five = {0};
    five.bits[0] = 5;
    big_s21_decimal one = {0};
    one.bits[0] = 1;
    if (len == 7 && s21_is_greater_or_equal_big(res_temp, five)) {
      null_big_decimal(&temp_isp);
      temp_isp = res_temp;
      s21_add_bit(temp_isp, one, &res_temp);
      mud_ten(&res);
      null_big_decimal(&res_itog);
      res_itog = res;
      s21_add_bit(res_itog, res_temp, &res);
      len++;
    }
    set_scale_big_decimal(&res, scale_1 - scale_2 + len);
    unsigned int s = sign;
    set_sign_big_decimal(&res, s);
    error = 0;
    from_big_to_decimal(&res, result);
  }

  return error;
}