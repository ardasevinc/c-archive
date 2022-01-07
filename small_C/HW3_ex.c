#include <stdio.h>

main()
{
	int b,c,d,e;
	long a;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	while(1==1)
	{
		a = getchar();
		if (a == EOF)
		{
			++e;
			break;	
		}
		if (a >= 'a' && a <= 'z')
		{
			++c;		
		}	
		else if (a >= 'A' && a <= 'Z')
		{
			++d;
		}
		else
		{
			++e;
		}
	}	
	printf("%d\t%d\t%d",c,d,e);
}
