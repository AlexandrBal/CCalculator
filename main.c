#include <stdio.h>

#include "io.h"
#include "compute.h"

#define LINE_LENGTH 20

int main(void) {
    line(LINE_LENGTH);

    printf("Welcome to the calculator!\nFor more information press H\n");

    line(LINE_LENGTH);

    main_calculation();
}