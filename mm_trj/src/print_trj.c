/**
 * @file
 */

#include <stdio.h>


/**
 * @fn printing_trj
 */
int printing_trj (const char *filename, const int atoms, const int num_types, const int *num_mol, 
                  const int *num_atoms, const char *ch_atom_types, const int *atom_types,
                  const float *coords)
/**
 * @brief function that prints trajectory snapshots
 * @code
 * printing_trj (filename, atoms, num_types, num_mol, num_atoms, ch_atom_types, 
 *               atom_types, coords);
 * @endcode
 * 
 * @param filename        output file name
 * @param atoms           number of atoms in system
 * @param num_types       number of molecule types
 * @param num_mol         massive of number of molecule of selected type
 * @param num_atoms       massive of number of atoms of selected molecule
 * @param ch_atom_types   massive of char atom types
 * @param atom_types      massive of atom types
 * @param coords          massive of coordinates
 * 
 * @return 0              - exit without errors
 */
{
  int cur_mol, cur_type[2], i, j, k, l;
  FILE *f_out;
  
/* cur_mol                number of current molecule
 * cur_type               number of current atom type
 * f_out                  output file
 */
  
  cur_mol = 1;
  f_out = fopen (filename, "w");
  fprintf (f_out, " %6i\n", atoms);
  
  i = 0;
  while (i < atoms)
  {
    cur_type[0] = 0;
    for (j=0; j<num_types; j++)
    {
      for (k=0; k<num_mol[j]; k++)
      {
        cur_type[1] = cur_type[0];
        for (l=0; l<num_atoms[j]; l++)
        {
          fprintf (f_out, "%5i  %c%c %12.6f%12.6f%12.6f    %2i %4i\n", i+1, 
ch_atom_types[2*cur_type[1]+0], ch_atom_types[2*cur_type[1]+1], coords[3*i+0], 
coords[3*i+1], coords[3*i+2], atom_types[cur_type[1]], cur_mol);
          cur_type[1]++;
          i++;
        }
        cur_mol++;
      }
      cur_type[0] += num_atoms[j];
    }
  }
  
  fclose (f_out);
  
  return 0;
}