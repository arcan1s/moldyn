/**
 * @file
 */

#include <stdlib.h>


/**
 * @fn proc_matrix
 */
int proc_matrix (const int num_mol, const int *connect, int *num_mol_agl, int *agl, 
                 int *stat, int *stat_all)
/**
 * @brief function that processes connectivity matrix
 * @code
 * proc_matrix (number_of_molecules, connect_matrix, num_of_molecules_in_agglomerates, 
 *              agglomerates, statistic, summary_statistic);
 * @endcode
 * 
 * @param num_mol         number of molecules
 * @param connect         connectivity graph for all molecules
 * @param num_mol_agl     massive of number of molecules in agglomerates
 * @param agl             massive of agglomerates
 * @param stat            massive of statistic
 * @param stat_all        massive of summary statistic
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */
{
  int i, j, k, p, *bin;
  
  /* p                    weight / graph index
   * bin                  binary massive of labels
   */
  
/// <b>Work blocks</b>
  
// definition and zeroing
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
  
/// <pre>   select non-bonded molecules </pre>
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
  
/// <pre>   unwraping of connectivity matrix </pre>
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
  
/// <pre>   filling statistic array </pre>
  i = 0;
  while (num_mol_agl[i] > 0)
  {
    stat[num_mol_agl[i]-1]++;
    stat_all[num_mol_agl[i]-1]++;
    i++;
  }
  
/// <pre>   free memory </pre>
  free (bin);
  
  return 0;
}