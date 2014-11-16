//List.c implementation file

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"

typedef struct _node *Node;

typedef struct _node {
	int value;
	Node next;
} node;

typedef struct _list {
	Node first;
} list;

List newList(void){
	List new = malloc(sizeof(struct _list));
	assert(new != NULL);
	new->first = NULL;
	return new;
}

void addNode(List l, int item){
	Node new = malloc(sizeof(struct _node));
	assert(new != NULL);
	new->value = item;
	new->next = l->first;
	l->first = new;
}

void dropList(List l){
	if (l->first != NULL){
		Node curr = l->first;
		Node next = curr->next;
		while (next != NULL){
			free(curr);
			curr = next;
			next = curr->next;
		}
		free(curr);
	}
	free(l);
}