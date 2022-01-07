#include <stdio.h>

int power(int, int);

main()
{
	int m, n, result;
	
	printf("Enter\n");
	scanf("%d %d", &m, &n);
	
	result = power(m, n);
	printf("\n Result:%d",result);
}

int power(int input, int power)
{
	int i,temp;
	temp = input;
	for(i=1; i<power; i++)
	{
		input = input * temp;
		
	}
	return input;
}
