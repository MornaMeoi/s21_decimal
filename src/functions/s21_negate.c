#include "../s21_decimal.h"
#include "../shared/utils.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int exit_code = CODE_OK;
  if (IsCorrectDecimal(&value)) {
    // MakeZero(result);
    *result = value;
    get_sign_decimal(*result) == 0 ? set_sign_decimal(result, 1)
                                   : set_sign_decimal(result, 0);
  } else
    exit_code = CODE_CALCULATING_ERROR;
  return exit_code;
}