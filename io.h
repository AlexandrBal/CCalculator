#ifndef IO_H
#define IO_H
#include <stdbool.h>

#define INPUT_SIZE 200
enum ERROR_CODES {
    SUCCESS = 0,
    INVALID_POINTER,
    WRONG_INPUT
};
enum ERROR_CODES pointer_check_assert(bool someLogic);
void line(int len);
enum ERROR_CODES readOperator(char *operator);
enum ERROR_CODES readNums(double *a, double *b);

#endif