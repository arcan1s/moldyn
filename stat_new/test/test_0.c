#include <stdio.h>
#include <stdlib.h>


int test_func(float* test)
{
  int i, j;
  
  *test = 3.0;
  
  return 0;
}


int main (int argc, char *argv[])
{
  int i, j;
  float test;
  
  test = 0.0;
  printf ("%3.1f\n", test);
  
  printf ("Done\n");
  
  test_func(&test);

  printf ("%3.1f\n", test);
  
  return 0;
}
