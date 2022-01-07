#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char arr[100], a, n;
  int i=0, index=0;

  while(1)
  {
    a = getchar();
    printf("%c", a);
    if (a == ' ')
    {
      getchar();
      break;
    }
  }
  printf("\n\nPress enter to exit...");
  getchar();

  return 0;
}
