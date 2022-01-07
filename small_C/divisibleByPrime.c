#include <stdio.h>
#include <stdlib.h>
// Program by Arda Sevinç 260206019
// This program uses recursion and user defined functions to calculate the divisors of an integer N.
// Also checks for prime.
void divisibleBy(); // Function declaration.
int primalityCheck(int M); // Function declaration.
int N,a,b; // Global variable declaration.

main() 
{
	printf("Ctrl-C to quit\n\n");
	divisibleBy(); // Running the function.
}

void divisibleBy() // Function definition.
{	
	int count=0; // Setting "count" to 0 to count.
	printf("Enter the number N:"); 
	scanf("%d",&N); // Taking input from user.
	
	if (N<0)
	{
		printf("Please do not enter negative integers.\n\n");
		printf("-------------------\n");
		divisibleBy();
	}
		
	if (N == 1) // Special case.
	{
		printf("\n%d is divisible by %d\n",N,N);
		printf("....%d has %d divisors\n\n",N,N);
		printf("-------------------\n");
		divisibleBy();
	}
	
	if (primalityCheck(N) == 1) // If prime, do that etc..
	{
		printf("\n%d Is PRIME!\n\n",N);
		printf("-------------------\n");
		divisibleBy(); // Recursion. Re-running the function.
	}
	
	for (a=2;a<N;a++) // Loop the point out the divisors.
	{
		if ((N % a) == 0) // Diving N to a and checking if modulus gives 0.
		{
			printf("\n%d is divisible by %d\n",N,a);
			++count; // Counting divisors.
		}
	}
	printf("\n....%d has %d divisors\n\n",N,count);
	printf("-------------------\n"); // Style.
	divisibleBy(); // Recursion. Re-running the function.
}

int primalityCheck(int M) // Prime checker function definition.
{
	int j;
	
	if (M==0) // Special case.
		return 0; 
	if (M==2) // Special case.
		return 1;
	else if (M==1)  // Special case.
		return 0;	
	else
	{
		for (j=2;j<=M-1;j++) // Loop for determining primality
		{
			if ((M % j) == 0 && M != j) // Checking if said number has divisors excluding 1 and the number itself.
				return 0;
		}
		return 1; // Returning 1 if loop exits. (prime = 1, non prime = 0)
	}
}
