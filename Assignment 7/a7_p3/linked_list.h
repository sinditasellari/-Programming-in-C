/* 
   CH-230-A
   a7 p3.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#ifndef LIST_H
#define LIST_H

/* Struct and function declarations */

struct list {
    int info;
    struct list* next; /* self reference */
};

struct list* push_front(struct list *my_list, int value);
struct list* push_back(struct list* my_list, int value);
void print_list(struct list* my_list);
void dispose_list(struct list* my_list);
struct list* delete_firstel(struct list *my_list);

#endif

