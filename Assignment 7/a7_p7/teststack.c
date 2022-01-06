/*
   CH-230-A
   a7 p7.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main () {
    int num, i=1;
    char c;
    Stack stc;
    stc.count = 0;

    while (((c = getchar()) != EOF) && (i==1))
    {
        switch(c)
        {
            /* A new number is put into the stack
            if the following character is entered */
            case 's':
                if (stc.count<12)
                {
                    scanf("%d", &num);
                    getchar();
                    push(num, &stc);
                    printf("Pushing %d\n", num);
                }
                else
                {
                    printf("Pushing Stack Overflow\n");
                }
                break;
            
            /* A number is popped out of the stack
            if the following character is entered */
            case 'p':
                if (stc.count>0)
                {
                    printf("Popping %d\n", pop(&stc));
                }
                else
                {
                    printf("Popping Stack Underflow\n");
                }
                break;
            
            /* The stack will be emptied
            if the following character is entered */
            case 'e':
                empty(&stc);
                break;
            
            /* The program will stop
            if the following character is entered */
            case 'q':
                printf("Quit\n");
                i = 0;
                break;
        }
    }
    return 0;
}