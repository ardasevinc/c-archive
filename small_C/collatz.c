#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Program demonstrating the collatz sequence. */
int collatz_seq(int input)
{
	if (input % 2) == 0))
	{
		return 0;
	}
	
	if (input % 2) == 1))
	{
		return 1;
	}
}
main()
{
	int a,input;
	printf("Enter thy number: ");
	scanf("%d",&input);
	while (1==1)
	{
		a = collatz_seq(input);
		if (a==1)
		{
			exit(0);
		}
	}
	return 0;
}
