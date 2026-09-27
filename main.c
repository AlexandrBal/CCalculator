#include <stdio.h>

#include "compute.h"
#include "io.h"

// FIXME: make const
// #define LINE_LENGTH 20

// TODO: write C-code that reads test files
//
int main(void) {
  const int LINE_LENGTH = 20;

  line(LINE_LENGTH); // use verb in func name: draw_line / read_line

  printf("Welcome to the calculator!\nFor more information press H\n");

  line(LINE_LENGTH);

  main_calculation(); // perform_calculation / calulate_result

}

