CC=gcc
CFLAGS=-Wall -Werror -std=c99 -g

all: run sorts

run: BSTree.o runTree.o
	$(CC) $(CFLAGS) -o run BSTree.o runTree.o 

BSTree.o: BSTree.c BSTree.h
	$(CC) $(CFLAGS) -c BSTree.c 

run.o: runTree.c
	$(CC) $(CFLAGS) -c runTree.c 

sorts: sorts.c sorts.h
	$(CC) $(CFLAGS) -c sorts.c
	$(CC) $(CFLAGS) -o sorts sorts.o

clean:
	rm *.o run sorts