//#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 200

void line(int len) {
  for (int i = 0; i < len; i++) {
    printf("~*");
  }
  printf("\n");
}

enum ERROR_CODES {
  INVALID_POINTER = 0,
  WRONG_INPUT = 1,
};

bool readOperator(char *operator) {
  assert(operator != NULL); // re-write assert to gracefully exit function,
                            // instead of killing the whole program
    
  soft_assert(operator != NULL, INVALID_POINTER);

  // if (operator != NULL) {
  //   printf("Error");
  //   // abort(); -> INVALID_PTR
  //   return INVALID_POINTER;
  // }

  char input[INPUT_SIZE]; // uinint value
  char extra;

  if (fgets(input, sizeof(input), stdin) == NULL) {
    return false;
  }

  // FIXME, why not scanf from stdin
  // getchar() == getc(stdin)
  //
  if (sscanf(input, " %c %c", operator, &extra) != 1) { 
    printf("Please, enter exactly 1 operator!\n");
    
    // cleaning stdin from users' trash
    while (/*???*/) {
      int char = getchar();
    }
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

// perfect main example:
// int main() {
//         input_data();
//
//         process_data1();
//         process_data2();
//
//         output_data();
// }

// TODO: move up
int main() {
  // TODO: uninit value!
  // garbage
  char operator;

  double oper1, oper2, result; // NaN
  const int line_len = 20;

  line(20); // magic const

  printf("Welcome to the calculator!\nFor more information press H\n");

  line(20);

  while (true) {

    printf("Enter an operator: ");
    if (!readOperator(&operator)) {
      continue;
    }

    // TODO:  move to func
    switch (operator) {

    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      if (!readNums(&oper1, &oper2)) {
        continue;
      }

      switch (operator) {
      // case 'sin':
      //  sin(x) = x + x^3 / 3 + x^5 / 120 + ...
      case '+':
        result = oper1 + oper2; // TODO move to func
        break;

      case '-':
        result = oper1 - oper2;
        break;

      case '*':
        result = oper1 * oper2;
        break;

      case '/':             // M * 2 ^ E: M,E
        if (oper2 == 0.0) { // FIXME: bug! You can not comapre float with '=='
                            // cmp_doubles(oper2, 0);
          printf("Division by 0!\n");
          continue;
        } else {
          result = oper1 / oper2;
        }
        break;

      case '^':
        result = 1;
        for (int i = 0; i < oper2; i++) { // use pow(num, power);
          result *= oper1;
        }
        break;

      default:
        break;
      }

      printf("%.2f\n", result);
      break;

    case 'H':
      printf("Available operators: H, +, -, *, /, ^, N\n");
      printf("First enter an operator, then enter two numbers\n");
      printf("To exit, enter N\n");
      break;

    case 'N':
      printf("Thank you! Good day!");
      return 0;

    default:
      printf("Unknown operator.\n");
      break;
    }
  }
}

// FIXME: tests
// FIXME: Readme
// FIXME: split into files (header files + src files):
//  main.c -> main
//  compute.c -> computation
//  io.c -> i/o funcs
//  test.c -> tests

// FIXME: build system
// build.sh / build.bat
//
// Makefile
// 

// bool cmp_doubles(double lhs, double rhs) {
//   const double eps = 1e-5; // 0.000001
//   //
//   // |lhs - rhs| < eps
//   //
//   return fabs(lhs, rhs) < eps;
// }

