// Code by Arda Sevinç 260206019 EEE Major


#include <stdio.h>
#include <math.h>  // Including headers
#include <stdlib.h>

double Evalute(int poly[], int degree, double x);
double LeftRiemann(int coefficients[], int degree);
double RightRiemann(int coefficients[], int degree);  // Function prototypes
double TrapezoidalRiemann(int coefficients[], int degree);

double a, b, deltaX, n; // Global variable declaration

int main()
{
  int degree, k, var=1; // Necessary variables

while (1){ // Loop to compute integrals continuously
  printf("--------------------------------------\n");
  printf("Choose one of the methods listed below\n");
  printf("(1) Left Riemann Sum\n");
  printf("(2) Right Riemann Sum\n");
  printf("(3) Trapezoidal Riemann Sum\n");
  printf("(0) Exit\n");

  scanf("%d", &var); // Scanning the user input
  if (var == 0) // Exit condition
    exit(0);

  printf("Enter the degree of the function:"); //Getting the degree of the func.
  scanf("%d", &degree);

  int coefficients[degree+1]; // Degree+1 coefficients
  printf("Enter %d coefficients (enter one under the other)\n", degree+1);

  for(k=0; k<degree+1; k++)
  {
    scanf("%d", &coefficients[k]); // Filling the array with coefficients
  }

  printf("Enter a:"); // Boundaries of integration
  scanf("%lf", &a);
  printf("Enter b:");
  scanf("%lf", &b);

  printf("Enter n:");
  scanf("%lf", &n);

  deltaX = (b-a)/n; // Calculating deltaX

  switch(var){
    case 1:
      printf("------------------------------------\n");
      printf("Results\n");
      printf("DeltaX=%lf\n", deltaX);
      printf("Area=%lf\n", LeftRiemann(coefficients, degree)); // Results
      break;
    case 2:
      printf("------------------------------------\n");
      printf("Results\n");
      printf("DeltaX=%lf\n", deltaX);
      printf("Area=%lf\n", RightRiemann(coefficients, degree));
      break;
    case 3:
      printf("------------------------------------\n");
      printf("Results\n");
      printf("DeltaX=%lf\n", deltaX);
      printf("Area=%lf\n", TrapezoidalRiemann(coefficients, degree));
      break;
  }

}

return 0;
}

double Evalute(int poly[], int degree, double x)
{
  int i;
  double result = poly[0]; // Poly is the array where coefficients are stored

  for(i=1; i<=degree; i++)
  {
    result = result*x + poly[i];
  }
  return result;
}

double LeftRiemann(int coefficients[], int degree)
{
  double i=a, integral_result=0;
  int k;

  for(k=0; k<(int)n; k++, i += deltaX)
  {
    integral_result += deltaX * Evalute(coefficients, degree, i); // Formula
  }
  return integral_result;
}

double RightRiemann(int coefficients[], int degree)
{
    double i = a+deltaX, integral_result=0;
    int k;

    for(k=0; k<(int)n; k++, i+=deltaX)
    {
      integral_result += deltaX * Evalute(coefficients, degree, i);
    }
    return integral_result;
}

double TrapezoidalRiemann(int coefficients[], int degree)
{
  double i=a, integral_result=0, var2=0;
  int k;

  for(k=0; k<(int)n; k++, i += deltaX)
  {
    var2 = Evalute(coefficients, degree, (i + deltaX)); 
    integral_result += 0.5 * deltaX * (Evalute(coefficients, degree, i) + var2);
  }
  return integral_result;
}
