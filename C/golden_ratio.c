#include <stdio.h>

int fibonacci(int n);
void golden_ratio();

int main()
{
  golden_ratio();

  return 0;
}

int fibonacci(int n)
{
  if (n == 0 || n == 1)
    return n;
  else
    return fibonacci(n-1) + fibonacci (n-2);
}

void golden_ratio()
{
  double golden = 0;
  int n = 2;
  while(1){
    golden = (double)fibonacci(n) / (double)fibonacci(n-1);
    printf("%lf\n", golden);
    n++;
  }
}
