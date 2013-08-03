/**
 * @file
 */

#include <stdio.h>


/**
 * @fn print_structure
 */
int print_structure (const char *output, const int num_needed_mol, const int *needed_mol, 
                     const int num_atoms, const int *label_mol, const char *ch_type_atoms, 
                     const float *coords)
/**
 * @brief function that prints structure to pdb file
 * @code
 * print_structure (output, num_needed_mol, needed_mol, num_atoms, label_mol, 
 *                  char_type_atoms, coords);
 * @endcode
 * 
 * @param output          output file name
 * @param num_needed_mol  number of needed molecules
 * @param needed_mol      massive of number of needed molecules
 * @param num_atoms       number of atoms
 * @param label_mol       massive of numbers of molecule for atoms
 * @param ch_type_atoms   massive of char atom types
 * @param coords          massive of coordinates
 * 
 * @return 0              - exit without errors
 */
{
  int cur_atom, cur_atom_num, cur_mol, i, j;
  FILE *f_out;
  
/* cur_atom               current atom
 * cur_atom_num           true atom number
 * cur_mol                current molecule
 * f_out                  output file
 */
  
  cur_atom = 1;
  f_out = fopen (output, "w");
  
  for (i=0; i<num_needed_mol; i++)
    for (j=0; j<8*num_atoms; j++)
    {
      if (j < num_atoms)
      {
        cur_mol = 0;
        cur_atom_num = j;
      }
      else
      {
        cur_mol = ((j - num_atoms) % 7) + 1;
        cur_atom_num = (j - num_atoms) / 7;
      }
      if (needed_mol[i] == (8*label_mol[j]+cur_mol))
      {
        fprintf(f_out, "ATOM  %5i %c%c   MOL  %4i    %8.3f%8.3f%8.3f\n", cur_atom, 
                ch_type_atoms[2*cur_atom_num+0], ch_type_atoms[2*cur_atom_num+1], 
                i+1, coords[3*j+0], coords[3*j+1], coords[3*j+2]);
        cur_atom++;
      }
    }
  
  fclose (f_out);
  
  return 0;
}