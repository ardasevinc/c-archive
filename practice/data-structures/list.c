#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./list.h"


List init_list(void) 
{
    return (NULL);
}


int is_empty(List slist) 
{
    if (slist == NULL) {
        return (TRUE);
    }
    else return (FALSE);
}


List add_to_head(List slist, char *student, int *flag)
{
    List node;

    node = malloc( sizeof(struct list_node) );
    if (node == NULL)
        *flag = FALSE;

    else {
        strncpy(node->name, student, MAXNAME);
        node->next = slist;
        slist = node;
        *flag = TRUE;
    }
    return (slist);
}


void destroy_list(List slist)
{
    if (!is_empty(slist)) {
        destroy_list(slist->next);
        free(slist);
    }
}


List delete_from_list(List slist, char *str, int *flag)
{
    List temp;
    List prev;

    *flag = FALSE;
    temp = slist;

    while (!is_empty(temp) && !(*flag)) {
        if (!strcmp(temp->name, str))
            *flag = TRUE;
        else {
            prev = temp;
            temp = temp->next;
        }

        if (*flag) {
            if (temp == slist)
                slist = temp->next;
            else
                prev->next = temp->next;
            free(temp);
        }
    }
    return(slist);
}


void print_list(List slist) {
    List temp = slist;

    printf("\n");
    while (!is_empty(temp)) {
        /* printf("Just wanted to let you know\n"); */
        /* debug */
        /* printf("%20s | %p \t\t(%p)\n", temp->name, */ 
        /*         (void*) temp->next, (void*) temp); */
        printf("%20s\n", temp->name);
        temp = temp->next;
    }
}


void print_head(List slist)
{
    /* Debug */
    /* printf("%20s | %p\n", slist->name, */ 
    /*         (void*) slist->next); */
    printf("%20s\n", slist->name);
}


List pop_head(List slist, int *flag) {
    List temp = slist;

    if ( !(is_empty(temp)) ) {
        temp = temp->next;
        free(slist);
        *flag = TRUE;
    }
    else
        *flag = FALSE;
    return temp;
}


List pop_tail_iter(List slist)
{
    int test_flag;
    List temp;
    List prev;

    temp = slist;

    while ( !is_empty(temp) ) {
        /* printf("I'm here!\n"); */
        prev = temp;
        temp = temp->next;
    }
    free(prev);
    return (slist);
}
