#include <stdio.h>

int main()
{
  int i;

  for(i=0; i<=255; i++)
  {
    printf("%d\t%c\n", i, i);
  }
  printf("\n\nPress enter to exit..." );
  getchar();
}
