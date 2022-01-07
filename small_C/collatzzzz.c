#include <stdio.h>
#include <stdlib.h>
int collatz(int input)
{
	while (1==1)
	{
		if (input % 2 == 0)
		{
			input = input / 2;
			printf("\n%d",input);
			if (input == 1)
			{
				exit(0);
			}
		}
		if (input % 2 != 0)
		{
			input = (3*input) + 1;
			printf("\n%d",input);
		}
	}
	printf("%d",input);
}

int main()
{
	int usr_input;

	printf("Enter thy number: ");
	scanf("%d",&usr_input);

	collatz(usr_input);

	getchar();
	return 0;
}
