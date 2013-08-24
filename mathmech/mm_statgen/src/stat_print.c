/**
 * @file
 */

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


/**
 * @fn printing_agl
 */
int printing_agl (const char *input, const char *output, const int *connect, 
                  const int num_mol, const int *true_label_mol, const int *num_mol_agl, 
                  const int *agl, const int *stat, const int max_depth, int *type_agl)
/**
 * @brief function that prints aglomerates to output file
 * @code
 * printing_agl (input_file, output_file, number_of_molecules, true_label_molecules, 
 *               num_of_molecules_in_aglomerates, aglomerates, statistic, max_depth, 
 *               type_of_aglomerate);
 * @endcode
 * 
 * @param input           input file name
 * @param output          output file name
 * @param connect         connectivity graph for all molecules
 * @param num_mol         number of molecules
 * @param true_label_mol  massive of true numbers of molecule for atoms
 * @param num_mol_agl     massive of number of molecules in aglomerates
 * @param agl             massive of aglomerates
 * @param stat            massive of statistic
 * @param max_depth       maximum depth for check cycles in graph analyze
 * @param type_agl        massive of number of aglomerate types
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */
{
  int error, i, *iso, j, k, *label_matrix, *matrix;
  FILE *f_out;
  
/* iso                    isomorphic graph in database
 * label_matrix           massive of indexes of molecule
 * matrix                 connectivity graph
 * f_out                  output file
 */
  
/// <b>Work blocks</b>
  
  iso = (int *) malloc (max_depth * sizeof (int));
  if (iso == NULL)
    return 1;
  f_out = fopen (output, "a");
  
/// <pre>   print header </pre>
  fprintf (f_out, "FILE=%s\nSTATISTIC\n|   n   |   N   |\n-----------------\n", input);
  for (i=0; i<num_mol; i++)
    if (stat[i] != 0)
      fprintf (f_out, " %7i %7i \n", i+1, stat[i]);
  fprintf (f_out, "-----------------\n");
  
/// <pre>   print body </pre>
  for (i=0; i<num_mol; i++)
    if (num_mol_agl[i] > 0)
    {
/// <pre>      creating connectivity graph </pre>
      label_matrix = (int *) malloc (num_mol * sizeof (int));
      matrix = (int *) malloc (num_mol_agl[i] * num_mol_agl[i] * sizeof (int));
      if ((matrix == NULL) ||
        (label_matrix == NULL))
        return 1;
      for (j=0; j<num_mol_agl[i]; j++)
        for (k=0; k<num_mol_agl[i]; k++)
          matrix[num_mol_agl[i]*j+k] = 0;
      
      for (j=0; j<num_mol_agl[i]; j++)
        label_matrix[agl[num_mol*i+j]] = j;
      for (j=0; j<num_mol_agl[i]; j++)
        for (k=j+1; k<num_mol_agl[i]; k++)
          if (connect[num_mol*agl[num_mol*i+j]+agl[num_mol*i+k]] == 1)
          {
            matrix[label_matrix[agl[num_mol*i+j]]*num_mol_agl[i]+label_matrix[agl[num_mol*i+k]]] = 1;
            matrix[label_matrix[agl[num_mol*i+k]]*num_mol_agl[i]+label_matrix[agl[num_mol*i+j]]] = 1;
          }

/// <pre>      graph topology analyze </pre>
      if (max_depth > 0)
        error = graph_analyze (num_mol_agl[i], matrix, max_depth, iso);
      if (error > 0)
        return 1;
      
// print class of aglomerate
      fprintf (f_out, "AGL=%i=", num_mol_agl[i]);
      for (j=0; j<max_depth; j++)
      {
// number of tails
        if (j == 0)
          if ((iso[j] == 0) || ((iso[j] <= 2) && (iso[j] == 0)))
// not branched
            type_agl[2]++;
// branched
          else
            type_agl[3]++;
// number of cycles
        else if (j == 1)
          if (iso[j] > 0)
// cycle
            type_agl[1]++;
          else
// linear
            type_agl[0]++;
        else if (j > 1)
// number of n_cycles
          type_agl[j+2] += iso[j];
        
        fprintf (f_out, "%i.", iso[j]);
      }
      fprintf (f_out, "\n");
      for (j=0; j<num_mol_agl[i]; j++)
      {
        fprintf (f_out, "%7i=", true_label_mol[agl[num_mol*i+j]]);
        for (k=0; k<num_mol_agl[i]; k++)
          if (matrix[j*num_mol_agl[i]+k] == 1)
            fprintf (f_out, "%i,", true_label_mol[agl[num_mol*i+k]]);
        fprintf (f_out, "\n");
      }
      
/// <pre>      free memory </pre>
      free (matrix);
      free (label_matrix);
    }
  
  fprintf (f_out, "---------------------------------------------------\n");
  fclose (f_out);
  
/// <pre>   free memory </pre>
  free (iso);
  
  return 0;
}