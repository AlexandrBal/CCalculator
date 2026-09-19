#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "io.h"
#include "compute.h"

#define LINE_LENGTH 20


int main() {
    line(LINE_LENGTH);

    printf("Welcome to the calculator!\nFor more information press H\n");

    line(LINE_LENGTH);

    main_calculation();
}