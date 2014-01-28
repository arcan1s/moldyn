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

#ifndef ATOM_TYPES_H
#define ATOM_TYPES_H


/**
 * @fn reading_atoms
 */
int reading_atoms (const char *input_at, int *num_types, int *num_mol, int *num_atoms, 
                   char *ch_atom_types, int *atom_types, const int total_types);
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


#endif /* ATOM_TYPES_H */
