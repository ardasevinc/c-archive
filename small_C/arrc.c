#include <stdio.h>

main()
{
	int arr[10],n,m;
	
	printf("Enter inputs one by one\n");
	printf("-----------------------\n");
	
	for(n=0;n<=9;n++)
	{
		scanf("%d",&arr[n]);
	}
	
	printf("Now it's time to print\n");
	printf("----------------------\n");
	
	for (m=0;m<=9;m++)
	{
		printf("array[0]=%d\n",arr[m]);
	}
	
	system("pause");
	return 0;
}
