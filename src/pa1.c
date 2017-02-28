#include <pa1.h>
#include <stdio.h>
#include <time.h>

double mst_weight;

int recurse_on_nodes (int num_nodes, int num_other_nodes, struct Graph* graph, int dimension){
  if (num_other_nodes > 0  ) {
    addE(graph, num_nodes, num_other_nodes, dimension);
    recurse_on_nodes(num_nodes, (num_other_nodes - 1), graph, dimension);
  } else if (num_nodes > 1) {
    addE(graph, num_nodes, num_other_nodes, dimension);
    recurse_on_nodes((num_nodes -1), (num_nodes -2), graph, dimension);
  } else if (num_nodes = 1) {
    addE(graph, num_nodes, num_other_nodes);
  }
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

  //run tests if test flag given
  if (custom == 1){
    return run_tests(all_tests);
  }

  //Seed random ints, run only once or else produces same number
  time_t t;
  srand((unsigned)time(&t));

  struct Graph* graph = createGraph(numpoints, dimension);


  recurse_on_nodes((numpoints-1), (numpoints -2), graph, dimension);
  //
  // int i = 0;
  // while (i < numpoints)
  // {
  //   int x = i+1;
  //   while (x < numpoints){
  //       addE(graph, i, x, dimension);
  //       x++;
  //   }
  //   i++;
  // }

  printGraph(graph);

}
