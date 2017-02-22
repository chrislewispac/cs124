#include <pa1.h>
#include <stdio.h>

double RandDouble() {
  return rand()/(double)RAND_MAX;
}

int PrintOne() {
  return 1;
}

int CalculateNumEdges(int v) {
  return (v * (v-1))/2;
}

void InsertNewNode(node *n, int id)
{
  edge* edgeHead;
  n->head = edgeHead;
  n->id = id;
}

int MakeEdges(int v)
{
  int counter = 0;
  int i = 0;
  while (i < v){
    int x = i;
    while (x < v){
      if (x != i){
        edge* newEdge = malloc(sizeof(edge));
        newEdge->from = i;
        newEdge->to = x;
        newEdge->weight = RandDouble();
        printf("From = %d To = %d Weight = %f \n", newEdge->from, newEdge->to, newEdge->weight);
        counter++;
      }
      x++;
    }

    i++;
  }
  return counter;
}
