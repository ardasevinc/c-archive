#include <stdio.h>
#define N 2000

//Finding the average of  numbers where N is a constant defined at
//the beginning of the programme //

//Question.What happens,if we assign a floating point value
//greater than 255 to a variable declared as character//

main()

{
	
	float sum=0.0;
	float average=0.0;
	int i;
	char c;
	
	for (i=1; i <=N; i++){
		
		sum = sum+i;
		
		//printf("%d",i);//
		//printf("\t");
		//printf("Sum=%f\n",sum);
			
	}
		
	average=sum/N;
	
	printf("\n");
	printf("=======================\n");
	printf("Average=%f\n",average);	
	printf("=======================\n");
	
	c=average;	
	
	putchar(c);	
	
}




