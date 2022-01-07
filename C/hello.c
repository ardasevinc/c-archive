#include <stdio.h>


void printHello();

int main()
{
  printf("Hello, World\n");
  printHello();

  for(int i=0; i<5; i++)
  {
    printf("Hello!\n");
  }

  printf("Press enter to continue...");
  getchar();
}

void printHello()
{
  printf("Hello world!!!\n");
}
