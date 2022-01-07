#include <stdio.h>

int main() {
    int num_boi;

    printf("Input the number, boy: ");
    scanf("%d", &num_boi);

    int len_num_boi = snprintf(NULL, 0, "%d", num_boi);
    char str_boi[len_num_boi+1];
    sprintf(str_boi, "%d", num_boi);

    printf("\nLength of the string is %d\n", len_num_boi+1);
    printf("str is %s", str_boi);
    return 0;
}
