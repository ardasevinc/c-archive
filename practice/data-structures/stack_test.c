#include <stdio.h>
#include <stdlib.h>
#include "./stack.h"


int main()
{
    Stack s;
    struct number n = { 5 };
    struct number n_temp;
    int flag1 = !EOF;
    int flag2;

    s = make_stack(1, 1);
    if (s == NULL) {
        printf("ENOMEM\n");
        exit(-1);
    }


    printf("> Stack length: %d\n",
            return_count(s));
    push(s, &n);
    printf("Pushed %d\n", n.num);
    printf("> Stack length: %d\n",
            return_count(s));

    if (pop(s, &n_temp)) {
        printf("Popped %d\n", n_temp.num);
    }
    
    printf("> Stack length: %d\n",
            return_count(s));

    destroy_stack(s);
}
