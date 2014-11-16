//Stack.c implementation

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

typedef struct _stack {
	int *array;
	int numItems;
} stack;

Stack newStack(void){
	Stack new = malloc(sizeof(struct _stack));
	assert(new != NULL);
	new->numItems = 0;
	new->array = NULL;
	return new;
}

int popStack(Stack s){
	assert(!stackEmpty(s));
	int result = s->array[s->numItems - 1];
	s->numItems--;
	
	if (s->numItems != 0){
		s->array = realloc(s->array, sizeof(int) * s->numItems);
		assert(s->array != NULL);
	} else {
		s->array = NULL;
	}

	return result;
}

void pushStack(Stack s, int item){
	s->array = realloc(s->array, sizeof(int) * (s->numItems + 1));
	assert(s->array != NULL);
	s->array[s->numItems] = item;
	s->numItems++;
}

int stackEmpty(Stack s){
	if (s->numItems == 0){
		return TRUE;
	} else {
		return FALSE;
	}
}

void dropStack(Stack s){
	free(s->array);
	free(s);
}

void printStack(Stack s){
	int i;
	for (i = s->numItems - 1; i >= 0; i--){
		printf("%d ", s->array[i]);
	}
}