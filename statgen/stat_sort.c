/* Library for processing connectivity matrix
 * 
 * Usage:
 *                             proc_matrix (number_of_molecules, connect_matrix, 
 *   num_of_molecules_in_aglomerates, aglomerates, statistic, summary_statistic)
 */

#include <stdio.h>
#include <stdlib.h>


int proc_matrix (const int num_mol, const int *connect, int *num_mol_agl, int *agl, 
                 int *stat, int *stat_all)
/* num_mol          - number of molecules
 * connect          - connectivity graph for all molecules
 * num_mol_agl      - massive of numbers of molecule in aglomerates
 * agl              - massive of aglomerates
 * stat             - massive of statistics
 * stat_all         - massive of summary statistics
 */
{
  int i, j, k, p, *bin;
  /* p              - weight / graph index
   * bin            - binary massive of labels
   */
  
//   definition and zeroing
  bin = (int *) malloc (num_mol * sizeof (int));
  if (bin == NULL)
    return 1;
  for (i=0; i<num_mol; i++)
  {
    bin[i] = 1;
    stat[i] = 0;
    num_mol_agl[i] = 0;
    for (j=0; j<num_mol; j++)
      agl[num_mol*i+j] = 0;
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
      stat_all[0]++;
    }
  }
  
//   unwraping of connectivity matrix
  p = 0;
  for (i=0; i<num_mol; i++)
    if (bin[i] == 1)
    {
      agl[num_mol*p+num_mol_agl[p]] = i;
      num_mol_agl[p]++;
      bin[i] = 0;
      
      for (j=0; j<num_mol_agl[p]; j++)
        for (k=0; k<num_mol; k++)
          if ((connect[agl[num_mol*p+j]*num_mol+k] == 1) && (bin[k] == 1))
          {
            agl[num_mol*p+num_mol_agl[p]] = k;
            num_mol_agl[p]++;
            bin[k] = 0;
          }
      
      p++;
    }
  
//   filling statistic array
  i = 0;
  while (num_mol_agl[i] > 0)
  {
    stat[num_mol_agl[i]-1]++;
    stat_all[num_mol_agl[i]-1]++;
    i++;
  }
  
  free (bin);
  
  return 0;
}