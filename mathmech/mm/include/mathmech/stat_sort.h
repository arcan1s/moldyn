/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file stat_sort.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef STAT_SORT_H
#define STAT_SORT_H

#include <mathmech/var_types.h>


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
int proc_matrix (const system_info _system_info, const int *connect, int *num_mol_agl, 
                 int *agl, int *stat, int *stat_all);


#endif /* STAT_SORT_H */
