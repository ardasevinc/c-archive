#include <stdio.h>
//Function example by Arda Sevinç
int prime_check(long int x);


main()
{
	long int input;
	
	printf("Prime checker V1\n");
	while(1)
	{
		printf("Enter input:");
		scanf("%d",&input);
		printf("\n----------------\n");
	
		if (prime_check(input) == 1)
			printf("Congratulations, you have a prime.\n");
	
		else if(prime_check(input) == 0)
			printf("I'm sorry :()\n");
	}
	return 0;
}

int prime_check(long int x)
{
	int a;
	
	if (x == 0 || x == 1)
		return 0;
	else if (x == 2)
		return 1;
		
	else
	{
		for (a=2;a<=x;a++)
		{
			if (x % a == 0)
				return 0;
			if ( a == x)
				return 0;
			else
				return 1;
		}
	}
}

