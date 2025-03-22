#include "../../s21_decimal.h"

void null_decimal(s21_decimal* dec) {
  dec->bits[0] = 0;
  dec->bits[1] = 0;
  dec->bits[2] = 0;
  dec->bits[3] = 0;
}