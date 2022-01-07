#include <stdio.h> // Standart library of input and output.
#include <math.h> // Math library. We need the sqrt func.
#include <stdlib.h> // standart library for some functions we need.
#include <complex.h> // Complex library for complex numbers.
#include <unistd.h> // Need this library to use sleep() func.
// Program by Arda Sevinç 260206019
void quadEqsolver(); // Quadratic equation solving function declaration.

main()
{
	printf("Program will start shortly. Ctrl-C to exit.\n");
	printf("-------------------------------------------\n"); // Style.
	quadEqsolver(); // Running the function.
}

void quadEqsolver() // Quadratic equation solving function definition.
{
	double delta,x,y,x1,x2,a,b,c; // Necessary variable initializations.
	
	
	printf("Input a:");
	scanf("%lf",&a);
	printf("\nInput b:");   // Taking inputs from user.
	scanf("%lf",&b);
	printf("\nInput c:");
	scanf("%lf",&c);
	
	printf("\n-------------------------------------------\n"); // Style.
	printf("%lf*(x^2) + (%lf*x) + (%lf)\n", a, b, c); // Printing the quadratic equation.
	
	
	delta = b*b - (4*a*c); // Discriminant.
	
	if (delta > 0) // Real roots.
	{
		printf("Two distinct real roots detected!\n\n");
		
		x1 = (-b + (double) sqrt(delta)) / (2*a); // Identifying the formulas and computing the roots. 
		x2 = (-b - (double) sqrt(delta)) / (2*a);
		
		x = x1;
		y = a*(x*x) + (b*x) + c; // Computing f(x1).
		
		printf("f(%lf)=%lf\n",x1,y); // Printing f(x1).
		
		x = x2;
		y = a*(x*x) + (b*x) + c; // Computing f(x1).
		
		printf("f(%lf)=%lf\n",x2,y); // Printing f(x2).
	}
	
	else if (delta == 0) // Same real roots. AKA double root.
	{
		printf("Double root detected \n\n"); 
		
		x1 = (-b + (double) sqrt(delta)) / (2*a); // Formula definition and root computation.
		x2 = x1;
		
		y = a*(x*x) + (b*x) + c; // Computing f(x1).
		x = x1;
		
		printf("f(%lf)=%lf\n",x1,y);
	}
	
	else if (delta < 0) // Imaginary roots.
	{
		delta = (double)sqrt(abs(delta)); // Computing the value of delta in this case.
		
		double complex i = (-b + delta * I) / (2*a); // Declaring the complex number i.
		
		printf("-------------------------------------------\n"); // Styling the code.
		printf("Imaginary root detected!\n");
		printf("Using imagination!!!!!\n");  // A little joke won't harm a programmer.
		printf("-------------------------------------------\n"); // Style.
		
		printf("x1=%lf + (%lfi)\n",creal(i),cimag(i)); // Printing the first root.Creal means the real part vice versa. 
		
		if (cimag(i) < 0) // minus and plus sign conflict at this particular case.
		{
			printf("x2=%lf + (%lfi)\n",creal(i),cimag(i)); // Printing the complex number with the right signs.
			quadEqsolver(); // Re-run the function.
		}
		
		printf("x2=%lf + (-%lfi)\n",creal(i),cimag(i)); // Printing the second root.
		
		printf("-------------------------------------------\n\n");
		printf("R ");
		sleep(1);
		printf("E ");
		sleep(1);         // Beautiful reboot of the function.
		printf("B ");
		sleep(1);
		printf("O ");
		sleep(1);
		printf("O ");
		sleep(1);
		printf("T ");
		sleep(1);
		printf("!\n");
		printf("-------------------------------------------\n\n");
		
		quadEqsolver(); // Re-running the function using recursion.
	}
	printf("-------------------------------------------\n");
	
	printf("x1=%lf\n",x1);
	printf("x2=%lf\n",x2);  // Styling and printing the roots when delta >= 0.
	
	printf("-------------------------------------------\n\n");
	
	printf("R ");
	sleep(1);
	printf("E ");
	sleep(1);
	printf("B ");
	sleep(1);
	printf("O ");  // Beautiful reboot of the function when delta >=0.
	sleep(1);
	printf("O ");
	sleep(1);
	printf("T ");
	sleep(1);
	printf("!\n");
	
	printf("-------------------------------------------\n\n");
	
	quadEqsolver(); // REBOOT.
}
