#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BIT_MAX 31

int baseN_to_DEC(int, int);
int digit_extractor(int number);
int foolproof(int last_index, int base);

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
    if (base < 2){
        printf("Please check the base and try again\n");
        while (base > 2){
            printf("Base: ");
            scanf("%d", &base);
        }
    }

    printf("Enter the number: ");
    scanf("%d", &num);

    last_index = digit_extractor(num);

    converted_num = baseN_to_DEC(base, last_index);
    printf("Decimal=%d\n", converted_num);

    printf("Press enter to exit...");
    getchar();
    getchar();
    return 0;
}

int baseN_to_DEC(int r, int last_index)
{
    if (foolproof(last_index, r) == 0){
        printf("Base_Mismatch: PLease check the number and the base\n");
        printf("----------\n\n");
        main();
    }

    if (r>1){
        int i=0, count=0, total=0;

        for(i=last_index-1; i>=0; i--){
            total +=  new_digits[i] * (int) (pow(r, count));
            ++count;
        }
        return total;
    }
    return 1;
}

int digit_extractor(int number)
{
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

int foolproof(int last_index, int base){
    int i;
    for(i=0; i<last_index; i++){
        if (new_digits[i] >= base) return 0;
    }
    return 1;
}