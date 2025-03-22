#include <stdlib.h>

#include "../s21_decimal.h"
#include "../shared/utils.h"

#define CODE_OK 0
#define CODE_CONVERTATION_ERROR 1

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int exit_code = CODE_OK;
  MakeZero(dst);
  MakeSign(dst, src < 0 ? 1 : 0);
  dst->bits[0] = abs(src);
  return exit_code;
}
