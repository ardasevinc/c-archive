#include <stdio.h>

void recursive()
{
	printf("Recursive");
	recursive();
}

main()
{
	recursive();
}
