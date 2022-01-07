#include <stdio.h>
#include <conio.h>
#define M 5
#define C '*'


main()
{
	int a;
	for (a=1; a<= M*5;a++){
		printf("%c",C);
		if (a==5||a==10||a==15||a==20){
			printf("\n");
		}
	}
	getch();
	return 0;
}

