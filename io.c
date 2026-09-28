#include "io.h"
#include <stdio.h>
#include <math.h>

void draw_line(int len) {
    for (int i = 0; i<len; i++) {
        printf("~*");
    }
    printf("\n");
}

enum ERROR_CODES readOperator(char *operator) {
    CHECK(operator == NULL, "Invalid pointer!", return INVALID_POINTER);

    char input[INPUT_SIZE] = {0};
    char extra = '\0';

    CHECK(fgets(input, sizeof(input), stdin) == NULL, "NULL input!", return WRONG_INPUT);
    CHECK(sscanf(input, " %c %c", operator, &extra) != 1, "Please, enter exactly 1 operator!", return WRONG_INPUT);

    return SUCCESS;
}

enum ERROR_CODES readNums(double *a, double *b) {
    CHECK(a == NULL, "Invalid pointer (a==NULL)!", return INVALID_POINTER);
    CHECK(b == NULL, "Invalid pointer (b==NULL)!", return INVALID_POINTER);

    char input[INPUT_SIZE] = {0};
    char extra = '\0';

    CHECK(fgets(input, sizeof(input), stdin) == NULL, "NULL input!", return WRONG_INPUT);

    CHECK(sscanf(input, " %lf %lf %c", a, b, &extra) != 2, "Please, enter exactly 2 numbers!", return WRONG_INPUT);

    return SUCCESS;
}