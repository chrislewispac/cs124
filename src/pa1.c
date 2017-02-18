#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pa1.h>

int main( int argc, char *argv[] )
{

  myPrintHelloMake();

  /* Check for arguments and format them properly */
  if( argc == 5 ) {
    int custom    = strtol(argv[1], NULL, 10);
    int numpoints = strtol(argv[2], NULL, 10);
    int numtrials = strtol(argv[3], NULL, 10);
    int dimension = strtol(argv[4], NULL, 10);
    printf("custom = %d, numpoints = %d, numtrials = %d, dimension = %d \n", custom, numpoints, numtrials, dimension);
  }
  else if( argc < 5 ) {
     printf("Not Enough arguments supplied.\n");
  }
  else {
     printf("Please supply arguments in the format ./randmst 0 numpoint numtrials dimension .\n");
  }

}
