#include <stdio.h>

int main() {
    int c;
    char char_test;

    while ((char_test = getchar()) != EOF) {
        putchar(char_test);
    }
    
    if (char_test == EOF) {
        printf("\nEOF DETECTED!\n");
        printf("size_char=%d\n", sizeof(char_test));
        printf("size_eof=%d", sizeof(EOF));
    }
    else printf("\n NO EOF DETECTED\n");

    return 0;
}
