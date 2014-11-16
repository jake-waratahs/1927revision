CC=gcc
CFLAGS=-Wall -Werror -std=c99 -g

all: run sorts testQueue testStack graph

run: BSTree.o runTree.o
	$(CC) $(CFLAGS) -o run BSTree.o runTree.o 

BSTree.o: BSTree.c BSTree.h
	$(CC) $(CFLAGS) -c BSTree.c 

runTree.o: runTree.c
	$(CC) $(CFLAGS) -c runTree.c 

sorts: sorts.c sorts.h
	$(CC) $(CFLAGS) -c sorts.c
	$(CC) $(CFLAGS) -o sorts sorts.o

testQueue: Queue.o testQueue.o
	$(CC) $(CFLAGS) -o testQueue Queue.o testQueue.o

testQueue.o: testQueue.c Queue.h
	$(CC) $(CFLAGS) -c testQueue.c

Queue.o:	Queue.c Queue.h
	$(CC) $(CFLAGS) -c Queue.c

testStack: testStack.o Stack.o
	$(CC) $(CFLAGS) -o testStack testStack.o Stack.o

testStack.o: testStack.c Stack.h
	$(CC) $(CFLAGS) -c testStack.c

Stack.o: Stack.c Stack.h
	$(CC) $(CFLAGS) -c Stack.c

search: List.o Graph.o runGraph.o
	$(CC) $(CFLAGS) -o graph List.o Graph.o runGraph.o

List.o: List.c List.h
	$(CC) $(CFLAGS) -c List.c

Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

runGraph.o: runGraph.c Graph.h
	$(CC) $(CFLAGS) -c runGraph.c

clean:
	rm *.o run sorts testQueue testStack graph