#include <stdio.h>

main()
{
	double normal,fraction;
	int integer;
	normal = 12.1245;
	integer = normal;
	fraction = normal - integer;
	printf("%f\n%d\n%f",normal,integer,fraction);
}
