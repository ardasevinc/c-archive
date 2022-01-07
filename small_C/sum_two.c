#include <stdio.h>

int sum_two(float x1,float x2);

main()
{
	int input1,input2;
	
	printf("Enter numbers (x1,x2)):");
	scanf("%d %d",&input1,&input2);
	printf("\n\nResult is:%d",sum_two(input1,input2));	
}

int sum_two(float x1,float x2)
{
	return x1+x2;
}
