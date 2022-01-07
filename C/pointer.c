#include <stdio.h>

int main()
{
  int* c;
  int pc = 22;
  c = &pc;

  printf("%u\n", c);
  printf("%d\n", *c);Y

  getchar();
  getchar();
  return 0;
}
