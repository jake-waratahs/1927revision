//testStack.c Stack tests

#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main (int argc, char *argv[]){

	Stack s = newStack();

	assert(stackEmpty(s));

	pushStack(s, 5);
	pushStack(s, 8);
	pushStack(s, 3);
	pushStack(s, 9);
	pushStack(s, 2);

	printStack(s);

	assert(!stackEmpty(s));

	assert(popStack(s) == 2);
	assert(popStack(s) == 9);
	assert(popStack(s) == 3);
	assert(popStack(s) == 8);
	assert(popStack(s) == 5);

	assert(stackEmpty(s));

	dropStack(s);

	return EXIT_SUCCESS;
}