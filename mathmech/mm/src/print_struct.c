/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 */

#include <stdio.h>

#include <mathmech/print_struct.h>
#include <mathmech/var_types.h>


/**
 * @fn print_structure
 */
int print_structure (const char *output, const int num_needed_mol, const int *needed_mol, 
                     const system_info _system_info, const atom_info *_atom_info)
{
  int cur_atom, cur_mol, i, j;
  FILE *f_out;
  
/* cur_atom               current atom
 * cur_mol                current molecule
 * f_out                  output file
 */
  
  cur_atom = 1;
  f_out = fopen (output, "w");
  
  for (i=0; i<num_needed_mol; i++)
    for (j=0; j<8*_system_info.num_atoms; j++)
    {
      if (j < _system_info.num_atoms)
        cur_mol = 0;
      else
        cur_mol = ((j - _system_info.num_atoms) % 7) + 1;
      if (needed_mol[i] == (8*_atom_info[j].label_mol+cur_mol))
      {
        fprintf(f_out, "ATOM  %5i %c%c   MOL  %4i    %8.3f%8.3f%8.3f\n", cur_atom, 
                _atom_info[j].ch_type_atoms[0], _atom_info[j].ch_type_atoms[1], 
                i+1, _atom_info[j].coords[0], _atom_info[j].coords[1], _atom_info[j].coords[2]);
        cur_atom++;
      }
    }
  
  fclose (f_out);
  
  return 0;
}
