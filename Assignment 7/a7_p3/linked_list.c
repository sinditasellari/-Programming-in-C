/* 
   CH-230-A
   a7 p3.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/* Function definitions */

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