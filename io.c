#include "io.h"
#include <stdio.h>
#include <math.h>

void line(int len) {
    for (int i = 0; i<len; i++) {
        printf("~*");
    }
    printf("\n");
}

enum ERROR_CODES pointer_check_assert(bool someLogic) {
    if (someLogic == true) {
        return INVALID_POINTER;
    }
    return SUCCESS;
}

enum ERROR_CODES readOperator(char *operator) {
    enum ERROR_CODES state = pointer_check_assert(operator == NULL);
    if (state == INVALID_POINTER) {
        printf("Invalid pointer!\n");
        return INVALID_POINTER;
    }

    char input[INPUT_SIZE] = {0};
    char extra = '\0';

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return WRONG_INPUT;
    }

    if (sscanf(input, " %c %c", operator, &extra) != 1) {
        printf("Please, enter exactly 1 operator!\n");
        return WRONG_INPUT;
    }

    return SUCCESS;
}

enum ERROR_CODES readNums(double *a, double *b) {
    enum ERROR_CODES state = pointer_check_assert(a == NULL && b == NULL);
    if (state == INVALID_POINTER) {
        print("Invalid pointer!\n");
        return INVALID_POINTER;
    }

    char input[INPUT_SIZE] = {0};
    char extra = '\0';

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return WRONG_INPUT;
    }

    if (sscanf(input, " %lf %lf %c", a, b, &extra) != 2) {
        printf("Please, enter exactly 2 numbers!\n");
        return WRONG_INPUT;
    }

    return SUCCESS;
}