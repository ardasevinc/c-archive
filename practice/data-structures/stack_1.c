#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 300


struct pass {
    char name[80]; /* name of passenger */
    int pieces;    /* number of pieces of luggage */
    int tag1;      /* luggage tag number 1 */
    int tag2;      /* luggage tag number 2 */
};

struct stack_pass {
    int count; /* number of entries in the stack */
    struct pass entries[MAXSTACK];
};


void init_stack(struct stack_pass *);

int return_count(struct stack_pass *);

struct pass pop(struct stack_pass *);

void push(struct stack_pass *, struct pass *);


int main() 
{
    struct pass p;
    struct stack_pass stack;
    int flag = !EOF;
    int seats;

    /* init stack and get capacity of plane */
    init_stack(&stack);
    printf("Enter number of seats on the plane\n");
    scanf("%d", &seats);

    /* read passenger info until we get EOF*/
    while (flag != EOF) {
        flag = scanf("%s %d %d %d", p.name, &p.pieces,
                &p.tag1, &p.tag2);
        if (flag != EOF) push(&stack, &p);
    }

    /* pop bumped passengers */
    while(return_count(&stack) > seats) {
        p = pop(&stack);
        printf("Passenger %s is bumped. Remove luggage\
                %d and %d\n", p.name, p.tag1, p.tag2);
    }
    return 0;
}


void init_stack(struct stack_pass *s)
{
    s->count = 0;
}


int return_count(struct stack_pass *s)
{
    return (s->count);
}


struct pass pop(struct stack_pass *s)
{
    if (s->count > 0) {
        s->count--;
        return (s->entries[s->count]);
    }
    else {
        printf("Error: Cannot pop empty stack!\n");
        exit(-1);
    }
}


void push(struct stack_pass *s, struct pass *p)
{
    if (s->count < MAXSTACK) {
        s->entries[s->count] = *p;
        s->count++;
    }
    else {
        printf("Error: Cannot push on full stack!\n");
        exit(-2);
    }
}
