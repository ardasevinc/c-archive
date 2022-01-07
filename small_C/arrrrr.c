#include <stdio.h>

main()
{
	int arr[5] = {1,2,3,4,5};
	char string[] = "Arda";
	int a=5;
	printf("sizeof(arr): %d\tsizeof(&arr): %d",sizeof(arr),sizeof(&arr)); // An example of pointers and arrays.
	printf("\nsizeof(arr[0]): %d",sizeof(arr[0]));
	printf("\npointer(string[0]): %d\nvalue(string[0]): %d",&string[0],string[0]);
	return 0;
}
