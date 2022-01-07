#include <stdio.h>
#include <stdlib.h>
int primalityCheck(int M);

main()
{
	int N,a;
	
	printf("Input:");
	scanf("%d",&N);
	a = primalityCheck(N);
		
	if (a == 1)
	{
		printf("....PRIME!!!\n");
	}
	
	else if (a == 0)
	{
		printf("....lol\n");	
	}
}

int primalityCheck(int M)
{
	int j;
	
	if (M==2)
		return 1;
	else if (M==1)
		return 0;	
	else
	{
		for (j=2;j<=M-1;j++)
		{
			if ((M % j) == 0 && M != j)
				return 0;
		}
		return 1;
	}
}
