#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define NAME_MAX 30

struct node {
    int *id;
    char name[NAME_MAX];
    struct node *next;
};

typedef struct node * List;

void clrscreen();
void wait();
int is_empty(List);
void print_menu();
List create_list();
void destroy_list(List);
List add_to_head(List, char*, int*, int*);
void print_list(List);
void search(List, int, int*);
List remove_from_list(List, int, int*);


int main()
{
    List slist;
    int sel, flag, main_flag;
    int *sid;
    slist = create_list();
    
    /* printf("> Empty list created\n"); */

    print_menu();
    printf("Enter an option: ");
    scanf("%d", &sel);

    main_flag = TRUE;

    while (main_flag) {
    switch(sel)
    {
        case (1): {
                      if (is_empty(slist)) {
                          printf("List is empty\n");
                          wait();
                          print_menu();
                          scanf("%d", &sel);
                          break;
                        }
                      else {
                          print_list(slist);
                      }
                      wait();
                      print_menu();
                      scanf("%d", &sel);
                      break;
                  }

        case (2): {

                      printf("Name: ");
                      char *sname = malloc(NAME_MAX);
                      sid = malloc(sizeof(int));
                      if (sname == NULL || sid == NULL)
                          exit(12);

                      scanf("%s", sname);
                      printf("name=%s\n", sname);

                      printf("ID: ");
                      scanf("%d", sid);

                      slist = add_to_head(
                              slist,
                              sname,
                              sid,
                              &flag
                              );
                      if (!flag) {
                          printf("> Error inserting, ");
                          printf("please try again\n");
                          break;
                      }

                      printf("Student %s with ID %d added\n",
                              slist->name, *(slist->id));
                      wait();
                      print_menu();
                      scanf("%d", &sel);
                      break;
                  }

        case (3): {

                  }

        case (4): {

                  }

        case (5): {
                      exit(0);
                  }
        default:
                  print_menu();
                  printf("Enter an option: ");
                  scanf("%d", &sel);
                  break;
    }

    }


    return 0;
}


void print_menu()
{
    printf("\n----------------------------------\n");
    printf("1 - Print\n");
    printf("2 - Add\n");
    printf("3 - Search\n");
    printf("4 - Remove\n");
    printf("5 - Exit\n");
    printf("\n----------------------------------\n");
}


/* This is the LINUX version
 * Uncomment below as advised to get
 * it working on windows */
void clrscreen()
{
    /* Uncomment the line below for Windows */
    /* system("cls"); */
    system("clear");
}


void wait()
{
    char temp;

    printf("Press enter to continue...\n");
    temp = getchar();
    temp = getchar();

    clrscreen();
}


List create_list()
{
    return (NULL);
}


int is_empty(List slist)
{
    if (slist == NULL)
        return (TRUE);
    else
        return (FALSE);
}


void print_list(List slist)
{
    List temp = slist;
    
    printf("\n----------------------------------\n");

    while (!is_empty(temp)) {
        printf("%s\t\t\t%10d\n",
                temp->name, *(temp->id));
        temp = temp->next;
    }

    printf("\n----------------------------------\n");
}


List add_to_head(List slist, char *name, int *id, int *flag)
{
    List data;

    data = malloc( sizeof(struct node) );
    if (data == NULL)
        *flag = FALSE;

    else {
        strncpy(data->name, name, NAME_MAX);
        data->id = id;
        data->next = slist;
        slist = data;
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


void search(List slist, int id, int *flag)
{
    List temp;
    List prev;
    temp = slist;


    while (!is_empty(temp) && !(*flag)) {
        if (*(temp->id) == id)
            *flag = TRUE;
        else
            temp = temp->next;
    }
}


List remove_from_list(List slist, int id, int *flag) {
    List temp;
    List prev;
    temp = slist;

    while (!is_empty(temp) && !(*flag)) {
        if (*(temp->id) == id)
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
    return (slist);
}
