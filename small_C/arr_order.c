#include <stdio.h>

main()
{
	int m,n,k;
	
	int arr[10] = {0,1,11,3,4,5,6,7,8,9};
	
	for (m=0;m<=8;m++)
	{
		if (arr[m] > arr[m+1])
		{
			k = arr[m];
			arr[m] = arr[m+1];
			arr[m+1] = k; 
		}

	}
	for (n=0;n<=9;n++)
	{
		printf("%d\n",arr[n]);
	}
	
}

