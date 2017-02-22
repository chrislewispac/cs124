#include <pa1.h>
#include <stdio.h>

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
  srand((long)time(NULL));

  node verts[numpoints];

  int i = 0;
  int x;
  while (i < numpoints) {
    if (i == 0) {
      InsertNewNode(&verts[i], i);
    } else {
      x = i - 1;
      InsertNewNode(&verts[i], i);
    }

    printf("Vertex # %u \n", verts[i].id);
    i++;
  };

  MakeEdges(numpoints);

}
