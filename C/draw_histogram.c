//  Histogram drawing function with example main.
//
//  Author: Mehmet Onur Cirit
//	Mail  : mehmetcirit@iyte.edu.tr
//  Date  : 16.11.2018
//
// Please report bugs to given mail address if you
// encounter one

// Preprocessor directives
#include<stdio.h>

#define N_C 30	//Number of columns
#define N_R 30	//Number of rows

// Function prototypes
void draw_histogram(int Input_Array[N_C]);

// Main function
//
// Includes four example cases that
// demonstrate draw_histogram function usage
int main(){
	int Array[N_C];
	int i,j;

	// Case 1
	for(i=0;i<N_C;i++){
		Array[i]=i;
	}
	draw_histogram(Array);

	// Case 2
	for(i=0;i<N_C;i++){
		Array[i]=N_C-i;
	}
	draw_histogram(Array);

	// Case 3
	j=0;
	for(i=0;i<N_C;i++){
		Array[i]=j;
		if((i/5)%2==0){
			j++;
		}
		else if((i/5)%2==1){
			j--;
		}
	}
	draw_histogram(Array);

	// Case 4
	j=10;
	for(i=0;i<N_C;i++){
		Array[i]=j;
		if((i/5)%2==0){
			j++;
		}
		else if((i/5)%2==1){
			j--;
		}
	}
	draw_histogram(Array);

	return 0;
}

// Function to draw a histogram from an array
//
// Histogram size is determined by preprocessor directives N_R and N_C
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
