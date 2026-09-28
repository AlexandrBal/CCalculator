#ifndef COMPUTE_H
#define COMPUTE_H
#include <stdbool.h>

int perform_calculation(void);
bool cmp_doubles(double rhs, double lhs);
double add(double num1, double num2);
double subtract(double num1, double num2);
double pow_check(double num1, double num2);
double mult(double num1, double num2);
double div(double num1, double num2);
void dispatch_cmd(char operator, bool *is_working);
void dispatch_operator(char operator, double oper1, double oper2, double *result);

#endif