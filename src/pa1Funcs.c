#include <pa1.h>
#include <stdio.h>
#include <math.h>

double RandDouble()
{
  return rand()/(double)RAND_MAX;
}

int PrintOne()
{
  return 1;
}

int CalculateNumEs(int v)
{
  return (v * (v-1))/2;
}

double CalculateWeight(double w1, double x1, double y1, double z1, double w2, double x2, double y2, double z2, int dimension)
{
  double sum;

  switch (dimension) {
    case 2:
      sum = ((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
      return sqrt(sum);
      break;
    case 3:
      sum = ((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2)+(z1 -z2)*(z1 -z2));
      return sqrt(sum);
      break;
    case 4:
      sum = ((w1 - w2)*(w1 - w2)+(x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2)+(z1 -z2)*(z1 -z2));
      return sqrt(sum);
      break;
    default:
      return RandDouble();
      break;
  }
}

struct E* newE(int to)
{
    struct E* newE = malloc(sizeof(struct E));
    newE->next = NULL;
    newE->to = to;
    return newE;
}

struct Heapish* createHeapish()
{
  struct Heapish* heapish = malloc(sizeof(struct Heapish));
  heapish->current_min_weight = INT_MAX;
  heapish->current_min_node = 0;
  heapish->total_mst_weight = 0;
  return heapish;
}

struct Graph* createGraph(int size, int dimension)
{
    struct Graph* graph =  malloc(sizeof(struct Graph));
    graph->node = malloc(size * sizeof(struct Node));
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

int addE(struct Graph* graph, int from, int to, int dimensions, int numpoints, double expected, int breakpoint)
{
        double w1 = graph->node[from].w;
        double x1 = graph->node[from].x;
        double y1 = graph->node[from].y;
        double z1 = graph->node[from].z;
        double w2 = graph->node[to].w;
        double x2 = graph->node[to].x;
        double y2 = graph->node[to].y;
        double z2 = graph->node[to].z;

        double weight = CalculateWeight( w1,  x1,  y1,  z1,  w2,  x2,  y2,  z2, dimensions);

        if (weight > expected && breakpoint < 1) {
          return 0;
        }

        struct E* newEdge = newE(to);
        newEdge->next = graph->node[from].head;
        graph->node[from].head = newEdge;
        newEdge->weight = weight;

        return 1;

}

void deleteAllNodes(struct E* start)
{
    while (start != NULL)
    {
        struct E* temp = start;
        free(temp);
        start = start->next;
    }
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->size; ++v)
    {
        struct E* p = graph->node[v].head;
        struct Node nd = graph->node[v];
        printf("\nAdjacency list of vertex %d coordinates w=%f, x=%f, y=%f, z=%f\n head ", v, nd.w, nd.x, nd.y, nd.z);
        while (p)
        {
            printf("-> %d, %f", p->to, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}
