#ifndef UTILS_H
#define UTILS_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

#define INCORRECT_DECIMAL_CONST \
  2130771967  // 01111111 00000000 11111111 11111111

void MakeZero(s21_decimal *dec);
void MakeSign(s21_decimal *dec, int sign);
void MakePower(s21_decimal *dec, int power);
bool IsCorrectDecimal(const s21_decimal *dec);
void SumStrings(const char *lhs, const char *rhs, char *result);
void TurnRight(char *num, int amount);
void FromDecimalToString(const s21_decimal *dec, char *result);
int CompareNumericStrings(char *lhs, char *rhs);
void DivideByTwo(char *num);
unsigned GetLast32Bits(char *num);
void FromStringToDecimal(char *num, int sign, int power, s21_decimal *result);

#endif