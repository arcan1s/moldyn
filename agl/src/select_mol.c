/* Library for select molecules in translations
 * 
 * Usage:
 * 
 */

#include <math.h>


int select_molecule (const int num_atoms, const int *label_mol, const int *true_label_mol, const float *coords, const int num_needed_mol, int *needed_mol)
{
  float r, ref[3], rmin;
  int i, j, k, *old_needed_mol;
  
  old_needed_mol = (int *) malloc (num_needed_mol * sizeof (int));
  if (old_needed_mol == NULL)
    return 1;
  
//   set first molecule
  ref_mol = old_needed_mol[0];
  needed_mol[0] = 0;
  k = 1;
  for (i=0; i<3; i++)
    ref[i] = coords[3*0+i];
  
  for (i=1; i<num_needed_mol; i++)
    for (j=0; j<8*num_atoms; j++)
      if (old_needed_mol[i] == true_label_mol[label_mol[j]])
      {
        if (j < num_atoms)
          cur_mol = 0;
        else
          cur_mol = ((j - num_atoms) % 7) + 1;
    //     for (j=0; j<3; j++)
    //       centr_coords[3*(8*label_mol[i]+cur_mol)+j] += coords[3*i+j];
      }
  
  for (i=1; i<num_needed_mol; i++)
    for (j=0; j<num_atoms; j++)
      if (old_needed_mol[i] == true_label_mol[label_mol[j]])
      {
        if (ref_mol != true_label_mol[label_mol[j]])
        {
          ref_i = j;
          rmin = sqrt (pow ((coords[3*j+0] - ref[0]), 2) + \
                 pow ((coords[3*j+1] - ref[1]), 2) + \
                 pow ((coords[3*j+2] - ref[2]), 2));
          ref_mol = true_label_mol[label_mol[j]];
        }
        else
        {
          
        }
      }
  
  free (old_needed_mol);
  
  return 0;
}
