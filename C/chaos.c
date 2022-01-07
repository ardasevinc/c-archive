#include <stdio.h>
#include <stdlib.h>
int main()
{
  int val, i;

  for (i=0; i<15; i++){
    val = rand() % 2;
    printf("%d\n", val);
  }

  getchar();
  return 0;
}
