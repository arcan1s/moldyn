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

#ifndef SELECT_MOL_H
#define SELECT_MOL_H


/**
 * @fn select_molecule
 */
int select_molecule (const float *centr_coords, const int num_needed_mol, int *needed_mol);
/**
 * @brief function that selects molecules from array of translated molecules
 * @code
 * select_molecule (centr_coords, num_needed_mol, needed_mol);
 * @endcode
 * 
 * @param centr_coords    massive of centered coordinates
 * @param num_needed_mol  number of needed molecules
 * @param needed_mol      massive of number of needed molecules
 * 
 * @return 0              - exit without errors
 */


#endif /* SELECT_MOL_H */
