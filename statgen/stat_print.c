/* Library for printing aglomerates
 * 
 * Usage:
 *                  printing_agl (input_file, output_file, number_of_molecules, 
 *          true_label_molecules, num_of_molecules_in_aglomerates, aglomerates, 
 *                                                statistic, type_of_aglomerate)
 */

#include <stdio.h>
#include <stdlib.h>


int printing_agl (char *input, char *output, const int *connect, int num_mol, 
                  const int *true_label_mol, const int *num_mol_agl, 
                  const int *agl, const int *stat, int *type_agl)
/* input            - name of file with coordinates
 * output           - name of output file
 * connect          - connectivity graph for all molecules
 * num_mol          - number of molecules
 * true_label_mol   - massive of true numbers of molecule for atoms
 * num_mol_agl      - massive of numbers of molecule in aglomerates
 * agl              - massive of aglomerates
 * stat             - massive of statistics
 * type_agl         - massive of numbers of aglomerate types
 */
{
  int i, iso, j, k, p, type, *label_matrix, **matrix;
  FILE *f_out;
/* iso              - isomorphic graph in database
 * type             - number of cycle in aglomerates
 * label_matrix     - massive of indexes of molecule
 * matrix           - connectivity graph
 * f_out            - output file
 */
  
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
      matrix = (int **) malloc (num_mol_agl[i] * sizeof (int *));
      for (j=0; j<num_mol_agl[i]; j++)
      {
        matrix[j] = (int *) malloc (num_mol_agl[i] * sizeof (int));
        for (k=0; k<num_mol_agl[i]; k++)
          matrix[j][k] = 0;
      }
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
            matrix[label_matrix[agl[num_mol*i+j]]][label_matrix[agl[num_mol*i+k]]] = 1;
            matrix[label_matrix[agl[num_mol*i+k]]][label_matrix[agl[num_mol*i+j]]] = 1;
          }
//       TODO: analyze of topology
      iso = 0;
      p = 0;
      for (j=0; j<num_mol_agl[i]; j++)
        for (k=0; k<num_mol_agl[i]; k++)
          p += matrix[j][k];
      if (p == (2*num_mol_agl[i]-2))
      {
        type = 0;
        type_agl[0]++;
      }
      else
      {
        type = (p - (2*num_mol_agl[i]-2)) / 2;
        type_agl[1]++;
      }
      
//       printing class of aglomerate
      fprintf (f_out, "AGL=%i=%i=%i\n", num_mol_agl[i], type, iso);
      for (j=0; j<num_mol_agl[i]; j++)
      {
        fprintf (f_out, "%7i=", true_label_mol[agl[num_mol*i+j]]);
        for (k=0; k<num_mol_agl[i]; k++)
        {
          if (matrix[j][k] == 1)
            fprintf (f_out, "%i,", true_label_mol[agl[num_mol*i+k]]);
        }
        fprintf (f_out, "\n");
      }
      
//       free memory
      for (j=0; j<num_mol_agl[i]; j++)
        free (matrix[j]);
      free (matrix);
      free (label_matrix);
    }
  
  fprintf (f_out, "---------------------------------------------------\n");
  fclose (f_out);
  return 0;
}