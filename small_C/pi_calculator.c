#include <stdio.h>

main()
{
	double plus,minus,total;
	long long step,step2;
	for (step=1;step<=20000000;step=step+4)
	{
		plus = plus + 4.0/step;	
	}
	for (step2=3;step2<=20000000;step2=step2+4)
	{
		minus = minus - 4.0/step2;
	}
	
	total = plus + minus;
	printf("%.20f\n",total);
	system("pause");
	return 0;	
}

