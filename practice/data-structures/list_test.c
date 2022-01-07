#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./list.h"


int main()
{
    int len, flag, count = 1;
    List names = init_list();
    List temp = init_list();

    char *input = malloc(MAXNAME+1);

    if ( !input ) {
        printf("> Memory allocation failed\n");
        exit(12);
    }

    printf("Name %d: ", count);;
    while ( fgets(input, MAXNAME+1, stdin) != NULL )
    {
        /* Sanitize the input */
        len = strlen(input);
        if ( len > 0 && (input[len - 1] == '\n') )
            input[len-1] = '\0';

        names = add_to_head(names, input, &flag);
        if (!flag) 
            printf("Error in input, try again\n");
        else {
            count++;
            printf("Name %d: ", count);
        }

    }

    printf("\n>Calling head()...\n");
    /* print_head(names); */
    /* printf("--------\n"); */
    print_list(names);
    printf("--------------------\n");

    printf("\n>Calling pop_head()...\n");
    temp = pop_head(names, &flag);
    /* print_head(names); */
    printf("-------------------\n");
    print_list(names);

    printf("\n>Calling pop_tail_iter()...\n");
    temp = pop_tail_iter(names);
    print_list(names);

    /* while () */
    /* while (strcmp(temp->name, "Foo Bar")) { */

    /*     printf("Enter the name of passenger %d: ", count); */
    /*     scanf("%[^\n]", name); */

    /*     temp = add_to_front(passengers, */ 
    /*             name, &add_flag); */
    /*     count++; */
    /* } */


    
    /* printf("flag = %d\n\n", add_flag); */
    /* print_list( names ); */

    return 0;
}
