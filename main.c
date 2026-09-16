#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 200

void line(int len) {
    for (int i = 0; i<len; i++) {
        printf("~*");
    }
    printf("\n");
}

bool readOperator(char *operator) {
    char input[INPUT_SIZE];
    char extra;

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    if (sscanf(input, " %c %c", operator, &extra) != 1) {
        printf("Please, enter exactly 1 operator!\n");
        return false;
    }

    return true;
}

bool readNums(double *a, double *b) {
    char input[INPUT_SIZE];
    char extra;

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    if (sscanf(input, " %lf %lf %c", a, b, &extra) != 2) {
        printf("Please, enter exactly 2 numbers!\n");
        return false;
    }

    return true;
}

int main() {
    char operator;
    double oper1, oper2;

    line(20);

    printf("Welcome to the calculator!\nFor more information press H\n");

    line(20);

    while (true) {

        printf("Enter an operator: ");
        if (!readOperator(&operator)) {
            continue;
        }

        if (operator == 'H') {
            printf("Available operators: H, +, -, *, /, ^, N\n");
            printf("First enter an operator, then on the next line 2 numbers, separated by space\n");
            printf("To exit, enter N\n");
        } else if (operator == '+') {
            if (!readNums(&oper1, &oper2)) {
                continue;
            }
            printf("%.2lf\n", oper1+oper2);
        } else if (operator == '-') {
            if (!readNums(&oper1, &oper2)) {
                continue;
            }
            printf("%.2lf\n", oper1-oper2);
        } else if (operator == '*') {
            if (!readNums(&oper1, &oper2)) {
                continue;
            }
            printf("%.2lf\n", oper1*oper2);
        } else if (operator == '/') {
            if (!readNums(&oper1, &oper2)) {
                continue;
            }
            printf("%.2lf\n", oper1/oper2);
        } else if (operator == '^') {
            if (!readNums(&oper1, &oper2)) {
                continue;
            }
            double res = 1;
            for (int i=0; i<oper2; i++) {
                res *= oper1;
            }
            printf("%.2lf\n", res);
        } else if (operator == 'N') {
            printf("Thank you! Good day!");
            break;
        }
    }
}