/**
 * @file
 */

#include <math.h>
#include <stdio.h>

#include "print_trj.h"


/**
 * @fn translate_coords
 */
int translate_coords (const float coords, const float cell, float *trans)
/**
 * @brief funtion that translates coordinate
 * @code
 * 
 * @endcode
 * 
 * @param coords          coordinate
 * @param cell            cell size
 * @param trans           massive of translated coordinates
 * 
 * @return 0              - exit without errors
 */
{
    trans[0] = coords;
    trans[1] = coords - cell;
    trans[2] = coords + cell;
   
  return 0;
}


/**
 * @fn rw_gmx
 */
int rw_gmx (const char *input, const int step, const char *output, const int num_types, 
            const int *num_mol, const int *num_atoms, const char *ch_atom_types, 
            const int *atom_types, float *coords)
/**
 * @brief function that read GROMACS trajectory file and write to output
 * @code
 * rw_gmx (input, step, output, num_types, num_mol, num_atoms, ch_atom_types, 
 *         atom_types, coords);
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
  float cell[3], trans[3], r_min;
  int atoms, i, j, k, l, m, n;
  FILE *f_inp;
  
/* filename               output file name
 * cell                   cell size
 * trans                  translated coordinates
 * r_min                  minimal radius
 * atom                   number of atoms
 * f_inp                  input file
 */
  
  f_inp = fopen (input, "r");
  if (f_inp == NULL)
    return 1;
  
  for (i=0; i<step; i++)
  {
// initial variables
    sprintf (filename, "%s.%03i", output, i+1);
    fgets (tmp_str, 256, f_inp);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "   natoms=%i%s", &atoms, tmp_str);
    fgets (tmp_str, 256, f_inp);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "      box[    0]={%f%s", &cell[0], tmp_str);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "      box[    1]={%f,%f%s", &cell[1], &cell[1], tmp_str);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "      box[    2]={%f,%f,%f%s", &cell[2], &cell[2], &cell[2], tmp_str);
    fgets (tmp_str, 256, f_inp);
    for (j=0; j<3; j++)
      cell[j] = 10 * cell[j];
// coordinates
    for (j=0; j<atoms; j++)
    {
      fgets (tmp_str, 256, f_inp);
      sscanf (tmp_str, "      x[%i]={%f,%f,%f%s", &k, &coords[3*j+0], &coords[3*j+1], 
              &coords[3*j+2], tmp_str);
      for (k=0; k<3; k++)
        coords[3*j+k] = 10 * coords[3*j+k];
    }
// velocities
    fgets (tmp_str, 256, f_inp);
    for (j=0; j<atoms; j++)
      fgets (tmp_str, 256, f_inp);
    
// processing coordinates
    j = 0;
    while (j < atoms)
      for (k=0; k<num_types; k++)
        for (l=0; l<num_mol[k]; l++)
        {
          for (m=1; m<num_atoms[k]; m++)
            for (n=0; n<3; n++)
            {
              r_min = fabs (coords[3*(j+m)+n] - coords[3*j+n]);
              translate_coords (coords[3*(j+m)+n], cell[n], trans);
              if (fabs (trans[1] - coords[3*j+n]) < r_min)
                coords[3*(j+m)+n] = trans[1];
              if (fabs (trans[2] - coords[3*j+n]) < r_min)
                coords[3*(j+m)+n] = trans[2];
            }
          j += num_atoms[k];
        }
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