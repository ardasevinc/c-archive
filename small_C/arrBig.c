#include <stdio.h>

main()
{
	int m,n=0,j;
	int arr[100] = {0,1,2,3,4,5,6,7,8,9,10,11,12,24};
	
	for(m=0;m<=12;m++)
	{
		if (arr[m] < arr[m+1])
			n = arr[m+1];
		else if (arr[m] > arr[m+1])
			n = arr[m];
		else if (arr[m] = arr[m+1])
			n = arr[m];
			
	}
	printf("%d",n);
	
}
