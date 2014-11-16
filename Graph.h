//Graph.h interface file

#include "List.h"

typedef struct _graph *Graph;

Graph newGraph(int verticies);

List getConnections(Graph g, int vertex);

void addEdge(Graph g, int from, int to);

void dropGraph(Graph g);