#include <pa1.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

double max_min_weight = 1;
double growth_rate = 0;
int counter = 0;

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

  //run tests if test flag given
  if (custom == 1){
    return run_tests(all_tests);
  }

  //Seed random ints, run only once or else produces same number
  time_t t;
  srand((unsigned)time(&t));

  double results[numtrials];
  int trials = numtrials;
  int breakpoint = (numpoints - 1) * 0.90;
  //initialize arr for every trial for quicker check if visited
  int visited[numpoints];


  while (numtrials != 0){
    struct Graph* graph = createGraph(numpoints, dimension);
    struct Heapish* tracker = createHeapish();

    //set arr contents to 0 for each trial
    memset(visited, 0, sizeof visited);

    //iterate backwards over nodes
    int outer = numpoints - 1;
    while (outer >= 0)
    {
      //iterate backwards over edges
      int inner = numpoints - 1;

      while (inner >= 0){

            //if not visite and not itself
            if (visited[inner] == 0 && inner != outer){
              //calculate max expected weight
              double expected = max_min_weight + 0.07;
              int ignore_max_weight = counter > breakpoint;

              //generate edge conditionally depending on weight generated
              addE(graph, outer, inner, dimension, numpoints, expected, ignore_max_weight);
            }

          inner--;
      }

      //mark as visited after all edges searched
      visited[outer] = 1;
      // printf("visited node %d\n", counter);

      //reset tracker
      tracker->current_min_node = INT_MAX;
      tracker->current_min_weight = INT_MAX;

      //capture each node's edge list after it is generated
      struct E* p = graph->node[outer].head;
      struct Node nd = graph->node[outer];

      //search the edge list for min edge to node not visited.
      while (p)
      {
        if (visited[p->to] == 0 && p->weight < tracker->current_min_weight) {
          tracker->current_min_weight = p->weight;
          tracker->current_min_node = p->to;
        }

        p = p->next;
      }

      deleteAllNodes(graph->node[outer].head);

      //go to the node with the min edge weight
      int next_node = tracker->current_min_node;

      //base case, no change in min
      if (tracker->current_min_weight != INT_MAX) {

          tracker->total_mst_weight += tracker->current_min_weight;

          //keep track of max seen, this is used with padding to trash really high edges
          if (tracker->current_min_weight > max_min_weight) {
            max_min_weight = tracker->current_min_weight;
          }

          //visit next node
          outer = next_node;

          counter++;
      } else {
          outer = -1;
          results[numtrials] = tracker->total_mst_weight;
      }
    }

   free(tracker);
   free(graph->node);
   free(graph);
    numtrials--;

  }

  //gen report
  double sum = 0;
  numtrials = trials;
  double num = trials;
  while (trials != 0){
    sum += results[trials];
    trials--;
  };

  double avg = sum/num;

  //output format = average numpoints numtrials dimension
  printf("%f %d %d %d \n", avg, numpoints, numtrials, dimension);

}
