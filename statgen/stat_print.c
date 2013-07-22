/* Library for printing aglomerates
 * 
 * Usage:
 *                  printing_agl (input_file, output_file, number_of_molecules, 
 *          true_label_molecules, num_of_molecules_in_aglomerates, aglomerates, 
 *                                     statistic, max_depth, type_of_aglomerate)
 */

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


int printing_agl (const char *input, const char *output, const int *connect, 
                  const int num_mol, const int *true_label_mol, const int *num_mol_agl, 
                  const int *agl, const int *stat, const int max_depth, int *type_agl)
/* input            - name of file with coordinates
 * output           - name of output file
 * connect          - connectivity graph for all molecules
 * num_mol          - number of molecules
 * true_label_mol   - massive of true numbers of molecule for atoms
 * num_mol_agl      - massive of numbers of molecule in aglomerates
 * agl              - massive of aglomerates
 * stat             - massive of statistics
 * max_depth        - max depth for check cycles in graph analyze
 * type_agl         - massive of numbers of aglomerate types
 */
{
  int i, *iso, j, k, *label_matrix, *matrix;
  FILE *f_out;
/* iso              - isomorphic graph in database
 * label_matrix     - massive of indexes of molecule
 * matrix           - connectivity graph
 * f_out            - output file
 */
  
  iso = (int *) malloc (max_depth * sizeof (int));
  f_out = fopen (output, "a");
  
//   head
  fprintf (f_out, "FILE=%s\nSTATISTIC\n|   n   |   N   |\n-----------------\n", input);
  for (i=0; i<num_mol; i++)
    if (stat[i] != 0)
      fprintf (f_out, " %7i %7i \n", i+1, stat[i]);
  fprintf (f_out, "-----------------\n");
  
//   body
  for (i=0; i<num_mol; i++)
    if (num_mol_agl[i] > 0)
    {
//       creating connectivity graph
      matrix = (int *) malloc (num_mol_agl[i] * num_mol_agl[i] * sizeof (int));
      for (j=0; j<num_mol_agl[i]; j++)
        for (k=0; k<num_mol_agl[i]; k++)
          matrix[num_mol_agl[i]*j+k] = 0;
      label_matrix = (int *) malloc (num_mol * sizeof (int));
      if ((matrix == NULL) ||
        (label_matrix == NULL))
        return 1;
      
      for (j=0; j<num_mol_agl[i]; j++)
        label_matrix[agl[num_mol*i+j]] = j;
      for (j=0; j<num_mol_agl[i]; j++)
        for (k=j+1; k<num_mol_agl[i]; k++)
          if (connect[num_mol*agl[num_mol*i+j]+agl[num_mol*i+k]] == 1)
          {
            matrix[label_matrix[agl[num_mol*i+j]]*num_mol_agl[i]+label_matrix[agl[num_mol*i+k]]] = 1;
            matrix[label_matrix[agl[num_mol*i+k]]*num_mol_agl[i]+label_matrix[agl[num_mol*i+j]]] = 1;
          }

//       graph topology analyze
      if (max_depth > 0)
        graph_analyze (num_mol_agl[i], matrix, max_depth, iso);
      
//       printing class of aglomerate
      fprintf (f_out, "AGL=%i=", num_mol_agl[i]);
      for (j=0; j<max_depth; j++)
      {
//         number of tails
        if (j == 0)
          if (iso[j] > 2)
//             branched
            type_agl[3]++;
          else
//             not branched
            type_agl[2]++;
//         number of cycles
        else if (j == 1)
          if (iso[j] > 0)
//             cycle
            type_agl[1]++;
          else
//             linear
            type_agl[0]++;
        else if (j > 1)
//           number of n_cycles
          type_agl[j+2] += iso[j];
        
        fprintf (f_out, "%i.", iso[j]);
      }
      fprintf (f_out, "\n");
      for (j=0; j<num_mol_agl[i]; j++)
      {
        fprintf (f_out, "%7i=", true_label_mol[agl[num_mol*i+j]]);
        for (k=0; k<num_mol_agl[i]; k++)
        {
          if (matrix[j*num_mol_agl[i]+k] == 1)
            fprintf (f_out, "%i,", true_label_mol[agl[num_mol*i+k]]);
        }
        fprintf (f_out, "\n");
      }
      
//       free memory
      free (matrix);
      free (label_matrix);
    }
  
  fprintf (f_out, "---------------------------------------------------\n");
  fclose (f_out);
  free (iso);
  return 0;
}