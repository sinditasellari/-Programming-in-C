/*
   CH-230-A
   a8 p7.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
	char c;
	FILE *doc1, *doc2, *doc3;
	doc1 = fopen("text1.txt", "r");
	doc2 = fopen("text2.txt", "r");
	doc3 = fopen("merge12.txt", "w");
	
	if(doc1 == NULL || doc2 == NULL || doc3 == NULL)
    {
		printf("Exit!\n");
		exit(1);
	}
	
	/* Reading the content of two files and merging them into another one */
	while((c=fgetc(doc1)) != EOF)
    {
		fputc(c, doc3);
	}
	fputc('\n', doc3);
	while((c=fgetc(doc2)) != EOF)
    {
		fputc(c, doc3);
	}
	
	fclose(doc1);
	fclose(doc2);
	fclose(doc3);
	return 0;
}