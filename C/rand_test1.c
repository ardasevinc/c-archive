#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

int main()
{
  time_t timer;
  int rand_val;
  int i;
  long int seconds = time(&timer);

  srand(seconds);
  while((i = (rand() / (RAND_MAX / N+1))) != N-1)
    printf("%d\n", i);

  printf("%d\n", i);
}
