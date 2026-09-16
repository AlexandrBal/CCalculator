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
    double oper1, oper2, result;

    line(20);

    printf("Welcome to the calculator!\nFor more information press H\n");

    line(20);

    while (true) {

        printf("Enter an operator: ");
        if (!readOperator(&operator)) {
            continue;
        }

        switch (operator)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if (!readNums(&oper1, &oper2)) {
                continue;
            }
            
            switch (operator)
            {
            case '+':
                result = oper1 + oper2;
                break;
            
            case '-':
                result = oper1 - oper2;
                break;
            
            case '*':
                result = oper1 * oper2;
                break;
            
            case '/':
                if (oper2 == 0.0) {
                    printf("Division by 0!\n");
                    continue;
                } else {
                    result = oper1 / oper2;
                }
                break;

            case '^':
                result = 1;
                for (int i = 0; i < oper2; i++) {
                    result *= oper1;
                }
                break;
                
            default:
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