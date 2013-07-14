#include <stdio.h>
#include <stdlib.h>


int test_func(float *test)
{
  int i, j;
  
  for (i=0; i<3; i++)
    test[i] = i;
  printf("\n%lf\n", test[1]);
  
  return 0;
}


int main (int argc, char *argv[])
{
  int i, j;
  float test[3];
  
  for (i=0; i<3; i++)
    test[i] = 0.0;
  for (i=0; i<3; i++)
    printf ("%3.1f\n", test[i]);
  
  printf ("Done\n");
  
  test_func(test);

  for (i=0; i<3; i++)
    printf ("%3.1f\n", test[i]);
  
  return 0;
}