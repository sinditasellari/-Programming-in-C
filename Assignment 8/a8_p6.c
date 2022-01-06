/*
   CH-230-A
   a8 p6.cpp
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *doc1, *doc2, *doc3;
	char str1[100], str2[100];
	double a, b;
	
	/* Getting input */
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1)-1] = '\0';
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2)-1] = '\0';
	
	doc1 = fopen(str1, "r");
	if(doc1==NULL)
    {
		printf("Error!\n");
		exit(1);
	}
	doc2 = fopen(str2, "r");
	if(doc2==NULL)
    {
		printf("Error!\n");
		exit(1);
	}
	doc3 = fopen("results.txt", "w");
	if(doc3==NULL)
    {
		exit(1);
	}
	
	/* Reading the two values from the two files */
	fscanf(doc1, "%lf", &a);
	fscanf(doc2, "%lf", &b);
	
	/* Writing the results in the last file */
	fprintf(doc3, "Sum of the numbers: %lf\n", a+b);
	fprintf(doc3, "Difference of the numbers: %lf\n", a-b);
	fprintf(doc3, "Product of the numbers: %lf\n", a*b);
	fprintf(doc3, "Division of the numbers: %lf\n", a/b);
	
	fclose(doc1);
	fclose(doc2);
	fclose(doc3);	
	return 0;
}