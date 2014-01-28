/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file stat_select.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef STAT_SELECT_H
#define STAT_SELECT_H

#include <mathmech/var_types.h>


/**
 * @brief function that creates connectivity matrix
 * @code
 * create_matrix (_system_info, _atom_info, num_of_inter, crit, connect);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param _atom_info      atom information structure
 * @param num_of_inter    number of different interactions
 * @param crit            massive of criteria
 * @param connect         connectivity graph for all molecules
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */
int create_matrix (const system_info _system_info, const atom_info *_atom_info, 
                   const int num_of_inter, const float *crit, int *connect);


#endif /* STAT_SELECT_H */
