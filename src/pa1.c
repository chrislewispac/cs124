#include <pa1.h>
#include <stdio.h>

typedef struct
{
  struct node* next;
  int id;
}
node;

void insertNewNode(node *n, int id)
{
  n->next = NULL;
  n->id = id;
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

  //Seed random ints, run only once or else produces same number
  srand((long)time(NULL));

  node verts[numpoints];

  int i = 0;
  while (i < numpoints) {
    insertNewNode(&verts[i], i);
    printf("Vertex # %d: %u\n", i, verts[i].id);
    i++;
  };

}
