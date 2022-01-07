#include <stdio.h>

int arraySum(int size, int arr[]);

main()
{
	int arr_size,a,sum;
	
	printf("Enter array size: ");
	scanf("%d",&arr_size);
	
	int arr[arr_size];
	
	printf("Enter the integers one by one");
	
	for(a=0; a<arr_size; a++)
	{
		scanf("%d",&arr[a]);
	}
	
	sum = arraySum(arr_size,arr);
	printf("Sum is:%d",sum);
}

int arraySum(int size, int arr[])
{
	int j,sum=0;
	
	for(j=0; j<size; j++)
	{
		sum += arr[j];
	}
	return sum;
}
