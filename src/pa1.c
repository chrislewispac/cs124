#include <pa1.h>
#include <stdio.h>
#include "seatest.h"

typedef struct
{
  double weight;
  int to;
  int from;
  struct edge* next;
}
edge;

typedef struct
{
  struct edge* head;
  int id;
}
node;

void insertNewNode(node *n, int id)
{
  edge* edgeHead;
  n->head = edgeHead;
  n->id = id;
}

// edge* buildEdgeList(int id, int numpoints)
// {
//   int i = 0;
//   edge* head = malloc(sizeof(edge));
//   head->next = NULL;
//   head->from = id;
//   printf("head %p \n", head);
//   while (i < numpoints){
//     if (i != id){
//
//       edge* newEdge = malloc(sizeof(edge));
//
//       if (head->next == NULL){
//         head->next = newEdge;
//         newEdge->next = NULL;
//       } else {
//         newEdge->next = head->next;
//         head->next = newEdge;
//       }
//
//       newEdge->from = id;
//       newEdge->to = i;
//       newEdge->weight = rand_double();
//
//       printf("headNext= %p | edgeNext= %p | edgeFrom= %d | edgeTo= %d | weight= %f \n", head->next, newEdge->next, newEdge->from, newEdge->to, newEdge->weight);
//     }
//     i++;
//   }
//   return head;
// }

void test_hello_world()
{
        char *s = "hello world!";
        assert_string_equal("hello world!", s);
        assert_string_contains("hello", s);
        assert_string_doesnt_contain("goodbye", s);
        assert_string_ends_with("!", s);
        assert_string_starts_with("hell", s);
}

//
// put the test into a fixture...
//
void test_fixture_hello( void )
{
        test_fixture_start();
        run_test(test_hello_world);
        test_fixture_end();
}

//
// put the fixture into a suite...
//
void all_tests( void )
{
        test_fixture_hello();
}


int main( int argc, char *argv[] )
{

  /* Check for arguments and format them properly */
  if( argc != 5 ) {
     printf("Please supply arguments in the format ./randmst 0 numpoint numtrials dimension\n");
     return 0;
  }

  int custom    = strtol(argv[1], NULL, 10);
  int numpoints = strtol(argv[2], NULL, 10);
  int numtrials = strtol(argv[3], NULL, 10);
  int dimension = strtol(argv[4], NULL, 10);
  printf("custom = %d, numpoints = %d, numtrials = %d, dimension = %d \n", custom, numpoints, numtrials, dimension);

  if (custom == 1){
    return run_tests(all_tests);
  }

  //Seed random ints, run only once or else produces same number
  srand((long)time(NULL));

  node verts[numpoints];

  int i = 0;
  int x;
  while (i < numpoints) {
    if (i == 0) {
      insertNewNode(&verts[i], i);
    } else {
      x = i - 1;
      insertNewNode(&verts[i], i);
    }
    // edge* edgeHead = buildEdgeList(i, numpoints);
    //
    // edge* next = edgeHead->next;
    //
    // while (next != NULL){
    //   next->next =
    //   next->
    // }

    // printf("edgeList head %p \n", edgeHead);
    printf("Vertex # %u \n", verts[i].id);
    i++;
  };

}
