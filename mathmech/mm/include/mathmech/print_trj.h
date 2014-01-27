/**
 * @file
 */

#ifndef PRINT_TRJ_H
#define PRINT_TRJ_H


/**
 * @fn printing_trj
 */
int printing_trj (const char *filename, const int atoms, const int num_types, const int *num_mol, 
                  const int *num_atoms, const char *ch_atom_types, const int *atom_types,
                  const float *coords);
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


#endif /* PRINT_TRJ_H */
