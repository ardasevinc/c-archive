#include <stdio.h>

//Printing ASCII codes backwards from highest to lowest//

main()

{
	int i;
	printf("====  ASCI CODES ========\n");
	printf("\n");	
	
	for (i=0; i <= 255; i++){
		
		printf("%d	",(255-i));
		printf("\t");
		putchar((255-i));
		printf("\n");
		
		//printf('%c',i);//
		
	}
	
	
}
