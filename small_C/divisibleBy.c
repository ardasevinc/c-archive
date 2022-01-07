#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Program by Arda Sevinç 260206019
// This program uses recursion and user defined functions to calculate the divisors of an integer N.
void divisibleBy(); // Function declaration.
int N,a; // Global variable declaration.

main() 
{
	printf("Ctrl-C to quit\n\n");
	divisibleBy(); // Running the function.
	return 0;
}

void divisibleBy() // Function definition.
{	
	int input;
	printf("Enter the number N:"); 
	scanf("%d",&N); // Taking the input from user.
	
	for (a=2;a<N;a++) // Loop for calculating divisors.
	{
		if ((N % a) == 0) // Using modulus to determine if user input is divisible without remainder.
			printf("\n%d is divisible by %d\n",N,a);
	}
	printf("\n");
	printf("Do you want to continue (y or n)\n\n"); 
	while (1==1) // Infinite loop to re-run the function
	{
		if (getch() == 'y')
			divisibleBy(); // Re-running using recursion.
		else
		{
			exit(0);	
		}	
			
	}
}
