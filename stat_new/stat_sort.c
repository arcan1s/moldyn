/* Library for processing connectivity matrix
 * 
 * Usage:
 */

#include <stdio.h>
#include <stdlib.h>


int proc_matrix (int num_mol, const int *connect, const int *num_bond, int *num_mol_agl, int *agl, int *stat)
{
  int i, j, p, *bin;
  
//   definition and zeroing
  bin = (int *) malloc (num_mol * sizeof (int));
  for (i=0; i<num_mol; i++)
    bin[i] = 0;
  for (i=0; i<5000; i++)
  {
    stat[i] = 0;
    num_mol_agl[i] = 0;
    for (j=0; j<5000; j++)
      agl[5000*i+j] = 0;
  }
  
  p = num_mol;
  for (i=0; i<num_mol; i++)
    if (num_bond[i] == 0)
    {
      bin[i] = 0;
      stat[0]++;
      p--;
    }
  
  while (p > 0)
  {
    
  }
  
  free (bin);
  
  return 0;
}


int main (int argc, char *argv[])
{
  return 0;
}