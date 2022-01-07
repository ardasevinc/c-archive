#include <stdio.h>
unsigned long long factorial(unsigned long long a);

main()
{
	unsigned long long usr_input;
	unsigned long long fact;
	
	printf("This program calculates the factorial of a number.\n\n");
	scanf("%d",&usr_input);
	
	if (usr_input < 0)
	{
		printf("no.\n");
		scanf("%d",&usr_input);
	}
	
	while (usr_input >= 25)
	{
		printf("That's... That's too much.\n\n");
		printf("--------------------------\n");
		printf("Enter again.\n");
		scanf("%d",&usr_input);
	}
	
	fact = factorial(usr_input);
	printf("%d!:%lld",usr_input,fact);
}

unsigned long long factorial(unsigned long long a)
{
	int c,b;
	b = a;
	
	if (a==0)
		return 1;
	
	for (c=1;c<b;c++)
	{
		a *= c;
	}
	return a;
}
