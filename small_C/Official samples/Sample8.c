#include <stdio.h>
#include <math.h>
#define M 100

//calculating squares of numbers from 1 to 100

//How can we modify this programme so that,the
//squares of all consequtive real numbers from 0  to 100
//that have a difference of Delta_x,specified by the
//use are displayed.

main()

{
	float x;
	float y;
	float DeltaX;
	int i;
	int N;
	
	printf("Enter DeltaX : ");
    scanf("%f", &DeltaX);
	
	N=round(M/DeltaX)+1;
	
	printf("N=%d\n",N);
	printf("DeltaX=%f\n",DeltaX);
	
	printf("========================\n");
	printf("\ni\tx\ty\n");
	printf("========================\n");
			
	
	for (x=0; x<=N; x+=DeltaX){
		
		y=x*x;
		printf("\n\t%f\t%f",x,y);	
				
	}	
	
}
