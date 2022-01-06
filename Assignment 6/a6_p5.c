/* 
   CH-230-A
   a6 p5.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#define BIT(a) a&1 /* Using macro */

unsigned int bits (unsigned int n);

int main () {
    unsigned char x;
	scanf("%c", &x);
    int idx, backwards;
    
    printf("The decimal representation is: %d\n", x);
	printf("The backwards binary representation is: ");
	
	for (idx=0; idx<bits(x); idx++)
    {
		backwards = x >> idx;
		printf("%d", BIT(backwards));	
	}
	printf("\n");
    return 0;
}

/* Counting the total bits in a number */
unsigned int bits (unsigned int n) { 
   unsigned int count = 0; 
   while (n)
   { 
        count++; 
        n >>= 1; 
   }
   return count; 
} 