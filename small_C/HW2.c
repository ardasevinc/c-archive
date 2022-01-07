#include <stdio.h>
// Program by Arda Sevinç - 260206019
main()
{
	int N,a;
	
	printf("Ctrl-C to exit\n\n");
	
	while (1==1)
	{
		printf("Please enter the number N:");
		scanf("%d",&N);
	
		for (a=2;a<N;a++)
		{
			if ((N % a) == 0)
				printf("\n%d is divisible by %d\n",N,a);
		}
		printf("\n\n");
	}
	return 0;
}
