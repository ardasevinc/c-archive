#include <stdio.h>

void bit_set(int bit, unsigned short int *byte);

int main()
{
  int bit;
  unsigned short int byte;

  printf("Move what to where?");
  scanf("%hu %d", &byte, &bit);
  bit_set(bit, &byte);
  printf("%d\n", byte);

  getchar();
  printf("\n\nPress enter to exit...");
  getchar();
}

void bit_set(int bit, unsigned short int *byte)
{
  bit = 1 << bit;
  *byte = *byte | bit;
}
