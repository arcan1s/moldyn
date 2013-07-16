/* Library for processing connectivity matrix
 * 
 * Usage:
 *    proc_matrix (number_of_molecules, connect_matrix, max_size_of_aglomerates,
 *                      num_of_molecules_in_aglomerates, aglomerates, statistic)
 */

#include <stdio.h>
#include <stdlib.h>


int proc_matrix (int num_mol, const int *connect, int max_size, int *num_mol_agl, int *agl, int *stat)
{
  int i, j, k, p, *bin;
  
//   definition and zeroing
  bin = (int *) malloc (num_mol * sizeof (int));
  for (i=0; i<num_mol; i++)
    bin[i] = 0;
  for (i=0; i<max_size; i++)
  {
    stat[i] = 0;
    num_mol_agl[i] = 0;
    for (j=0; j<max_size; j++)
      agl[max_size*i+j] = 0;
  }
  
//   select non-bonded molecules
  for (i=0; i<num_mol; i++)
  {
    p = 0;
    for (j=0; j<num_mol; j++)
      p += connect[i*num_mol+j];
    if (p == 0)
    {
      bin[i] = 0;
      stat[0]++;
    }
  }
  
//   unwraping of connectivity matrix
  p = 0;
  for (i=0; i<num_mol; i++)
    if (bin[i] == 1)
    {
      agl[max_size*p+num_mol_agl[p]] = i;
      num_mol_agl[p]++;
      bin[i] = 0;
      
      for (j=0; j<num_mol_agl[p]; j++)
        for (k=0; k<num_mol; k++)
          if ((connect[agl[max_size*p+j]*num_mol+k] == 1) && (bin[k] == 1))
          {
            agl[max_size*p+num_mol_agl[p]] = k;
            num_mol_agl[p]++;
            bin[k] = 0;
          }
      
      p++;
    }
  
//   filling statistic array
  for (i=0; i<max_size; i++)
    stat[num_mol_agl[i]-1]++;
  
  free (bin);
  
  return 0;
}


int main (int argc, char *argv[])
{
  return 0;
}