/**
 * @file
 */

#include <math.h>
#include <stdlib.h>


/**
 * @fn create_matrix
 */
int create_matrix (const int num_mol, const int num_atoms, const int *label_mol, 
                   const int *type_atoms, const float *coords, const int num_of_inter, 
                   const float *crit, int *connect)
/**
 * @brief function that creates connectivity matrix
 * @code
 * create_matrix (number_of_molecules, number_of_atoms, label_molecule, type_atoms, 
 *                coords, number_of_interactions, criteria, connect_matrix);
 * @endcode
 * 
 * @param num_mol         number of molecules
 * @param num_atoms       number of atoms
 * @param label_mol       massive of numbers of molecule for atoms
 * @param type_atoms      massive of atom types
 * @param coords          massive of coordinates
 * @param num_of_inter    number of different interactions
 * @param crit            massive of criteria
 * @param connect         connectivity graph for all molecules
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */
{
  float r;
  int cur_num_inter, i, j, k, l, num_inter, ***label_inter;
  
/* r                      radius
 * cur_num_inter          current number of true interactions
 * num_inter              needed number of true interactions
 * label_inter            temporary massive of true interactions
 */
  
/// <b>Work blocks</b>
  
  label_inter = (int ***) malloc (num_mol * sizeof (int **));
  for (i=0; i<num_mol; i++)
  {
    label_inter[i] = (int **) malloc (num_mol * sizeof (int *));
    for (j=0; j<num_mol; j++)
    {
      label_inter[i][j] = (int *) malloc (16 * sizeof (int));
      for (k=0; k<16; k++)
        label_inter[i][j][k] = 0;
    }
  }
  if (label_inter == NULL)
    return 1;
  
/// <pre>   creating initial connectivity matrix </pre>
  for (i=0; i<num_atoms*8; i++)
    for (j=i+1; j<num_atoms*8; j++)
// if atoms from different molecules
      if (label_mol[i] != label_mol[j])
      {
        r = sqrt (pow ((coords[3*i+0]-coords[3*j+0]), 2) + 
          pow ((coords[3*i+1]-coords[3*j+1]), 2) + 
          pow ((coords[3*i+2]-coords[3*j+2]), 2));
        for (k=0; k<num_of_inter; k++)
          if (crit[16*k+4*type_atoms[i]+type_atoms[j]] != 0.0)
            if (r < crit[16*k+4*type_atoms[i]+type_atoms[j]])
            {
              label_inter[label_mol[i]][label_mol[j]][4*type_atoms[i]+type_atoms[j]] = 1;
              label_inter[label_mol[i]][label_mol[j]][4*type_atoms[j]+type_atoms[i]] = 1;
              label_inter[label_mol[j]][label_mol[i]][4*type_atoms[i]+type_atoms[j]] = 1;
              label_inter[label_mol[j]][label_mol[i]][4*type_atoms[j]+type_atoms[i]] = 1;
            }
      }
  
  for (i=0; i<num_mol; i++)
    for (j=0; j<num_mol; j++)
      connect[i*num_mol+j] = 0;
  
/// <pre>   processing of initial connectivity matrix </pre>
  for (k=0; k<num_of_inter; k++)
  {
// determination of the number of interactions
    num_inter = 0;
    for (l=0; l<16; l++)
      if (crit[16*k+l] != 0.0)
        num_inter++;
    
    for (i=0; i<num_mol; i++)
      for (j=i+1; j<num_mol; j++)
      {
        cur_num_inter = 0;
        for (l=0; l<16; l++)
          cur_num_inter += label_inter[i][j][l];
        
        if (cur_num_inter == num_inter)
        {
          connect[i*num_mol+j] = 1;
          connect[j*num_mol+i] = 1;
        }
      }
  }
  
/// <pre>   free memory</pre>
  for (i=0; i<num_mol; i++)
  {
    for (j=0; j<num_mol; j++)
      free (label_inter[i][j]);
    free (label_inter[i]);
  }
  free (label_inter);
  
  return 0;
}