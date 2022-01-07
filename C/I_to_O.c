#include <stdio.h>

// copy input to outpu 1st version

int main()
{
  int c;

  c = getchar();
  while(c != EOF){  //Loop can't terminate in UNIX systems by terminal commands.
    putchar(c);
    c = getchar();
  }

}
