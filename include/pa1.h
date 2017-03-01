#include <time.h>
#include <limits.h>
#include <stdlib.h>

struct E
{
    int to;
    double weight;
    struct E* next;
};

struct Node
{
    struct E *head;
    int visited; //0 or 1
    double w;
    double x;
    double y;
    double z;
};

struct Graph
{
    struct Node* node;
    int size;
};

struct Heapish {
  double total_mst_weight;
  double current_min_weight;
  int current_min_node;
};

int PrintOne();
int CalculateNumEs(int v);
double CalculateWeight();
double RandDouble();
int addE();
void printGraph();
struct E* newE(int to);
struct Graph* createGraph(int size, int dimension);
struct Heapish* createHeapish();
void test_fixture_hello(void);
void test_fixture_hello(void);
void test_hello_world();
void all_tests(void);
int run_tests();
