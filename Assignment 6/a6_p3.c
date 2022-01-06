/* 
   CH-230-A
   a6 p3.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
/* Using macros */
/* Finding the maximum value */
#define MAXIMUM(a,b,c) ((a>b && a>c) ? a : \
                       ((b>c) ? b : c))
/* Finding the minimum value */
#define MINIMUM(a,b,c) ((a<b && a<c) ? a : \
                       ((b<c) ? b : c))
/* Finding the mid-range */
#define MIDRANGE(a,b,c) ((MINIMUM(a,b,c)+MAXIMUM(a,b,c))/2.0)

int main () {
	int num1, num2, num3;
	scanf ("%d", &num1);
    scanf ("%d", &num2);
    scanf ("%d", &num3);

    float mid;
    mid = MIDRANGE(num1,num2,num3);

	printf ("The mid-range is: %.6f\n", mid);
	return 0;
}