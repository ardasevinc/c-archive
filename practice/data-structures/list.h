#ifndef LIST_H
#define LIST_H

#define TRUE  1
#define FALSE 0
#define MAXNAME 80

struct list_node {
    char name[MAXNAME+1];
    struct list_node *next;
};

typedef struct list_node * List;

List init_list(void);
int is_empty(List);
List add_to_head(List, char *, int *);
void destroy_list(List);
List delete_from_list(List, char*, int *);
void print_list(List);
void print_head(List);
List pop_head(List, int *);
List pop_tail_iter(List);

#endif
