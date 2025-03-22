#ifndef CHECK_S21_DECIMAL_H
#define CHECK_S21_DECIMAL_H

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"
#include "../shared/utils.h"

#define TRUE 1
#define FALSE 0
#define MAX_UINT -1

#define CODE_OK 0
#define CODE_CONVERTATION_ERROR 1
#define CODE_CALCULATING_ERROR 1

Suite *test_add(void);
Suite *test_sub(void);
Suite *test_mul(void);
Suite *test_div(void);

Suite *s21_is_equal_suite();
Suite *s21_is_not_equal_suite();
Suite *s21_is_greater_suite();
Suite *s21_is_less_suite();
Suite *s21_is_less_or_equal_suite();
Suite *s21_is_greater_or_equal_suite();

Suite *s21_from_int_to_decimal_suite();
Suite *s21_from_float_to_decimal_suite();
Suite *s21_from_decimal_to_int_suite();
Suite *s21_from_decimal_to_float_suite();

Suite *s21_floor_suite();
Suite *s21_round_suite();
Suite *s21_truncate_suite();
Suite *s21_negate_suite();

#endif
