#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
main()
{
	int a,b,c,year;
	char usr_input[50];
	char ans1[15] = "ok";
	long double population = 2000.0;
	long long usr_input2;
	
	printf("Welcome traveler!\n");
	sleep(1);
	printf("...You die if you do not answer right, ok?\n");
	
	scanf("%s",&usr_input);
	
	if (strcmp(ans1,usr_input) == 0)
	{
		printf("Seems like you are smarter than expected, eh?\n");
	}
	else
	{
		printf("LOL!\n\n");
		sleep(1);
		while(1==1)
		{
			printf("LOL!");
		}
	}
	printf("---------------------------------\n");
	printf("Now, let part II BEGIN!\n\n\n");
	printf("So.. We have a village that starts with 2000 people.\n");
	printf("Every year population increases by 37%% and if the year is 2147 or 2457 population decreases by 71%\n");
	printf("Find what will the population will become in year 2458\n\n");
	
	scanf("%d",&usr_input2);
	
	if (usr_input2 == 6487504)
	{
		printf("Smart lad.\n");
		return 0;
	}
	else
	{
		printf("FACK\n");
		sleep(2);
		printf("\n...loading response");
		
		while (1==1)
		{
			printf("FACK");
		}
	}
	

	for (year = 2018;year<=2458;year++)
	{
		if (year == 2147 || year == 2457)
		{
			population -= 0.71 * population;
		}
		
		population += 0.37 * population;
	}
	printf("%ld\n",population);	
	system("pause");
	return 0;
}
