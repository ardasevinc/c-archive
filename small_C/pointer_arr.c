#include <stdio.h>

main()
{
	int intArr[5];
	int a;
	
	for(a=0;a<5;a++)
	{
		printf("The adress of intArr[%d]:%u\n",a,&intArr[a]);
	}
	
	/* &arr[0] is the same as arr
	 *arr[0] is the same ass *arr */ 
}
