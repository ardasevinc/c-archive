// Program for integer randomization and displaying via histograms

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N_C 50	//Number of columns
#define N_R 20	//Number of rows
#define MAX 50

void arrToZero(int arrInput[], int size);
long int returnSeconds();
void draw_histogram(int Input_Array[N_C]);
int* returnSeededArr(int arr[],int size, int seed);

int new_arr[50];

int main()
{
  int arr[500];
  char m;


  arrToZero(arr, 500);

  printf("Welcome. Enter 0 to exit.\n");
  while ((m=getchar()) != '0'){

    switch (m) {
      case '1':
      {
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, 0));
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, 0));
        arrToZero(arr, 500);
        break;
      }
      case '2':{
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, 0));
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, 15));
        arrToZero(arr, 500);
        break;
      }
      case '3':{
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, returnSeconds()));
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, returnSeconds()));
        arrToZero(arr, 500);
        break;
      }
      case '4':{
        arrToZero(arr, 500);
        draw_histogram(returnSeededArr(arr, 500, returnSeconds()));
        arrToZero(arr, 500);
        sleep(1);
        draw_histogram(returnSeededArr(arr, 500, returnSeconds()));
        arrToZero(arr, 500);
        break;
      }
    }
  }

}

void draw_histogram(int Input_Array[N_C])
{
  int i,j;
	int Hist[N_C];
	char fill=35;
	char horizontal_line=95;
	char horizontal_t_line=95;
	char vertical_line=47;
	char vertical_t_line=47;
	char northwest_corner=32;
	char northeast_corner=32;
	char southwest_corner=32;
	char southeast_corner=32;
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


long int returnSeconds()
{
  time_t timer;
  return time(&timer);
}

void arrToZero(int arrInput[], int size)
{
  int i;

  for(i=0; i<size; i++)
  {
    arrInput[i] = 0;
  }
}

int* returnSeededArr(int arr[],int size, int seed){
  int i, n;
  srand(seed);

  arrToZero(new_arr, 50);

  for(i=0; i<size; i++)
  {
    arr[i] = rand() % MAX;
  }
  for(i=0; i<50; i++)
  {
    for(n=0; n<size; n++){
      if (i == arr[n]){
        new_arr[i] += 1;
      }
    }
  }

  return new_arr;
}
