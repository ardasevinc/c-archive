#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char arr[100], a;
  int i=0, index=0;

  while((a=getchar()) != '0')
  {
    printf("%c", a);
  }
  printf("\n\nPress enter to exit...");
  getchar();

  return 0;
}
