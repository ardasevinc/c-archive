#include <stdio.h>

long long int fibonacci(long long int);


int main() {
    int n;
    long long int result;
    while (1 == 1) {
    printf("\nenter sth plz: ");
    scanf("%d", &n);
    result = fibonacci(n);
    printf("\nresult=%lld", result);
    }
    return 0;
}


long long int fibonacci(long long int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}
