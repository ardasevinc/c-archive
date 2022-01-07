#include <stdio.h>
#include <string.h>
main()
{
	char s[100];
	printf("Enter thy string: ");
	fgets(s,100,stdin);
	printf("\n\nHere is thy string: %s",s);
}
