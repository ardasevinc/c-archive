#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define N 49 // Maximum value of 49

#define N_C 50	//Number of columns
#define N_R 20	//Number of rows

void draw_histogram(int Input_Array[N_C]);

int main()
{
  time_t timer;

  int d;

  int second_val[500];
  int real_arr[50];

  printf("Press ctrl-c to exit\n\n");
while(1==1)
{

  printf("Enter case:\n");
  scanf("%d", &d);



  switch (d) {
    case 1:

      srand(0);
      int i,n;

      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }

      draw_histogram(real_arr);

      //Second seed
      srand(0);
      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }

      draw_histogram(real_arr);


      printf("\n\n");
      break;

    case 2:
    {
      int i;

      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }
      srand(0);
      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }

      draw_histogram(real_arr);

      // Second seed
      srand(15);

      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }

      draw_histogram(real_arr);
      break;
    }

    case 3:
    {
      int i,n;

      srand(time(&timer));
      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }

      draw_histogram(real_arr);
      // Second Seed

      srand(time(&timer));
      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }
      draw_histogram(real_arr);
      break;
    }
    case 4:
    {
      int i,n;

      srand(time(&timer));

      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }
      draw_histogram(real_arr);

      // Second Seed
      sleep(1);

      srand(time(&timer));
      for(i=0; i<500; i++){
        real_arr[i] = 0;
      }

      for(i=0; i<500; i++){

        second_val[i] = (rand() % 50);
      }

      for(i=0; i<50; i++)
      {
        for(n=0; n<500; n++){
          if (i == second_val[n])
          {
            real_arr[i] += 1;
          }
        }
      }
      draw_histogram(real_arr);
      break;
    }
}
}





}




void draw_histogram(int Input_Array[N_C]){
	int i,j;
	int Hist[N_C];
    // NOTE TO MY FUTURE SELF!
    // fuck this extended ascii windows shit



	//char fill=219;
	//char horizontal_line=196;
	//char horizontal_t_line=194;
	//char vertical_line=179;
	//char vertical_t_line=195;
	//char northwest_corner=218;
	//char northeast_corner=191;
	//char southwest_corner=192;
	//char southeast_corner=217;
	//Copy contents of input array
	for(i=0;i<N_C;i++){
		if(N_R-Input_Array[i]<0){
			Hist[i]=0;
		}
		else{
			Hist[i]=N_R-Input_Array[i];
		}
	}
	//Draw top line
	for(i=0;i<N_C+1;i++){
		if(i==0){
			printf("  %c",northwest_corner);
		}
		else if(i==N_C){
			printf("%c%c%c%c",horizontal_line,horizontal_line,horizontal_line,northeast_corner);
		}
		else{
			printf("%c%c%c",horizontal_line,horizontal_line,horizontal_line);
		}
	}
	printf("\n");
	//Draw the histogram with left and right lines
	for(i=0;i<N_R;i++){
		for(j=0;j<N_C;j++){
			if(j==0){
				if(N_R-i<10){
					if(Hist[j]>0){
						printf(" %d%c   ",N_R-i,vertical_t_line);
						Hist[j]--;
					}
					else{
						printf(" %d%c %c ",N_R-i,vertical_t_line,fill);
					}
				}
				else{
					if(Hist[j]>0){
						printf("%d%c   ",N_R-i,vertical_t_line);
						Hist[j]--;
					}
					else{
						printf("%d%c %c ",N_R-i,vertical_t_line,fill);
					}
				}
			}
			else if(j==N_C-1){
				if(Hist[j]>0){
					printf("   %c",vertical_line);
					Hist[j]--;
				}
				else{
					printf(" %c %c",fill,vertical_line);
				}
			}
			else{
				if(Hist[j]>0){
					printf("   ");
					Hist[j]--;
				}
				else{
					printf(" %c ",fill);
				}
			}
		}
		printf("\n");
	}
	//Draw bottom line
	for(i=0;i<N_C+1;i++){
		if(i==0){
			printf("  %c",southwest_corner);
		}
		else if(i==N_C){
			printf("%c%c%c%c",horizontal_line,horizontal_line,horizontal_line,southeast_corner);
		}
		else{
			printf("%c%c%c",horizontal_line,horizontal_t_line,horizontal_line);
		}
	}
	printf("\n");
	//Write event numbers
	for(i=0;i<N_C+1;i++){
		if(i==0){
			printf("   ");
		}
		else if(i<10){
			printf(" %d ",i-1);
		}
		else{
			printf(" %d",i-1);
		}
	}
	printf("\n");
}
