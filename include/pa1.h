#include <time.h>
#include <limits.h>
#include <stdlib.h>

typedef struct edge
{
  double weight;
  int to;
  int from;
  struct edge* next;
}
edge;

typedef struct node
{
  struct edge* head;
  int id;
}
node;

int MakeEdges(int v);
int PrintOne();
int CalculateNumEdges(int v);
double RandDouble();
void InsertNewNode(node *n, int id);
void test_fixture_hello(void);
void test_hello_world();
void all_tests(void);
int run_tests();
