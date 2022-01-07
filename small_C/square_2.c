#include <stdio.h>
#include <unistd.h>

main()
{
	int i;
	for (i=1;i<=25;i++){
		printf("*");
		if (i==5||i==10||i==15||i==20){
			printf("\n");
		}
	}
	sleep(10);
}
