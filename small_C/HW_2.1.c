#include <stdio.h>
#include <conio.h>
// Pattern printer
// Creator: Arda Sevinç 260206019
main()
{
	int a,b,c; //Defining variables.
	
	printf("Enter the pattern lenght: ");
	scanf("%d",&c);  // Getting the input from user.
	
	for (a=1;a<=c;a++) // Making it so that the loop iterates between a and c while incrementing by one.
	{
		printf("%s\n","&"); // Printing the pattern.
		for (b=1;b<=a;b=b+1) // Printing a certain number of spaces and making sure this for loop works in sync with the other one.
		{
			printf("%*c",4,' '); // Printing the spaces.
		}
	}
	getch(); // Executable closes immediately and we need to analyze the output so we wait for keyboard input to exit the program.
	return 0;
}
