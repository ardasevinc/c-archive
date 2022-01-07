#define BUFSIZE 1000
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fp;
    int NR, NC, i, j;
    float *arr;

    fp = fopen(argv[1], "w");

    NR = atoi(argv[2]);
    NC = atoi(argv[3]);

    if (argc != NR * NC +4 ) {
        printf("Number of args is incorrect");
        exit(-1);
    }
    arr = (float *) malloc(NR * NC * sizeof(float));

    for (i=0 ; i<NR ; i++) {
        for (j=0 ; j<NC ; j++) {
            arr[i * NC + j] = atof(argv[i + NC + j + 4]);
            fprintf(fp, "%f ", arr[i*NC+j]);
        }
        fprintf(fp, "\n");
    }
}
