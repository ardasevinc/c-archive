#include <stdio.h>

main()
{
	
}

int diagonalDifference(int arr_rows, int arr_columns, int* arr) {
    
	int i,j,k,sumLeft=0,sumRight=0,sum;
    
    for(i=0, j=0; i<arr_rows, j<arr_columns; i++, j++)
    {
        sumLeft += arr[i][j];
    }
    
    for(i=0, j=arr_columns-1; i<arr_rows, j>=0; i++, j--)
    {
        sumRight += arr[i][j];
    }

    sum = abs(sumLeft - sumRight);
    return sum;
}
