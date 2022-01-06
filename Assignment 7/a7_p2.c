/* 
   CH-230-A
   a7 p2.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

/* Struct list */
struct double_list
{
	char data;
	struct double_list *n;
	struct double_list *p;
};

/* Functions declaration */
struct double_list *push_front(struct double_list*, char elem);
struct double_list *remove_one(struct double_list*, char elem);
void print_list(struct double_list*);
void list_backwards(struct double_list*);
void empty_list(struct double_list*);

int main () {
    struct double_list *special_list = NULL;
	char elem;
	int number, k = 0;
	
    do
	{
		scanf("%d", &number); /* Getting input */
		getchar();

		switch(number)
		{
			case 1:
				scanf("%c", &elem); /* Getting input */
				special_list = push_front(special_list, elem);
				break;

			case 2:
				scanf("%c", &elem); /* Getting input */
				special_list = remove_one(special_list, elem);
				break;

			case 3:
				print_list(special_list);
				break;

			case 4:
				list_backwards(special_list);
				break;

			case 5:
				empty_list(special_list);
				k = 1;
				break;
		}
	} while(!k);

	return 0;
}

/* Pushing an element at the beginning of the list */
struct double_list *push_front(struct double_list *special_list, char elem)
{
	struct double_list *new;
	new = (struct double_list*) malloc(sizeof(struct double_list));
	if (!new)
		exit(0);

	if (special_list==NULL)
	{
		new->data = elem;
		new->n = NULL;
		new->p = NULL;
		return new;
	}
    new->data = elem;
	new->p = NULL;
	new->n = special_list;
	special_list->p = new;
	return new;
}

/* Deleting all elements with a given char */
struct double_list *remove_one(struct double_list *special_list, char elem)
{
    struct double_list *p = NULL, *n = NULL, *cur;
	cur = special_list;
	int idx = 0;
	
	if (special_list == NULL)
		return special_list;
	
    while (cur)
	{
		p = cur->p;
		n = cur->n;
		/* When the element is the first of the list */
		if (p==NULL && (cur->data == elem))
		{
			n->p = NULL;
			cur->n = NULL;
			cur = n;
			special_list = n;
			idx++;
			continue;
		}
		/* When the element is the last of the list */
		if (n==NULL && cur->data == elem)
		{
			p->n = NULL;
			cur->p = NULL;
			idx++;
			break;
		}
		/* Other situations */
		if (cur->data == elem)
		{
			p->n = n;
			n->p = p;
			cur->n = NULL;
			cur->p = NULL;
			cur = n;
			idx++;
			continue;
		}
        cur = cur->n;
	}
	
    if (idx==0)
		printf("%s\n", "The element is not in the list!");
	return special_list;
}

/* Printing the list */
void print_list(struct double_list *special_list)
{
	struct double_list* cur;
	for(cur = special_list; cur; cur = cur->n)
	{
		printf("%c ", cur->data);
	}
	printf("\n");
}

/* Printing the list backwards */
void list_backwards(struct double_list *special_list)
{
	struct double_list *cur;
	for (cur=special_list; cur; cur = cur->n)
    {
		if (cur->n == NULL)
			break;
	}
	
    /* The elements backwards */
	for (; cur; cur = cur->p)
		printf("%c ", cur->data);
	printf("\n");
}

/* Quitting the execution of the program*/
void empty_list(struct double_list* special_list)
{
	struct double_list *nextelem;
	while (special_list!=NULL)
	{
		nextelem = special_list->n;
		free(special_list); /* Freeing the memory */
		special_list = nextelem;
	}
}