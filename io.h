#ifndef IO_H
#define IO_H
#include <stdbool.h>

# define CHECK(option, to_print, to_do)       \
    do {                                      \
        if (option) {                         \
        printf(to_print "\n");                \
        to_do;                                \
    }                                         \
    } while (0)                               \

#define INPUT_SIZE 200
enum ERROR_CODES {
    SUCCESS = 0,
    INVALID_POINTER,
    WRONG_INPUT
};
enum ERROR_CODES pointer_check_assert(bool someLogic);
void draw_line(int len);
enum ERROR_CODES readOperator(char *operator);
enum ERROR_CODES readNums(double *a, double *b);

#endif