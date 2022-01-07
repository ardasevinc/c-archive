#include <stdio.h>

main()
{
	int m = 0;
	char c = 255;
	
	m = ((m=c) << 1);
	c=m;
	
	printf("\nc=%d",c);
	
}
