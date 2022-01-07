/* Arda Sevinç - 260206019
 * Written on a linux system
 * 2020-06-22 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FALSE 0
#define TRUE  1

#define STACK_MAX 100

struct stack {
    char entry[STACK_MAX];
    int count;
};


void init_stack(struct stack *);
int push(struct stack *, char);
char pop(struct stack *);
int return_count(struct stack *);
int is_palindrome(struct stack *s, char *);
char *strlower(char *str);

int main()
{
    struct stack s;
    int word_count;
    char input[STACK_MAX];
    char *token;

    printf("initializing stack\n");
    init_stack(&s);
    printf("> Stack length: %d\n",
            return_count(&s));

    printf("Input 100 chars max\n");
    scanf("%[^\n]s", input);

    strlower(input);

    token = strtok(input, " ");

    word_count = 1;

    while (token != NULL) {
        if (is_palindrome(&s, token)) {
            printf("> word %d is palindrome\n", word_count);
        }
        token = strtok(NULL, " ");
        word_count++;
    }

    return 0;
}


void init_stack(struct stack *s)
{
    s->count = 0;
}


int push(struct stack *s, char c)
{
    if (return_count(s) < STACK_MAX) {
        s->entry[s->count] = c;
        s->count++;
        return (TRUE);
    }
    else {
        return (FALSE);
    }
}


char pop(struct stack *s)
{
    if (s->count > 0) {
        s->count--;
        return (s->entry[s->count]);
    }
    else return (FALSE);
}


int return_count(struct stack *s)
{
    return (s->count);
}


int is_palindrome(struct stack *s, char *word) 
{
    int i, wordlen, result;
    wordlen = strlen(word);
    /* printf("wordlen=%d\n", wordlen); */

    init_stack(s);
    for (i = wordlen-1; i >= 0; i--) {
        if (push(s, word[i]));
        else {
            printf("LOL\n");
            exit(12);
        }
    }
    /* printf("> stack: %s\n", s->entry); */
    /* printf("> word: %s\n", word); */
    result = strcmp(s->entry, word);
    return (!result);
}


char *strlower(char *str)
{
  char *p = (char *)str;

  while (*p) {
      *p = tolower((char)*p);
      p++;
  }

  return str;
}
