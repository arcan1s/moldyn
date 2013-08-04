/**
 * @file
 */

#include <stdio.h>


/**
 * @fn reading_atoms
 */
int reading_atoms (const char *input_at, int *num_types, int *num_mol, int *num_atoms, 
                   char *ch_atom_types, int *atom_types, const int total_types)
/**
 * @brief function that reads atom types from input file
 * @code
 * reading_atoms (input_at, &num_types, num_mol, num_atoms, ch_atom_types, atom_types, 
 *                total_types);
 * @endcode
 * 
 * @param input_at        input file name with atom types
 * @param num_types       number of molecule types
 * @param num_mol         massive of number of molecules of selected type
 * @param num_atoms       massive of number of atoms of selected molecule
 * @param ch_atom_types   massive of char atom types
 * @param atom_types      massive of atom types
 * @param total_types     number of different atom types
 * 
 * @return 1              - error in opening file
 * @return 2              - error in file format
 * @return 3              - memory error
 * @return 0              - exit without errors
 */
{
  char at_symb[2], tmp_str[256];
  int at_ndx, i, j, total_atoms;
  FILE *f_inp;
  
/* at_*                    temp variables
 * total_atoms             total atom types
 * f_inp                   input file
 */
  
  f_inp = fopen (input_at, "r");
  if (f_inp == NULL)
    return 1;
  
  fgets (tmp_str, 256, f_inp);
  sscanf (tmp_str, "NUMTYPES=%i", num_types);
  if (*num_types == 0)
    return 2;
  else if (*num_types > total_types)
    return 3;
  
  total_atoms = 0;
  for (i=0; i<*num_types; i++)
  {
// read constants
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "NUMMOL=%i", &num_mol[i]);
    if (num_mol[i] == 0)
      return 2;
    fgets (tmp_str, 256, f_inp);
    sscanf (tmp_str, "NUMAT=%i", &num_atoms[i]);
    if (num_atoms[i] == 0)
      return 2;
    else if ((total_atoms + num_atoms[i]) > total_types)
      return 2;
    
// read atoms
    for (j=0; j<num_atoms[i]; j++)
    {
      fgets (tmp_str, 256, f_inp);
      at_ndx = -1;
      sscanf (tmp_str, "%2s=%i", at_symb, &at_ndx);
      if (at_ndx == -1)
        return 2;
      ch_atom_types[2*total_atoms+2*j+0] = at_symb[0];
      ch_atom_types[2*total_atoms+2*j+1] = at_symb[1];
      atom_types[total_atoms+j] = at_ndx;
    }
    total_atoms += num_atoms[i];
  }
  
  fclose (f_inp);
  
  return 0;
}