#include <stdio.h>

main()
{
	int a;
	int b;
	for(a=5;a>=0;a--)
	{
		printf("%c",'&');
		printf("\n");
		for (b=3;b<=15;b++)
		{
			printf("   ");
		}
	}	
}	
