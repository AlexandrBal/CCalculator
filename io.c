#include "io.h"
#include <stdio.h>

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