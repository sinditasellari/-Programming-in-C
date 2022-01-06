/* 
   CH-230-A
   a6 p2.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
/* The macro using bitwise operators */
#define BIT(x) x&1

int main () {
    unsigned char ch;
    scanf("%c", &ch);

    printf("The decimal representation is: %d\n", ch);
    /* Apply the macro */
    printf("The least significant bit is: %d\n", BIT(ch));
    return 0;
}