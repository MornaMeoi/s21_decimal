#include "../s21_decimal.h"
#include "../shared/utils.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int exit_code = CODE_OK;
  if (IsCorrectDecimal(&value)) {
    *result = value;
    int sign = get_sign_decimal(*result), scale = get_scale_decimal(*result);
    if (scale > 0) {
      if (sign == 1) set_sign_decimal(result, 0);
      big_s21_decimal big = convert_to_big_return(*result);
      for (int i = 0; i < scale; i++) {
        div_ten(&big);
      }
      from_big_to_decimal(&big, result);
      if (sign == 1) set_sign_decimal(result, 1);
    }
  } else
    exit_code = CODE_CALCULATING_ERROR;
  return exit_code;
}