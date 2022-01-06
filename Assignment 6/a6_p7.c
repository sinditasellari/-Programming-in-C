/* 
   CH-230-A
   a6 p7.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#define BIT(a) a&1

void set3bits(unsigned char *ch, int x, int y, int z)
{
	/* Making the x, y, and z-th bits equal to 1 */
	/* Using pointers */
	*ch |= (1<<x);
	*ch |= (1<<y);
	*ch |= (1<<z);
}

int main () {
    unsigned char ch;
	scanf("%c", &ch);
    /* The positions */
    int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
    int idx, k;

    printf("The decimal representation is: %d\n", ch);
	printf("The binary representation is: ");

	for (idx=7; idx>=0; --idx)
    {
		k = ch >> idx;
		printf("%d", BIT(k)); /* Apply the macro */
	}
	printf("\n");

	/* Using function set3bits */
	set3bits(&ch, x, y, z);
	printf("After setting the bits: ");
	for (idx=7; idx>=0; --idx)
    {
		k = ch >> idx;
		printf("%d", BIT(k)); /* Apply the macro */
	}
	printf("\n");
    return 0;
}
