#include <stdio.h>
#define XP_MIN 150

int f(int);
int sum(int, int);
int min_to_xp(int);
int xp_to_lvl(int);

int main() {
    int time;

    printf("time: ");
    scanf("%d", &time);

    int xp;
    xp = time * XP_MIN;

    int lvl;
    lvl = xp_to_lvl(xp);


    printf("\nLevel = %d\n", lvl);

    return 0;
}

int f(int x) {
    return ( 300 + (200 * (x-1)) );
}

int sum(int start, int end) {
    int i;
    int sum = 0;

    for (i = start; i <= end; i++) {
        sum += f(i);
    }

    return sum;
}

int min_to_xp(int min) {
    return (min * XP_MIN);
}


int xp_to_lvl(int xp) {
    int i;
    int total = 0;
    int lvl;

    for (i = 1; i <= 200; i++) {
        total = sum(1, i);

        if (total >= xp) {
            lvl = i;
            break;
        }
    }

    return lvl;
}
