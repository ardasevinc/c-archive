#include <stdio.h>

unsigned long long int factorial(int fact);

long long int power(int n, int i);

main()
{
	int input,m,factorial1,power1;
	
	printf("Enter:");
	scanf("%d",&input);
	scanf("%d",&m);
	
	factorial1 = factorial(input);
	power1 = power(input,m);
	printf("\n%ld",power1);
	
}

unsigned long long int factorial(int fact)
{
	int i;
	
	for(i=1; i<fact; i++)
	{
		fact *= i;
	}
	return fact;
	
}

long long int power(int n, int i)
{
	int a, temp=n;
	
	
	for(a=1; a<i; a++)
	{
		n *= temp;
	}
	
	return n;
}
