/* 
   CH-230-A
   a7 p5.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

/* Sorting the integers in ascending order */
int asc_order(const void *one, const void *two)
{
	const int* el1 = (const int*) one;
	const int* el2 = (const int*) two;
	if (*el1 < *el2) return -1;
	else if (*el1 > *el2) return 1;
	else return 0;
}

/* Sorting the integers in descending order */
int desc_order(const void *one, const void *two)
{
	const int* el1 = (const int*) one;
	const int* el2 = (const int*) two;
	if (*el1 > *el2) return -1;
	else if (*el1 < *el2) return 1;
	else return 0;
}

/* Creating a function pointer */
int (*fct) (const void *one, const void *two);

/* Printing the sorted array of integers */
void print_sort(int *arr, int size, int(*fct)(const void *one, const void *two))
{
	qsort (arr, size, sizeof(arr[0]), fct);
	int idx;
	for (idx=0; idx<size; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("\n");
}

int main () {
	int idx, n;
	char char1;
	scanf("%d", &n); /* Getting input */
	int a[n];
	for (idx=0; idx<n; idx++)
	{
		scanf("%d", &a[idx]); /* Getting input */
	}
	while(1)
	{
		scanf("%c", &char1); /* Getting input */
		/* The cases for sorting the array */
		switch(char1)
		{
			case 'a':
				print_sort(a, n, asc_order);
				break;
			case 'd':
				print_sort(a, n, desc_order);
				break;
			case 'e':
			/* Stopping the program */
				exit(1);
				break;
		}
	}
	return 0;
}