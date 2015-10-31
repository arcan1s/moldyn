/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file read_puma.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <stdio.h>

#include <mathmech/print_trj.h>
#include <mathmech/read_puma.h>


/**
 * @fn rw_puma
 */
int rw_puma (const char *input, const int step, const char *output, const int num_types, 
             const int *num_mol, const int *num_atoms, const char *ch_atom_types, 
             const int *atom_types, float *coords)
{
  char filename[256], tmp_str[256];
  float cell[3];
  int atoms, i, j, k, l, m, n;
  FILE *f_inp;
  
/* filename               output file name
 * cell                   cell size
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
    sscanf (tmp_str, "%s%s%i%s", tmp_str, tmp_str, &atoms, tmp_str);
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "%f%f%f", &cell[0], &cell[1], &cell[2]);
// coordinates
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
                  atom_types, coords, cell);
  }
  
  fclose (f_inp);
  
  return 0;
}
