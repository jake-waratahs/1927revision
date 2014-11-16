//Graph.c implementation

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

typedef struct _graph {
	int nV;
	List *connections;
} graph;

Graph newGraph(int verticies){
	Graph new = malloc(sizeof(struct _graph));
	assert(new != NULL);
	new->nV = verticies;
	new->connections = calloc(verticies, sizeof(List));
	assert(new->connections != NULL);
	int i;
	for (i = 0; i < verticies; i++){
		new->connections[i] = newList();
	}
	return new;
}

List getConnections(Graph g, int vertex){
	return g->connections[vertex];
}

void addEdge(Graph g, int from, int to){
	addNode(g->connections[from], to);
	addNode(g->connections[to], from);
}

void dropGraph(Graph g){
	int i;
	for (i = 0; i < g->nV; i++){
		dropList(g->connections[i]);
	}
	free(g->connections);
	free(g);
}