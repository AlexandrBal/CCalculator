#include <stdio.h>
#include <string.h>

void line(int len) {
    for (int i = 0; i<len; i++) {
        printf("~*");
    }
    printf("\n");
}

int main() {
    char operator;
    double oper1, oper2;
    char input_operator[30];
    char input_nums[10000];
    line(20);

    printf("Welcome to the calculator!\nFor more information press H\n");

    line(20);

    while (true) {

        printf("Enter an operator: ");
        fgets(input_operator, sizeof(input_operator), stdin);
        input_operator[strcspn(input_operator, "\n")] = '\0';
        if (strlen(input_operator) != 1) {
            printf("Please, enter an operator without extra spaces\n");
            continue;
        }

        operator = input_operator[0];

        if (operator == 'H') {
            printf("Available operators: H, +, -, *, /, ^, N\n");
            printf("Firts enter an operator, then on the next line 2 numbers, separated by space\n");
            printf("To exit, enter N\n");
        } else if (operator == '+') {
            fgets(input_nums, sizeof(input_nums), stdin);
            sscanf(input_nums, "%lf %lf", &oper1, &oper2);
            printf("%.2lf\n", oper1+oper2);
        } else if (operator == '-') {
            fgets(input_nums, sizeof(input_nums), stdin);
            sscanf(input_nums, "%lf %lf", &oper1, &oper2);
            printf("%.2lf\n", oper1-oper2);
        } else if (operator == '*') {
            fgets(input_nums, sizeof(input_nums), stdin);
            sscanf(input_nums, "%lf %lf", &oper1, &oper2);
            printf("%.2lf\n", oper1*oper2);
        } else if (operator == '/') {
            fgets(input_nums, sizeof(input_nums), stdin);
            sscanf(input_nums, "%lf %lf", &oper1, &oper2);
            printf("%.2lf\n", oper1/oper2);
        } else if (operator == '^') {
            fgets(input_nums, sizeof(input_nums), stdin);
            sscanf(input_nums, "%lf %lf", &oper1, &oper2);
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