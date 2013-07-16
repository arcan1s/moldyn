/* Library for creating connectivity matrix
 * 
 * Usage:
 *          create_matrix (number_of_molecules, number_of_atoms, label_molecule,
 *         type_atoms, coords, number_of_interactions, criteria, connect_matrix)
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


float radii (const float *a, const float *b)
{
  return sqrt (pow((a[0]-b[0]), 2) + pow((a[1]-b[1]), 2) + pow((a[2]-b[2]), 2));
}


int create_matrix (int num_mol, int num_atoms, const int *label_mol, 
                   const int *type_atoms, const float *coords, int num_of_inter, 
                   const float *crit, int *connect, int *num_bonds)
{
  float x[2][3];
  int cur_num_inter, i, j, k, l, num_inter, ***label_inter;
  
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
  
//   creating initial connectivity matrix
  for (i=0; i<num_atoms*8; i++)
    for (j=i+1; j<num_atoms*8; j++)
//       if atoms from different molecules
      if (label_mol[i] != label_mol[j])
      {
        for (k=0; k<3; k++)
        {
          x[0][k] = coords[3*i+k];
          x[1][k] = coords[3*j+k];
        }
        for (k=0; k<num_of_inter; k++)
          if (crit[16*k+4*type_atoms[i]+type_atoms[j]] != 0.0)
            if (radii (x[0], x[1]) <= crit[16*k+4*type_atoms[i]+type_atoms[j]])
            {
              label_inter[label_mol[i]][label_mol[j]][4*type_atoms[i]+type_atoms[j]] = 1;
              label_inter[label_mol[j]][label_mol[i]][4*type_atoms[i]+type_atoms[j]] = 1;
            }
      }
  
  for (i=0; i<num_mol; i++)
  {
    num_bonds[i] = 0;
    for (j=0; j<num_mol; j++)
      connect[i*num_mol+j] = 0;
  }
  
//   processing of initial connectivity matrix
  for (k=0; k<num_of_inter; k++)
  {
//     determination of the number of interactions
    num_inter = 0;
    for (l=0; l<16; l++)
      if (crit[16*k+l] != 0.0)
        num_inter++;
    
    for (i=0; i<num_mol; i++)
      for (j=0; j<num_mol; j++)
      {
        cur_num_inter = 0;
        for (l=0; l<16; l++)
          cur_num_inter += label_inter[i][j][l];
        
        if (cur_num_inter == num_inter)
        {
          connect[i*num_mol+j] = 1;
          connect[j*num_mol+i] = 1;
          num_bonds[i]++;
          num_bonds[j]++;
        }
      }
  }
  
//   free memory
  for (i=0; i<num_mol; i++)
  {
    for (j=0; j<num_mol; j++)
      free (label_inter[i][j]);
    free (label_inter[i]);
  }
  free (label_inter);
  
  return 0;
}


int main (int argc, char *argv[])
{
  return 0;
}