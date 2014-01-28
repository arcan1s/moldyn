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

#ifndef ENVIR_SEARCH_H
#define ENVIR_SEARCH_H

#include <mathmech/var_types.h>


/**
 * @fn search_envir
 */
int search_envir (const int num_of_mol, const system_info _system_info, const float *centr_coords, 
                  const double rad, int *needed_mol, int *num_needed_mol);
/**
 * @brief function that searchs environment
 * @code
 * search_envir (number_of_molecule, _system_info, centr_coords, rad, needed_mol, 
 *               &num_needed_mol);
 * @endcode
 * 
 * @param num_of_mol      number of molecule
 * @param _system_info    system information structure
 * @param centr_coords    massive of centered coordinates
 * @param rad             radius of environment sphere
 * @param needed_mol      massive of number of needed molecules
 * @param num_needed_mol  number of needed molecules
 * 
 * @return 0              - exit without errors
 */


#endif /* ENVIR_SEARCH_H */
