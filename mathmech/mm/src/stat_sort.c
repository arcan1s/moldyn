/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 */

#include <stdlib.h>

#include <mathmech/stat_sort.h>
#include <mathmech/var_types.h>


/**
 * @fn proc_matrix
 */
int proc_matrix (const system_info _system_info, const int *connect, int *num_mol_agl, 
                 int *agl, int *stat, int *stat_all)
{
  int i, j, k, p, *bin;
  
  /* p                    weight / graph index
   * bin                  binary massive of labels
   */
  
/// <b>Work blocks</b>
  
// definition and zeroing
  bin = (int *) malloc (_system_info.num_mol * sizeof (int));
  if (bin == NULL)
    return 1;
  for (i=0; i<_system_info.num_mol; i++)
  {
    bin[i] = 1;
    stat[i] = 0;
    num_mol_agl[i] = 0;
    for (j=0; j<_system_info.num_mol; j++)
      agl[_system_info.num_mol*i+j] = 0;
  }
  
/// <pre>   select non-bonded molecules </pre>
  for (i=0; i<_system_info.num_mol; i++)
  {
    p = 0;
    for (j=0; j<_system_info.num_mol; j++)
      p += connect[i*_system_info.num_mol+j];
    if (p == 0)
    {
      bin[i] = 0;
      stat[0]++;
      stat_all[0]++;
    }
  }
  
/// <pre>   unwraping of connectivity matrix </pre>
  p = 0;
  for (i=0; i<_system_info.num_mol; i++)
    if (bin[i] == 1)
    {
      agl[_system_info.num_mol*p+num_mol_agl[p]] = i;
      num_mol_agl[p]++;
      bin[i] = 0;
      
      for (j=0; j<num_mol_agl[p]; j++)
        for (k=0; k<_system_info.num_mol; k++)
          if ((connect[agl[_system_info.num_mol*p+j]*_system_info.num_mol+k] == 1) && (bin[k] == 1))
          {
            agl[_system_info.num_mol*p+num_mol_agl[p]] = k;
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
