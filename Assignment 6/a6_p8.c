/* 
   CH-230-A
   a6 p8.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

/* Using the example from the slides (Tutorial 6, pages 28 − 35)
as it is indicated in the question */

struct list {
    int info;
    struct list* next; /* self reference */
};

/* Pushing an element at the beginning of the list */
struct list* push_front(struct list *my_list, int value)
{
    struct list* newel;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf("Error allocating memory\n");
        return my_list;
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}

/* Pushing an element at the end of list */
struct list* push_back(struct list* my_list, int value)
{
    struct list* cursor, *newel;
    cursor = my_list;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf ("Error allocating memory \n");
        return my_list;
    }
    newel->info = value;
    newel->next = NULL;
    if (my_list == NULL)
        return newel;
    while (cursor->next != NULL)
        cursor = cursor -> next;
    cursor->next = newel;
    return my_list;
}

/* Printing the list */
void print_list(struct list* my_list)
{
    struct list *p;
    for (p=my_list ; p ; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

/* Quitting the execution of the program*/
void dispose_list(struct list* my_list)
{
    struct list *nextelem;
    while (my_list != NULL)
    {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }
}

/* Removing the first element */
struct list* delete_firstel(struct list *my_list)
{
    /* When the list is empty */
    if (my_list == NULL) 
    {
        return my_list;
    }
    struct list* list1;
    list1 = (my_list->next);
    free (my_list);
    my_list = list1;
    return my_list;
}

int main () {
    struct list *special_list=NULL;
    int n=1;

    while(n)
    {
        char c;
        scanf("%c", &c); /* Getting the input */

        int x1, x2;

        switch(c)
        {
        case 'a':
            scanf("%d", &x1);
            special_list = push_back(special_list, x1);
            break;

        case 'b' :
            scanf("%d", &x2);
            special_list = push_front(special_list, x2);
            break;

        case 'r':
            special_list = delete_firstel(special_list);
            break;

        case 'p':
            print_list(special_list);
            break;

        case 'q':
            dispose_list(special_list);
            n=0;
            break;
        }
    }
    return 0;
}

