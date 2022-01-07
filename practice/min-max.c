#include <stdio.h>

int max(int*, int);
int min(int*, int);


int main() {
    int arr_size;
    
    printf("arr_size=");
    scanf("%d", &arr_size);
    int arr[arr_size];

    printf("\nEnter array elements one by one\n");
    int input;
    for (int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
        printf("entered=%d\n", arr[i]);
    }

    int max_of_arr = max(arr, arr_size);
    int min_of_arr = min(arr, arr_size);

    printf("\n\nmax=%d\n", max_of_arr);
    printf("min=%d\n", min_of_arr);
    
    return 0;
}


int max(int array[], int array_length) {
    int temp = 0;
    for (int i=0; i<array_length; i++) {
        if (array[i] > temp) temp = array[i];
    }
    return temp;
}


int min(int arr[], int array_length) {
    int temp = arr[0];
    for (int i=1; i<array_length; i++) {
        if (arr[i] < temp) temp = arr[i];
    }
ööööööööööööööööööööööööööööööööööööööööööööööööööööööö    return temp ;
}
