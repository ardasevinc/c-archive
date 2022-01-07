#include <stdio.h>

main()
{
	int a,input;
	
	printf("Enter thy number\n");
	scanf("%d",&input);
	
	if (input==2)
		printf("prime\n");
	else
	{
		for(a=2;a <= input - 1;a++)
		{
			if (input % a == 0)
				printf("Not prime\n");
				break;
			if (a != input)
				printf("Not prime,\n");
			else
				printf("Prime.\n");
		}
	}
	return 0;
}
