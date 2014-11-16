//Testing the Queue ADT

#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]){

	Queue q = newQueue();

	assert(queueEmpty(q));

	queueJoin(q, 5);
	queueJoin(q, 8);
	queueJoin(q, 3);
	queueJoin(q, 9);
	queueJoin(q, 2);

	printQueue(q);

	assert(!queueEmpty(q));

	assert(queueLeave(q) == 5);
	assert(queueLeave(q) == 8);
	assert(queueLeave(q) == 3);
	assert(queueLeave(q) == 9);
	assert(queueLeave(q) == 2);

	assert(queueEmpty(q));

	dropQueue(q);

	return EXIT_SUCCESS;
}