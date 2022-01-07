#include <stdio.h>

void test(int, int);

int main()
{
  int a, b;

  printf("Enter a:");
  scanf("%d", &a);
  printf("Enter b:");
  scanf("%d", &b);

  test(a, b);

  printf("\na:%d", a);
  printf("\nb:%d", b);
  getchar();
  printf("\n\nPress enter to exit...");
  getchar();
}

void test(int a, int b)
{
  a = 5;
  b = 20;
}
