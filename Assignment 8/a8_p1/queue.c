/*
   CH-230-A
   a8 p1.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* Function definitions */

/* Initializing a queue */
void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}
/* Testing if queue is full */
int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}
/* Testing if queue is empty */
int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}
/* Counting the number of items in the queue */
int queue_item_count(const Queue *pq)
{
	return pq->items;
}

static void item_to_node(Item item, Node *ptr_node); // Function declaration

/* Adding a new element to the queue */
int enqueue(Item item, Queue *pq)
{
    /* Return -1 if the queue is full */
    if (queue_is_full(pq)==1)
    {
        return -1;
    }
    
    Node *new1;
    new1 = (Node*)malloc(sizeof(new1));
    if(!new1)
    {
        exit(1);
    }
    
    item_to_node(item, new1); /* Copying item */
    new1->next = NULL;
    /* The case when the queue is empty */
    if (queue_is_empty(pq) == 1)
    {
        pq->front = new1;
    }
    else
        (pq->rear)->next = new1;
    pq->rear = new1;
    pq->items++;
    
    free(new1); /* Freeing the memory */
    return 0;
}
/* Removing an element from the queue */
int dequeue(Item *pitem, Queue *pq)
{
    return 0;
}
/* Emptying the queue */
void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}
/* Copying item to the node */
static void item_to_node(Item item, Node *ptr_node)
{
	ptr_node->item = item;
}

