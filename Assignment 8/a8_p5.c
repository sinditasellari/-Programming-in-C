/*
   CH-230-A
   a8 p5.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *doc1, *doc2;
	char char1, char2;
	
    doc1 = fopen("chars.txt", "r");
	if(doc1==NULL)
    {
		printf("Error!\n");
		exit(1);
	}
	doc2 = fopen("codesum.txt", "w");
	if(doc2==NULL)
    {
		printf("Error!\n");
		exit(1);
	}
	
	/* Reading the first two characters from the file chars.txt */
	char1 = getc(doc1);
	char2 = getc(doc1);
	/* Writing the sum of the characters */
	fprintf(doc2, "%d", (int)char1 + (int)char2);
	
	fclose(doc1);
	fclose(doc2);
	return 0;
}