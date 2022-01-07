#include <stdio.h>

int sum(int, int, int);
void print_sum(int, int, int, int);

int main()
{
    int start, end, step, count;

    printf("Start: ");
    scanf("%d", &start);

    printf("\nEnd: ");
    scanf("%d", &end);

    printf("\nStep: ");
    scanf("%d", &step);

    printf("\n Count: ");
    scanf("%d", &count);

    int sum_result;
    /* sum_result = sum(start, end, step); */

    /* printf("\n\nResult = %d\n", sum_result); */

    print_sum(start, end, step, count);

    return 0;
}

int sum(int start, int end, int step)
{
    int i;
    int result;

    result = 0;
    for (i = start; i <= end; i += step) {
        result += i;
    }

    return result;
}

void print_sum(int start, int end, int step, int count) {
    int i, j;
    int result;

    result = 0;
    for (i = 0; i < count; i++) {
        for (j = start; j <= end; j += step) {
            printf("%d\n", j);
        }
    }
}
