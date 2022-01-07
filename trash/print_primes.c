#include <stdio.h>
#include <math.h>

int is_prime(int);

int main() {
    int i;

    for (i = 0; i < 200; i++) {
        if (is_prime(i) == 1) printf("%d\n", i);
    }
    return 0;
}


int is_prime(int n) {
    if ( n < 2 ) return 0;
    else {
        int i;

        for (i = 2; i <= (int) sqrt(n); i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }
}
