CC=gcc
CFLAGS=-Wall -Werror -std=c99 -g

all: run sorts testQueue

run: BSTree.o runTree.o
	$(CC) $(CFLAGS) -o run BSTree.o runTree.o 

BSTree.o: BSTree.c BSTree.h
	$(CC) $(CFLAGS) -c BSTree.c 

run.o: runTree.c
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

clean:
	rm *.o run sorts testQueue