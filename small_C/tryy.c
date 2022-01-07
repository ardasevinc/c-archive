#include <stdio.h>

main()
{
	double m,n;
	n = 0;
	for(m=0;m<=99000;m++)
	{
		n = (1 + 1/m)^m;	
	}
	printf("%f",n);
		
}
