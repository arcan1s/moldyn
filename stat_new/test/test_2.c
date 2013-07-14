#include <stdio.h>
#include <stdlib.h>


int test_func(int **test)
{
  int i, j;

  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      test[i][j] = 3;
  
  return 0;
}


int main (int argc, char *argv[])
{
  int i, j;
  int test[3][3];
  
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      test[i][j] = 0;
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      printf ("%i\n", test[i][j]);
  
  printf ("Done\n");
  
  test_func((int **) test);

  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      printf ("%i\n", test[i][j]);
  
  return 0;
}