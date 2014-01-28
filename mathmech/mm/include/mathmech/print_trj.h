/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file print_trj.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef PRINT_TRJ_H
#define PRINT_TRJ_H


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
int printing_trj (const char *filename, const int atoms, const int num_types, const int *num_mol, 
                  const int *num_atoms, const char *ch_atom_types, const int *atom_types,
                  const float *coords);


#endif /* PRINT_TRJ_H */
