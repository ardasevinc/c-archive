#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
void quadEqsolver();

main()
{
	int integer;
	double delta,x1,x2,a,b,c;
	double decimal,normal;
	double x1_real,x2_real;	
	
	
	printf("Enter a:");
	scanf("%lf",&a);
	printf("\n\nEnter b:");
	scanf("%lf",&b);
	printf("\n\nEnter c:");
	scanf("%lf",&c);
	
	delta = b*b -(4*a*c);
	
	if (delta > 0)
	{	
		x1 = (-b + (double) sqrt(delta)) / (2*a);
		x2 = (-b - (double) sqrt(delta)) / (2*a);
	}
	else if (delta == 0)
	{
		x1 = (-b + (double) sqrt(delta)) / (2*a);
		x2 = x1;
		printf("\nDetected double root x1=x2\n");
	}
	else if(delta < 0)
	{
		printf("\n....No real root!\n\n");
		printf("Using my imagination......\n....\n\n");
		delta = sqrt(abs(delta));
		normal = delta;
		double complex i = (-b + normal * I) / (2*a);
		printf("x1=%lf+%lfi\n",creal(i),cimag(i));	
		printf("x2=%lf-%lfi\n",creal(i),cimag(i));
		exit(0);
	}

	printf("l%f\n",x1);
	printf("l%f\n",x2);
}

