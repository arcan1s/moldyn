/**
 * @file
 */

#include <stdio.h>

#include "print_trj.h"


/**
 * @fn rw_puma
 */
int rw_puma (const char *input, const int step, const char *output, const int num_types, 
             const int *num_mol, const int *num_atoms, const char *ch_atom_types, 
             const int *atom_types, float *coords)
/**
 * @brief function that read PUMA trajectory file and write to output
 * @code
 * rw_puma (input, step, output, num_types, num_mol, num_atoms, ch_atom_types, 
 *          atom_types, coords);
 * @endcode
 * 
 * @param input           input file name
 * @param step            number of trajectory steps
 * @param output          mask of output files
 * @param num_types       number of molecule types
 * @param num_mol         massive of number of molecule of selected type
 * @param num_atoms       massive of number of atoms of selected molecule
 * @param ch_atom_types   massive of char atom types
 * @param atom_types      massive of atom types
 * @param coords          massive of coordinates
 * 
 * @return 1              - file does not exist
 * @return 0              - exit without errors
 */
{
  char filename[256], tmp_str[256];
  float cell[3];
  int atoms, i, j, k, l, m, n;
  FILE *f_inp;
  
  f_inp = fopen (input, "r");
  if (f_inp == NULL)
    return 1;
  
  for (i=0; i<step; i++)
  {
// initial variables
    sprintf (filename, "%s.%03i", output, i+1);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "%s%s%i%s", tmp_str, tmp_str, &atoms, tmp_str);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "%f%f%f", &cell[0], &cell[1], &cell[2]);

    for (j=0; j<atoms; j++)
    {
      fgets (tmp_str, 256, f_inp);
      sscanf (tmp_str, "%f%f%f", &coords[3*j+0], &coords[3*j+1], &coords[3*j+2]);
    }
    fgets (tmp_str, 256, f_inp);

// processing coordinates
    j = 0;
    while (j < atoms)
      for (k=0; k<num_types; k++)
        for (l=0; l<num_mol[k]; l++)
          {
            for (m=0; m<3; m++)
            {
              while (coords[3*j+m] > cell[m]/2)
                for (n=j; n<j+num_atoms[k]; n++)
                  coords[3*n+m] -= cell[m];
              while (coords[3*j+m] < -cell[m]/2)
                for (n=j; n<j+num_atoms[k]; n++)
                  coords[3*n+m] += cell[m];
            }
            j += num_atoms[k];
          }
// write to output
    printing_trj (filename, atoms, num_types, num_mol, num_atoms, ch_atom_types, 
                  atom_types, coords);
  }
  
  fclose (f_inp);
  
  return 0;
}