#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_VALUE 100

int fib_cache[MAX_INPUT_VALUE];

int fibonacci(int n);
int fibonacci_cache(int n);

int main(int argc, char *argv[]) {

  char *num = argv[1];
  char *choice = argv[2];
  int number = atoi(num);

  FILE *file = fopen(argv[3], "r");

  char line[10];
  fgets(line, 10, file);

  int num_from_file = atoi(line);
  int total = number + num_from_file;

  char iter = 'i';
  if (*choice == iter) {
    int x = 0;
    int y = 1;
    for (int i = 0; i < total; i++) {

      int temp = x + y;

      x = y;
      y = temp;
    }
    printf("%d ", x);
  }

  char recur = 'r';
  if (*choice == recur) {
    for (int i = 0; i < total; i++) {
      fibonacci(i);
    }
    printf("%d ", fibonacci(total));
  }

  char cach = 'c';
  if (*choice == cach) {
    printf("%d", fibonacci_cache(total - 1));
  }

  return 0;
}

int fibonacci(int num) {
  if (num == 0) {
    return 0;
  }

  if (num == 1) {
    return 1;
  }

  return (fibonacci(num - 1) + fibonacci(num - 2));
}

int fibonacci_cache(int num) {
  if (num <= 1) {
    return 1;
  }

  // if in the cache, return it directly
  if (fib_cache[num] != 0) {
    return fib_cache[num];
  }

  int result = fibonacci_cache(num - 1) + fibonacci_cache(num - 2);

  fib_cache[num] = result;

  return result;
}
