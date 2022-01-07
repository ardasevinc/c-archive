#include <stdio.h>

int main() {
    int count;
    int i;

    printf("Count=");
    scanf("%d", &count);

    for (i=0; i <= count; i++) {

        printf("lol %d\n", i);

        if (i == count) {
            printf("\nlel\n");
        }
    
    }
    printf("Press any key to exit...");
    getchar();
    getchar();
    return 0;
}
