#include <stdio.h>
#include <stdlib.h>

main()
{
	int i,num;
	
	int *arr;
	
	printf("Enter total number of elements(1 to 100):");
	scanf("%d",&num);
	
	arr = (int*) calloc(num, sizeof(int));
	
	if (arr == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(0);	
	}
	
	printf("\n");
	
	for(i=0;i<num;i++)
	{
		printf("Enter number %d:",i+1);
		scanf("%d",(arr+i));		
	}
	for(i=0;i<num;i++)
	{
		printf("%d\n",*(arr+i));
	}
	
		
}


