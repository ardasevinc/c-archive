#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned short int bit_set(int pos);
short int read_bit(unsigned short int byte2, int pos);

int main()
{
  unsigned short int test1;
  int pos, bit_arr[16], val, i;

  printf("This program  diplays a positive integer in 16 bit binary\n\n");
  printf("Enter a positive number:");
  scanf("%hu", &test1);

  for(i=0; i<16; i++)
  {
    bit_arr[i] = 0;
  }
  for (i=15; i>=0; i--)
  {
    bit_arr[i] = read_bit(test1, 15-i);
  }

  for(i=0; i<16; i++)
  {
    printf("%d", bit_arr[i]);
  }

  getchar();
  printf("\n\nPress enter to exit...");
  getchar();
  return 0;
}

unsigned short int bit_set(int pos)
{
  unsigned short int mask = 0;

  pos = 1 << (pos);

  return (pos | mask);
}

short int read_bit(unsigned short int byte2, int pos)
{

  if((byte2 >>= pos) & 1)
    return 1;
  else
    return 0;
}
