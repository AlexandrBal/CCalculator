#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "compute.h"
#include "io.h"

# define NAN_INF_CHECK(arg1, arg2, arg1_name, arg2_name)      \
    do {                                                      \
        CHECK(isnan(arg1), arg1_name " in NaN!", return NAN); \
        CHECK(isnan(arg2), arg2_name " in NaN!", return NAN); \
        CHECK(isinf(arg1), arg1_name " in inf!", return NAN); \
        CHECK(isinf(arg2), arg2_name " in inf!", return NAN); \
    } while (0)                                               \

int perform_calculation(void) {
    char operator = '\0';
    double oper1 = NAN, oper2 = NAN, result = NAN;
    bool is_working = true;
    while (true) {

        printf("Enter an operator: ");
        if (readOperator(&operator) != SUCCESS) {
            continue;
        }

        if (strchr("+-*/^", operator)) {
            if (readNums(&oper1, &oper2) != SUCCESS) {
                continue;
            }
            dispatch_operator(operator, oper1, oper2, &result);
            if (!isnan(result)) {
                printf("%.2f\n", result);
            }
        } else if (strchr("HN", operator)) {
            dispatch_cmd(operator, &is_working);
        } else {
            printf("Unknown operator\n");
        }

        if (!is_working) {
            return 0;
        }
    }
}

bool cmp_doubles(double rhs, double lhs) {
    NAN_INF_CHECK(rhs, lhs, "rhs", "lhs");
    const double eps = 1e-5;
    return fabs(lhs - rhs) < eps;
}

double add(double num1, double num2) {
    NAN_INF_CHECK(num1, num2, "num1", "num2");
    return num1 + num2;
}

double subtract(double num1, double num2) {
    NAN_INF_CHECK(num1, num2, "num1", "num2");
    return num1 - num2;
}

double pow_check(double num1, double num2) {
    NAN_INF_CHECK(num1, num2, "num1", "num2");
    return pow(num1, num2);
}

double mult(double num1, double num2) {
    NAN_INF_CHECK(num1, num2, "num1", "num2");
    return num1 * num2;
}

double div(double num1, double num2) {
    NAN_INF_CHECK(num1, num2, "num1", "num2");
    CHECK(cmp_doubles(num2, 0), "Division by 0!", return NAN);

    return num1 / num2;

}

void dispatch_cmd(char operator, bool *is_working) {
    switch (operator) {
    case 'H':
        printf("Available operators: H, +, -, *, /, ^, N\n");
        printf("First enter an operator, then enter two numbers\n");
        printf("To exit, enter N\n");
        break;

    case 'N':
        printf("Thank you! Good day!");
        *is_working = false;
        break;
    }
}

void dispatch_operator(char operator, double oper1, double oper2, double *result) {
    switch (operator) {
    case '+':
        *result = add(oper1, oper2);
        break;

    case '-':
        *result = subtract(oper1, oper2);
        break;

    case '*':
        *result = mult(oper1, oper2);
        break;

    case '/':
        *result = div(oper1, oper2);
        break;

    case '^':
        *result = pow_check(oper1, oper2);
        break;
    }
}