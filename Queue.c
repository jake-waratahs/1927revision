//Queue.c implementation as a linked list

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef struct _node *Node;

typedef struct _node {
	int value;
	Node next;
} node;

typedef struct _queue {
	Node first;
	Node last;
} queue;

Queue newQueue(void){
	Queue new = malloc(sizeof(struct _queue));
	new->first = NULL;
	new->last = NULL;
	return new;
}

int queueLeave(Queue q){
	assert(q->first != NULL);
	
	int result = q->first->value;
	Node toDelete = q->first;

	if (q->first == q->last){
		q->last = NULL;
	}
	
	q->first = q->first->next;

	free(toDelete);

	return result;
}

void queueJoin(Queue q, int item){
	Node new = malloc(sizeof(struct _node));
	new->value = item;
	new->next = NULL;

	if (q->first == NULL){
		q->first = new;
	} else {
		q->last->next = new;
	}

	q->last = new;
}

void dropQueue(Queue q){
	while (q->first != NULL){
		Node toDelete = q->first;
		q->first = q->first->next;
		free(toDelete);
	}
	free(q);
}

int queueEmpty(Queue q){
	if (q->first == NULL){
		return TRUE;
	} else {
		return FALSE;
	}
}

void printQueue(Queue q){
	Node curr;
	curr = q->first;
	while (curr != NULL){
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}
