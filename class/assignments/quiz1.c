#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
    int a[N]; 
    int M=100,*pa;
    int b[M];
    pa=(int *)malloc(M*sizeof(int));
    free(pa);
    pa=a;
    pa[0]=1; 
}
