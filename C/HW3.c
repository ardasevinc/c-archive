#include <stdio.h>

unsigned short int bit_set(int pos);
short int read_bit(unsigned short int byte2, int pos);
int fibonacci(int n);
unsigned short int generateMask(int n);
void binary_to_arr(unsigned short int binary, short int array*);
unsigned short int message_generate(int n);

short int arr[16];

int main()
{
  int i, var;
  unsigned short int test = 0, test1=0;

  printf("Enter index number of fibonacci:");
  scanf("%d", &var);

  test = message_generate(var);
  binary_to_arr(test);

  for(i=0; i<16; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");
  getchar();
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

int fibonacci(int n)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

void binary_to_arr(unsigned short int binary, short int array*)
{
  int i;

  for(i=15; i>=0; i--)
  {
      array[i] = read_bit(binary, 15-i);
  }
}
