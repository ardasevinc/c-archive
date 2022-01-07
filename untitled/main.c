#include <stdio.h>
#include <math.h>

#define BIT_MAX 31

int baseN_to_DEC(int, int);
int digit_extractor(int number);

int new_digits[BIT_MAX];

int main() {
    int base=0, num=0, i=0, last_index=0;
    int converted_num=0;

    printf("Base: ");
    scanf("%d", &base);

    if (base > 10){
        printf("Please enter a base number lower or equal to 10\n");
        while (base > 10){
            printf("Base: ");
            scanf("%d", &base);
        }
    }

    printf("Enter the number: ");
    scanf("%d", &num);

    last_index = digit_extractor(num);

    converted_num = baseN_to_DEC(base, last_index);
    printf("Decimal=%d\n", converted_num);

    getchar();
    return 0;
}

int baseN_to_DEC(int r, int last_index)
{
    if (r>2){
        int i=0, count=0, total=0;

        for(i=last_index-1; i>=0; i--){
            total +=  new_digits[i] * pow(r, count);
            ++count;
        }
        return total;
    }
    return 1;
}

int digit_extractor(int number)
{
    int digit = 0;
    int i=0, j=0;
    int digits[BIT_MAX];

    while(number>0){
        digits[i] = number % 10;
        i++;
        number /= 10;
    }

    for(j=0; j<i; j++){
        new_digits[j] = digits[i-j-1];
    }

    return i;
}