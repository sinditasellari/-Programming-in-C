/*
   CH-230-A
   a8 p4.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main () {
    /* Getting input */
    unsigned int n;
    scanf("%d", &n);
    Stack stc;
    stc.count = 0;
   
    conv_binary(&stc, n);
    /* Printing the binary representation */
    printf("The binary representation of %d is ", n);
    while(stc.count>0)
    {
        printf("%d", pop(&stc));
    }
    printf(".\n");
    return 0;
}