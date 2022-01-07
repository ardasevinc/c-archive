#include <stdio.h>
#include <string.h>

main()
{
	printf("Enter your string.\n");
	
	char string[1000];
	int a,b;
	
	scanf("%s",string);
	
	for (;a<strlen(string);a++)
	{
		printf("%c ",string[a]);
	}
	return 0;
}
