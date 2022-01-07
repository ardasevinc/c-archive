#include <stdio.h>

main()
{
	int a;
	char b;
	long c;
	long long d;
	short e;
	a = 1;
	b = 1;
	c = 1;
	d = 1;
	e = 1;
	printf("%s:%d \n %s:%d \n %s:%d \n %s:%d \n %s:%d \n "," int",sizeof(a),"char",sizeof(b),"long",sizeof(c),"long long",sizeof(d),"short",sizeof(e));
	return 0;
}
