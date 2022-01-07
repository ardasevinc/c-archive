#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
	int i,count,step;
	printf("Count to and step (count,step): ");
	scanf("%d,%d",&count,&step);
	for (i=0;i<=count;i=i+step){
		printf("%d\n",i);
	}
	if ((count%step)>0)
	{
		printf("%d",count);	
	}	
	
	getch();
}
