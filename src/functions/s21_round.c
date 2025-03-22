#include "../s21_decimal.h"
#include "../shared/utils.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int exit_code = CODE_OK;
  if (IsCorrectDecimal(&value)) {
    *result = value;
    int start_scale = get_scale_decimal(*result);
    if (start_scale > 0) {
      s21_truncate(value, result);
      s21_decimal sub_result = {{0}};
      s21_sub(value, *result, &sub_result);

      int sign = get_sign_decimal(sub_result),
          scale = get_scale_decimal(sub_result);

      set_scale_decimal(&sub_result, 0);
      set_sign_decimal(&sub_result, 0);

      big_s21_decimal big = convert_to_big_return(sub_result);
      if (scale > 1) {
        for (int i = 0; i < scale - 1; i++) {
          div_ten(&big);
        }
      }

      s21_decimal dec = {{0}};
      from_big_to_decimal(&big, &dec);
      int num = dec.bits[0];

      if (num >= 5) {
        if (sign == 1) {
          s21_decimal help = {{1, 0, 0, 0}}, res = {0};
          s21_sub(*result, help, &res);
          *result = res;
        } else {
          s21_decimal help = {{1, 0, 0, 0}}, res = {0};
          s21_add(*result, help, &res);
          *result = res;
        }
      }
    }
  } else
    exit_code = CODE_CALCULATING_ERROR;
  return exit_code;
}