/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file read_gmx.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <math.h>
#include <stdio.h>

#include <mathmech/print_trj.h>
#include <mathmech/read_gmx.h>


/**
 * @fn translate_coords
 */
int translate_coords (const float coords, const float cell, float *trans)
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
                  atom_types, coords, cell);
  }
  
  fclose (f_inp);
  
  return 0;
}
