/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file read_gmx.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef READ_GMX_H
#define READ_GMX_H


/**
 * @brief funtion that translates coordinate
 * @code
 * translate_coords (coords[3*i+j], cell[j], trans);
 * @endcode
 * 
 * @param coords          coordinate
 * @param cell            cell size
 * @param trans           massive of translated coordinates
 * 
 * @return 0              - exit without errors
 */
int translate_coords (const float coords, const float cell, float *trans);


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
int rw_gmx (const char *input, const int step, const char *output, const int num_types, 
            const int *num_mol, const int *num_atoms, const char *ch_atom_types, 
            const int *atom_types, float *coords);


#endif /* READ_GMX_H */
