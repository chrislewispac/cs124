#include <pa1.h>
#include <stdio.h>

double RandDouble() {
  return rand()/(double)RAND_MAX;
}

int PrintOne() {
  return 1;
}

int CalculateNumEs(int v) {
  return (v * (v-1))/2;
}

struct E* newE(int to)
{
    struct E* newE = (struct E*) malloc(sizeof(struct E));
    newE->next = NULL;
    newE->to = to;
    return newE;
}

struct Graph* createGraph(int size, int dimension)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->node = (struct Node*) malloc(size * sizeof(struct Node));

    graph->size = size;

    int i = 0;
    while (i < size) {
      graph->node[i].head = NULL;
      switch (dimension) {
        case 2:
          graph->node[i].x = RandDouble();
          graph->node[i].y = RandDouble();
          break;
        case 3:
          graph->node[i].x = RandDouble();
          graph->node[i].y = RandDouble();
          graph->node[i].z = RandDouble();
          break;
        case 4:
          graph->node[i].w = RandDouble();
          graph->node[i].x = RandDouble();
          graph->node[i].y = RandDouble();
          graph->node[i].z = RandDouble();
          break;
      }
      i++;
    };

    return graph;
}

void addE(struct Graph* graph, int from, int to)
{
    struct E* newEdge = newE(to);
    newEdge->next = graph->node[from].head;
    newEdge->weight = RandDouble();

    graph->node[from].head = newEdge;

    newEdge = newE(from);
    newEdge->next = graph->node[to].head;
    newEdge->weight = RandDouble();
    graph->node[to].head = newEdge;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->size; ++v)
    {
        struct E* pCrawl = graph->node[v].head;
        struct Node nd = graph->node[v];
        printf("Adjacency list of vertex %d coordinates w=%f, x=%f, y=%f, z=%f\n head ", v, nd.w, nd.x, nd.y, nd.z);
        while (pCrawl)
        {
            printf("-> %d, %f", pCrawl->to, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
