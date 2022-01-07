#include <stdio.h>

int f(int);

int main()
{
    int i, x;
    int total;

    printf("x: ");
    scanf("%d", &x);

    printf("f(%d) = %d\n", x, f(x));

    total = 0;
    for (i = 1; i <= x; i++) {
        total += f(i);
    }

    printf("Sum(f(%d)) = %d\n", x, total);

    return 0;
}

int f(int x)
{
    return (300 + (200 * (x-1)));
}
