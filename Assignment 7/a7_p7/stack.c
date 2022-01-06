/*
   CH-230-A
   a7 p7.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Pushing a number into the stack */
void push(int num, Stack *stc)
{
    stc->array[stc->count++] = num;
}

/* Popping the last number out of the stack */
int pop(Stack *stc)
{
    int num;
    num = stc->array[(stc->count)-1];
    stc->array[stc->count-1] = 0;
    (stc->count)--;
    return num;
}

/* If the stack is empty */
int isEmpty(Stack *stc)
{
    return stc->count == 0;
}

/* Emptying the stack by popping one number after the other */
void empty(Stack *stc)
{
    printf("Emptying Stack ");
    while(!isEmpty(stc))
    {
        printf("%d ", pop(stc));
    }
    printf("\n");
}