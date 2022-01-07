#include <stdio.h>
#include <math.h>
#include <complex.h>

main()
{
	double complex n = 0.0 * I;
	double complex m = 1.0 + 1.0 * I;
	printf("complex1:%fi \ncomplex2:%fi",cimag(n),cimag(m));
}
