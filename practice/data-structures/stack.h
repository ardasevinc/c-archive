#ifndef STACK_H
#define STACK_H


/* fancy string is just a string
 * but it adopts an integer :) */
struct number {
    int  num;
};

struct number_stack {
    int count;/* number of items in the stack*/
    int size; /* max items that stack can hold*/
    int inc; /* increment to expand the stack*/
    struct number *entries;
};

typedef struct number_stack * Stack;


Stack make_stack(int, int);
int return_count(Stack);
int push(Stack, struct number *);
int pop(Stack, struct number *);
int return_mid(Stack, struct number *);
struct number head(Stack);
struct number tail(Stack);
void destroy_stack(Stack);


#define TRUE 1
#define FALSE 0


#endif
