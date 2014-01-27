/**
 * @file
 */

#ifndef STAT_SELECT_H
#define STAT_SELECT_H

#include <mathmech/var_types.h>


/**
 * @fn create_matrix
 */
int create_matrix (const system_info _system_info, const atom_info *_atom_info, 
                   const int num_of_inter, const float *crit, int *connect);
/**
 * @brief function that creates connectivity matrix
 * @code
 * int create_matrix (_system_info, _atom_info, num_of_inter, crit, connect);
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


#endif /* STAT_SELECT_H */
