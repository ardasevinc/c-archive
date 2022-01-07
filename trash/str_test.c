#include <stdio.h>


int main()
{
    char *p;
    char test = '\0';
    p = &test;
    if (*p) printf("if\n");
    return 0;
}
