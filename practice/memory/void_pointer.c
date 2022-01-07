#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *pn;
    int i;

    pn = malloc( sizeof(int) * 250 );

    if (pn != NULL) {
        for (i = 0; i < 250; i++)
            scanf("%d", pn+i);
    }
    return 0;
}
