/* 
   CH-230-A
   a7 p4.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Turning the letters to uppercase */
void upper(char *string)
{
    char str[50];
    /* Copying the string to not use the original one */
    strcpy(str, string);
	int idx;
	for (idx=0; str[idx]; idx++)
    {
        if ((str[idx]>=97) && (str[idx]<=122))
            printf("%c", str[idx]-32);
        else
        	printf("%c", str[idx]);
    }  
}

/* Turning the letters to lowercase */
void lower(char *string)
{
    char str[50];
    /* Copying the string to not use the original one */
    strcpy(str, string);
    int idx;
	for (idx=0; str[idx]; idx++)
    {
        if ((str[idx]>=65) && (str[idx]<=90))
            printf("%c", str[idx]+32);
        else
        	printf("%c", str[idx]);
    }  
}

/* Turning the lowercase letters to uppercase
and the uppercase ones to lowercase */
void upper_lower(char *string)
{
    char str[50];
    /* Copying the string to not use the original one */
    strcpy(str, string);
	int idx;
	for (idx=0; str[idx]; idx++)
    {
        if ((str[idx]>=97) && (str[idx]<=122))
            printf("%c", str[idx]-32);
        else if ((str[idx]>=65) && (str[idx]<=90))
        	printf("%c", str[idx]+32);       	
		else
		    printf("%c", str[idx]);
    }
}

/* Quitting the program */
void quit(char *str)
{
	exit(1);
}

/* Creating a function pointer */
void(*func_poin[4]) (char * str)
	= {upper, lower, upper_lower, quit};

int main () {
	char string[50];
    int n;
	/* Getting input */
	fgets(string, sizeof(string), stdin);
	scanf("%d", &n);

	while(1)
    {
		func_poin[n-1](string);
		scanf("%d", &n);
	}
	return 0;
}