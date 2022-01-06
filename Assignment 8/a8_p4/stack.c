/*
   CH-230-A
   a8 p4.c
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

/* Converting the number into binary */
void conv_binary(Stack *stc, unsigned int num)
{
    int idx = 0;
    unsigned int bin_array[1000];
    while(num>0)
    {
        /* Storing the remainder in the array */
        bin_array[idx] = num % 2;
        /* Pushing the bits into the stack */
        push(bin_array[idx], stc);
        num /= 2;
        idx++;
    }
}