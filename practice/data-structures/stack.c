#include <stdio.h>
#include <stdlib.h>
#include "./stack.h"


Stack make_stack(
        int initial_size,
        int increment
        )
{
    Stack s;

    /* try to allocate memory for stack */
    s = malloc( sizeof(struct number_stack) );
    /* check if memory was allocated */
    if (s != NULL) {
        /* Memory for stack data */
        s->entries = calloc(initial_size,
                sizeof(struct number));
        /* Set stack to null if we can't
         * allocate memory for stack data */
        if (s->entries == NULL) {
            free(s);
            s = NULL;
        }
        /* init the stack since memory
         * was allocated successfully */
        else {
            s->size  = initial_size;
            s->inc   = increment;
            s->count = 0;
        }
    }
    return (s);
}


int return_count(Stack s)
{
    return (s->count);
}


int push(Stack s, struct number *n)
{
    struct number *temp;
    
    if (s->count == s->size) {
        temp = reallocarray(s->entries,
                s->size+s->inc,
                sizeof(struct number));
        if (temp == NULL)
            return (FALSE);
        else
            s->entries = temp;
    }
    s->entries[s->count] = *n;
    s->count++;
    return (TRUE);
}


int pop(Stack s, struct number *n)
{
    if (s->count > 0) {
        s->count--;
        *n = s->entries[s->count];
        return (TRUE);
    }
    else
        return (FALSE);
}


int return_mid(Stack s, struct number *n)
{
    /* we can only find the mid item
     * if the number of items in
     * stack is an odd number */
    if (s->count % 2 != 0) {
        *n = (s->entries[((s->count)-1)/2]);
        return (TRUE);
    }
    else return (FALSE);
}


struct number head(Stack s)
{
    if (s->count > 0)
        return (s->entries[(s->count)-1]);
    else {
        struct number empty = {
            0
        };
        return empty;
    }
}


struct number tail(Stack s)
{
    if (s->count > 0) {
        return (s->entries[0]);
    }
    else {
        struct number empty = {
            0
        };
        return empty;
    }
}


void destroy_stack(Stack s) 
{
    /* free the stack data first
     * then stack */
    free(s->entries);
    free(s);
}
