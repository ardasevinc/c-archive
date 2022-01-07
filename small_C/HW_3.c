#include <stdio.h>
#include <conio.h>
// Character counter. This program doesn't count EOF character.
// Usage: Enter data, press enter then use ctrl-Z and press enter.
// Program will count the newline you enter before inputting EOF.
// Creator: Arda Sevinç 260206019
main()
{
	long input; // Defining variables. 
	int cap,small,other;
	cap = 0;
	small = 0;
	other = 0;
	
	printf("Please enter your text, press enter, then use ctrl-Z and press enter again.\n");
	
	while (1==1) // Only exit is which input equals EOF.
	{
		input = getchar(); // We get the characters one by one. 
		if (input == EOF)
		{
			break; // Loop will break if EOF is submitted.
		}
		if (input >= 'a' && input <= 'z') // Checking for small letters.
		{
			++small; //Increase by one
		}
		else if (input >= 'A' && input <= 'Z') // Checking for capital letters.
		{
			++cap;
		}
		else
		{
			++other; // Other characters are counted.
		}
	}  
	printf("Total number of capital letters:\t\t%d",cap);               // Printing
	printf("\nTotal number of small letters:\t\t\t%d",small);
	printf("\nTotal number of other characters(Excluding EOF):%d\n",other);
	
	getch(); // Making the program wait for input to analyze the executable.
	return 0; // Returning 0 to make sure we got the main() working.
}
