#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "compute.h"
#include "io.h"

#define SOFT_ASSERT(status)                                                    \
  if (status != SUCCESS) {                                                     \
    continue;                                                                  \
  }

bool cmp_doubles(double rhs, double lhs) {
  // NaN / +/- inf
  // isnan / isinf
  const double eps = 1e-5;
  return fabs(lhs - rhs) < eps;
}

double add(double num1, double num2) { return num1 + num2; }

double subtract(double num1, double num2) { return num1 - num2; }

// FIXME: why?
// naming: pow_check
double poww(double num1, double num2) {
  // soft-assert: not nans
  return pow(num1, num2);
}

double mult(double num1, double num2) { return num1 * num2; }


#define CHECK(condition, error, err_operation)                                 \
  do {                                                                         \
    if (!(condition)) {                                                        \
      printf(error);                                                           \
      (error_operation);                                                       \
    }                                                                          \
  } while (0)

double div(double num1, double num2) {
  // num2 != 0

  // assert(cmp_doubles(num2, 0) != 0);
  // TODO: check into soft-assert
  CHECK(isnan(num1), "num1 is NAN", return NAN);
  CHECK(isnan(num2), "num2 is NAN", return NAN);
  CHECK(isinf(num1), "num1 is NAN", return NAN);
  CHECK(isinf(num2), "num2 is NAN", return NAN);
  CHECK(cmp_doubles(num2, 0), "Division by 0", return NAN);

  return num1 / num2;
}

// move upwards
int main_calculation(void) {
  char operator = 0; // char = 1 byte; A = 60, B = 61; '\0' = 0

  double oper1 = NAN, oper2 = NAN, result = NAN;

  while (true) {

    printf("Enter an operator: ");
    SOFT_ASSERT(readOperator(&operator))
    // else {
    // }

    switch (operator) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      SOFT_ASSERT(readNums(&oper1, &oper2))

      switch (operator) {
      case '+':
        result = add(oper1, oper2);
        break;

      case '-':
        result = subtract(oper1, oper2);
        break;

      case '*':
        result = mult(oper1, oper2);
        break;

      case '/':
        result = div(oper1, oper2);
        if (isnan(result)) {
          continue;
        }
        break;

      case '^':
        result = poww(oper1, oper2);
        break;
      }

      printf("%.2f\n", result);
      break;

    case 'H':
      printf("Available operators: H, +, -, *, /, ^, N\n");
      printf("First enter an operator, then enter two numbers\n");
      printf("To exit, enter N\n");
      break;

    case 'N':
      printf("Thank you! Good day!");
      return 0;

    default:
      printf("Unknown operator.\n");
      break;
    }
  }

  // dispatch-cmd
  switch (operator) {
  case 'H':
    printf("Available operators: H, +, -, *, /, ^, N\n");
    printf("First enter an operator, then enter two numbers\n");
    printf("To exit, enter N\n");
    break;

  case 'N':
    printf("Thank you! Good day!");
    return 0;
  }

  // dispatch-operator
  switch (operator) {
  case '+':
    result = add(oper1, oper2);
    break;

  case '-':
    result = subtract(oper1, oper2);
    break;

  case '*':
    result = mult(oper1, oper2);
    break;

  case '/':
    result = div(oper1, oper2);
    if (isnan(result)) {
      continue;
    }
    break;

  case '^':
    result = poww(oper1, oper2);
    // if (isnan(result)) { //
    //     continue;
    // }
    break;

  case 'l':
    result = poww(oper1, oper2);
    break;
  default:
    printf("unknow");
  }

  if (isnan(result)) {
    // print error
  }
}
