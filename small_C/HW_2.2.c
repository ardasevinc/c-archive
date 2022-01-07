#include <stdio.h>
#include <conio.h>
// Pattern printer but direction is reversed.
// Creator: Arda Sevinç 260206019
main()
{
	int a,b; // Defining the variables.
	
	printf("Enter pattern length: "); 
	scanf("%d",&b); // Getting user input.
	
	for (a=b;a>=1;a--) // Decreasing by one while making sure that for loop operates within boundaries.
	{
		printf("%*c",(a*4),' '); // Printing a certain number of spaces. Variable 'a' decreases so spaces decrease too.
		printf("%s\n","&");      // Printing the character after spaces.
	}
	getch(); // Waiting for keyboard input to exit. Makes it so that executable doesn't closes immediately.
	return 0; // Returning 0 to show main() works correctly.
}
