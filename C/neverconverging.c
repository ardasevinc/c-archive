#include <stdio.h>

int main()
{
  double val=0.0;
  long long int i, lim;

  printf("Enter the limit:");
  scanf("%lld", &lim);

  for (i=1; i<=lim; i++){
    val += (double)1/(double)i;
    printf("%lf\n", val);
  }
  printf("\nResult:%lf\n", val);

  getchar();
  getchar();

}
