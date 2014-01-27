/**
 * @file
 */

#ifndef STAT_SORT_H
#define STAT_SORT_H

#include <mathmech/var_types.h>


/**
 * @fn proc_matrix
 */
int proc_matrix (const system_info _system_info, const int *connect, int *num_mol_agl, 
                 int *agl, int *stat, int *stat_all);
/**
 * @brief function that processes connectivity matrix
 * @code
 * proc_matrix (_system_info, connect_matrix, num_of_molecules_in_agglomerates, 
 *              agglomerates, statistic, summary_statistic);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param connect         connectivity graph for all molecules
 * @param num_mol_agl     massive of number of molecules in agglomerates
 * @param agl             massive of agglomerates
 * @param stat            massive of statistic
 * @param stat_all        massive of summary statistic
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */


#endif /* STAT_SORT_H */