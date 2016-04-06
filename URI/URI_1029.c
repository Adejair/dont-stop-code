#include <stdio.h>
#include <stdlib.h>

int fib(int x, int* n_calls) {
  if(x == 0) {
    ++(*n_calls);
    return 0;
  }
  else if(x == 1) {
    ++(*n_calls);
    return 1;
  }
  else {
     ++(*n_calls);
    return (fib(x - 1, n_calls) + fib(x - 2, n_calls));
  }
}

int main() {
  int i, j = -1;
  int value;

  scanf("%i", &i);

  int* test = (int*)malloc(sizeof(int) * i);
  int* fib_Value = (int*)malloc(sizeof(int) * i);
  int* n_calls = (int*)malloc(sizeof(int) * i);

  while(++j != i) {
    scanf("%i", &value);

    n_calls[j] = -1;
    test[j] = fib(value, &n_calls[j]);
    fib_Value[j] = value;
  }

  for(j = -1; ++j != i; )
    printf("fib(%i) = %i calls = %i\n", fib_Value[j], n_calls[j], test[j]);

    free(test);
    free(fib_Value);
    free(n_calls);
}
