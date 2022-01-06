/* 
   CH-230-A
   a7 p6.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char name[30];
	int age;
};

/* Comparing and sorting the ages */
int comp_age(struct person one, struct person two)
{
	if (one.age==two.age)
    {
		if (strcmp(one.name, two.name) < 0)
        return 0;
		else
        return 1;
	}
	else
    return (one.age>two.age);
}

/* Comparing and sorting the names */
int comp_name(struct person one, struct person two)
{
	if (strcmp(one.name, two.name) == 0)
    return (one.age>two.age);
	else
    {
		if (strcmp(one.name, two.name) < 0)
        return 0;
		else
        return 1;
	}
}

/* Creating a function pointer */
struct person (*fct) (struct person, struct person);

/* Bubblesort algorithm */
void bubble(struct person *data, int n, int(*fct)(struct person, struct person))
{
    int idx, a, swap = 1;
    char s[50];
    while(swap)
    { 
   		swap = 0;
        for (idx=0; idx<n-1; idx++)
        {            
            if (fct(data[idx], data[idx+1]))  /* Swapping if order is broken */
            {  
                strcpy(s, data[idx].name);
                strcpy(data[idx].name, data[idx+1].name);
                strcpy(data[idx+1].name, s);

			    a = data[idx].age;
                data[idx].age = data[idx + 1].age;
                data[idx + 1].age = a;
                
               	swap = 1;
            }
        }
        n--;
    }
}

/* Printing the sorted data */
void printing(struct person *data, int n)
{
	int idx;
	for (idx=0; idx<n; idx++)
    {
		printf("{%s, %d}; ", data[idx].name, data[idx].age);
	}
	printf("\n");
}

int main () {
    /* Getting input */
	int size;
	scanf("%d", &size);
    int idx;
	struct person data[size];
	for (idx=0; idx<size; idx++)
    {
		scanf("%s", data[idx].name);
		scanf("%d", &data[idx].age);
	}
	/* Calling the functions to perform the sort */
	bubble(data, size, comp_name);
	printing(data, size);
	bubble(data, size, comp_age);
	printing(data, size);
	return 0;
}