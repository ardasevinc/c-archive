#include <stdio.h>

main()
{
	int i;
	printf("-----ASCII TABLE-----");
	printf("\n");
	
	for (i=65; i<=90; i++) {
		printf("%d\t%c",i,i);
		printf("\n");
	}
}
