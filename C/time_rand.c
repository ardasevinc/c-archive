#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N_C 30	//Number of columns
#define N_R 30	//Number of rows
#define N 31 // random values, max 30

long int seconds_since1970();
void draw_histogram(int Input_Array[N_C]);

int main()
{
  int rand_val[N_C], i; 

  srand(seconds_since1970());

  for (i = 0; i < N_C; i++) {
    rand_val[i] = rand() / (RAND_MAX / N+1);
    printf("%d\n", rand_val[i]);
  }

  draw_histogram(rand_val);

  printf("Press enter to exit...");
  getchar();
  return 0;

}

long int seconds_since1970(){
  time_t time_var;
  long int seconds = time(&time_var);
  return seconds;

}

void draw_histogram(int Input_Array[N_C]){
	int i,j;
	int Hist[N_C];
	char fill=219;
	char horizontal_line=196;
	char horizontal_t_line=194;
	char vertical_line=179;
	char vertical_t_line=195;
	char northwest_corner=218;
	char northeast_corner=191;
	char southwest_corner=192;
	char southeast_corner=217;
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
