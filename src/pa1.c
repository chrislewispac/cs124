#include <pa1.h>
#include <stdio.h>
#include <time.h>

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
  //printf("custom = %d, numpoints = %d, numtrials = %d, dimension = %d \n", custom, numpoints, numtrials, dimension);

  //run tests if test flag given
  if (custom == 1){
    return run_tests(all_tests);
  }

  //Seed random ints, run only once or else produces same number
  time_t t;
  srand((unsigned)time(&t));

  double results[numtrials];
  int trials = numtrials;

  while (numtrials != 0){
    struct Graph* graph = createGraph(numpoints, dimension);

    struct Heapish* tracker = createHeapish();


    int outer = numpoints - 1;
    while (outer >= 0)
    {
      //printf("outer %d \n", outer);
      int inner = numpoints - 1;
      // char enter = 0;
      // printf("Press enter to continue outer = %d inner = %d \n", outer, inner);
      // while (enter != '\r' && enter != '\n') { enter = getchar(); }
      while (inner >= 0){
            // printf("Press enter to continue outer = %d inner = %d \n", outer, inner);
            // char enter = 0;
            // while (enter != '\r' && enter != '\n') { enter = getchar(); }

            if (graph->node[outer].visited == 0 && inner != outer){
              addE(graph, outer, inner, dimension, numpoints);
              //printf("inner %d \n", inner);
            }

          inner--;
      }

      graph->node[outer].visited =1;

      tracker->current_min_node = 10000000;
      tracker->current_min_weight = 10000000;

      struct E* p = graph->node[outer].head;
      struct Node nd = graph->node[outer];

      while (p)
      {
        //printf("examining node %d visited? %d current_min_weight %f \n", p->to, graph->node[p->to].visited, tracker->current_min_weight);
        if (graph->node[p->to].visited == 0 && p->weight < tracker->current_min_weight) {
          tracker->current_min_weight = p->weight;
          tracker->current_min_node = p->to;
        }

        p = p->next;
      }
      //printf("current_min_weight %f, current_min_node %d, total_mst_weight %f \n", tracker->current_min_weight, tracker->current_min_node, tracker->total_mst_weight);
      // printf("\n");
      int next_node = tracker->current_min_node;

      if (tracker->current_min_weight!= 10000000) {
          tracker->total_mst_weight += tracker->current_min_weight;
          free(graph->node[outer].head);
          outer = next_node;
      } else {
          outer = -1;
          // printf("min_span_tree = %f \n", tracker->total_mst_weight);
          results[numtrials] = tracker->total_mst_weight;
      }
    }

    // printGraph(graph);
    numtrials--;

  }

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
