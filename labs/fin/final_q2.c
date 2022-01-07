#include <stdio.h>

void easy_sort(int*, int);
int arr_max(int*, int);


int main()
{
    int i;
    int arr[10] = {3,4,1,5,6,2,9,8,1,2};

    /* int max = arr_max(arr, 10); */

    /* printf("%d\n", max); */

    easy_sort(arr, 10);

    for (i=0; i<10; i++) {
        printf("\n %d", arr[i]);
    }

    return 0;
}


void easy_sort(int * arr, int size)
{
    int i, temp;
    int * unsorted;

    for (i=0; i<size; i++) {
        if (i != size-1) {
            unsorted = arr + 1;

            temp = arr[i];
            arr[i] = arr_max(unsorted, size-1);
            /* TODO: Change "i" to to the index of the max element
             * of the unsorted array */
            /* use find_index func */
            unsorted[i] = temp;
        }
    }
}


int arr_max(int * arr, int size)
{
    int i, temp;

    temp = arr[0];
    for (i=1; i<size; i++) {
        if (arr[i] > temp)
            temp = arr[i];
    }

    return (temp);
}


int find_index(int * arr, int target, int size)
{
    int i;
    int flag = 0;

    for (i=0; i<size; i++) {
        if (flag)
            break;
        /* if found set flag to true */
        if (arr[i] == target)
            flag = 1;
    }
    return (i);
}
