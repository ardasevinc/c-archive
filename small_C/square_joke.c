#include <stdio.h>
#include <unistd.h>

main()
{
	int i,m;
	for (i=1;i<=25;i++){
		printf("*");
		if (i==5||i==10||i==15||i==20){
			printf("\n");
		}
	}
	printf("\nDo you like what you see?(y-n)");
	scanf("%c",&m);
	if (m=='y'){
		while (1==1){
			for (i=1;i<=25;i++){
		printf("*");
		if (i==5||i==10||i==15||i==20){
			printf("\n");
		}
	}
		}
	}
	else{
		printf("\nGoodbye");
	}
}
