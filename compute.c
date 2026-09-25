#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "compute.h"
#include "io.h"

bool cmp_doubles(double rhs, double lhs) {
    const double eps = 1e-5;
    return fabs(lhs - rhs) < eps;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double poww(double num1, double num2) {
    return pow(num1, num2);
}

double mult(double num1, double num2) {
    return num1 * num2;
}

double div(double num1, double num2) {
    if (cmp_doubles(num2, 0)) {
        printf("Division by 0!\n");
        return NAN;
    } else {
        return num1 / num2;
    }
}

int main_calculation(void) {
    char operator = '\0';
    double oper1 = NAN, oper2 = NAN, result = NAN;
    while (true) {

        printf("Enter an operator: ");
        enum ERROR_CODES operator_r_status = readOperator(&operator);
        if (operator_r_status != SUCCESS) {
            continue;
        }

        switch (operator)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            enum ERROR_CODES nums_r_status = readNums(&oper1, &oper2);
            if (nums_r_status != SUCCESS) {
                continue;
            }
            
            switch (operator)
            {
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
}