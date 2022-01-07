#include <stdio.h>

int main()
{
	char arr[1000];
	int i;
	
	printf("Enter thy string.\n");
	scanf("%s",arr);
	
	for (i=0;arr[i] != '\0';i++);
	
	printf("Length of thy string: %d\n",i);
	return 0;
}
