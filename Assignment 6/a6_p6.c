/* 
   CH-230-A
   a6 p6.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#define BIT(a) a&1 /* Using macro */

int main () {
    unsigned char x;
	scanf("%c", &x);
    int idx, binary;

    printf("The decimal representation is: %d\n", x);
	printf("The binary representation is: ");

	/* The loop starts from 7 to 0 as an int needs 8 bits */
	for (idx=7; idx>=0; --idx)
    {
		binary = x >> idx;
		printf("%d", BIT(binary));	
	}
	printf("\n");
	return 0;
}