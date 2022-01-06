/* 
   CH-230-A
   a6 p9.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

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

/* Computing the number of elements in a list */
int dim(struct list* my_list)
{
	int counting = 1;
	struct list *cursor;
	cursor = my_list;
	while (cursor->next != NULL)
	{
		cursor = cursor -> next;
		counting++;
	}
	return counting;
}

/* Inserting an element in a certain position */
struct list* insert(struct list* my_list, int pos, int val)
{
	int idx;
	struct list *cursor1, *new, *cursor2; 
	cursor1 = my_list;
    /* Negative position or larger than size positions */
	if ((pos<0) || (pos>dim(my_list)))
    {
		printf("Invalid position!\n");
		return my_list;
	}
	/* When the element is put in the beginning */
	else if (pos == 0)
    {
		return push_front(my_list, val);		
	}
	else {
        /* Dynamic memory allocation */
		new = (struct list*) malloc(sizeof(struct list));
        if (new == NULL)
        {
			printf ("Error allocating memory \n");
			return my_list;
		}
        new->info = val;
		new->next = NULL;
		/* When there are no elements in the list */
		if (my_list == NULL)
			return new;
		
		for (idx=0; idx<(pos-1); idx++)
        {
			cursor1 = cursor1->next;		
		}
		/* Inserting the new element */
		cursor2 = cursor1->next;
		cursor1->next = new;
		new->next = cursor2;
		return my_list;	
	}
}

/* Reserving the list */
struct list* reverse(struct list *my_list)
{
	struct list *list_curr, *list_prev, *list_n;
	list_curr = my_list;
    list_prev = NULL;
  	while (list_curr != NULL)
    {
        list_n = list_curr->next;   
        list_curr->next = list_prev;    
        list_prev = list_curr; 
        list_curr = list_n; 
    } 
    return list_prev;
}

int main () {
    struct list *special_list=NULL;
    int n=1;

    while(n)
    {
        char c;
        scanf("%c", &c); /* Getting the input */

        int x1, x2, x3, x4;

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
        
        case 'i':
			scanf("%d%d", &x3, &x4);
			getchar();
			special_list = insert(special_list, x3, x4);
			break; 

		case 'R':
			special_list = reverse(special_list);
			break;

        case 'q':
            dispose_list(special_list);
            n=0;
            break;
        }
    }
    return 0;
}

