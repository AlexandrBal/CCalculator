#include <stdio.h>

#include "io.h"
#include "compute.h"

int main(void) {
    const int LINE_LENGTH = 20;

    draw_line(LINE_LENGTH);

    printf("Welcome to the calculator!\nFor more information press H\n");

    draw_line(LINE_LENGTH);

    perform_calculation();
}