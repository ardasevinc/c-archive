#include <stdio.h>

int main()
{
  int var;
  int *p;

  printf("Enter an integer: ");
  scanf("%d", &var);
  printf("\nAdress:%p\n", &var);
  printf("Value:%d\n", var);

  getchar();
  getchar();
  return 0;
}
