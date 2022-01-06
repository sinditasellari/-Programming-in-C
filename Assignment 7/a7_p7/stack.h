/*
   CH-230-A
   a7 p7.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#ifndef STACKH
#define STACKH

typedef struct stack {
unsigned int count;
int array[12]; // Container
} Stack;

/* Functions declaration */
void push(int, Stack*);
int pop(Stack*);
int isEmpty(Stack*);
void empty(Stack*);

#endif 
