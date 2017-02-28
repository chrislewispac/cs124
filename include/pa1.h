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

int PrintOne();
int CalculateNumEs(int v);
double RandDouble();
void addE();
void printGraph();
struct E* newE(int to);
struct Graph* createGraph(int size, int dimension);
void test_fixture_hello(void);
void test_fixture_hello(void);
void test_hello_world();
void all_tests(void);
int run_tests();
