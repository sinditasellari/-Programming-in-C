/*
   CH-230-A
   a8 p8.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *fptr;
	int counting = 0;
	char name[30], a;

    /* Getting input */
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1] = '\0';

	fptr = fopen(name, "r");
	if(fptr==NULL)
    {
	    fprintf(stderr, "Exit!\n") ;
		exit(1) ;
	}
	/* For the following characters 
	the counting variable is increasing */
	while((a=fgetc(fptr)) != EOF)
    {
		if(a==' '|| a==','|| a=='?'|| a=='!'|| a=='.'|| a=='\t'|| a=='\r'|| a=='\n')
        {
			while((a = fgetc(fptr)) != EOF)
			{
				if(a==' '|| a==','|| a=='?'|| a=='!'|| a=='.'|| a=='\t'|| a=='\r'|| a=='\n')
				{
				continue;
				}
				else
				{
            	break;
				}
			}
		counting++;
		}
    }
    printf("The file contains %d words.\n", counting);
    fclose(fptr);
	return 0;
}