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

#ifndef STAT_PRINT_H
#define STAT_PRINT_H

#include <mathmech/var_types.h>


/**
 * @fn printing_agl
 */
int printing_agl (const char *input, const char *output, const int *connect, 
                  const system_info _system_info, const int *true_label_mol, 
                  const int *num_mol_agl, const int *agl, const int *stat, 
                  const int max_depth, int *type_agl);
/**
 * @brief function that prints agglomerates to output file
 * @code
 * printing_agl (input, output, connect, _system_info, true_label_mol, num_mol_agl, 
 *               agl, stat, max_depth, type_agl);
 * @endcode
 * 
 * @param input           input file name
 * @param output          output file name
 * @param connect         connectivity graph for all molecules
 * @param _system_info    system information structure
 * @param true_label_mol  massive of true numbers of molecule for atoms
 * @param num_mol_agl     massive of number of molecules in agglomerates
 * @param agl             massive of agglomerates
 * @param stat            massive of statistic
 * @param max_depth       maximum depth for check cycles in graph analyze
 * @param type_agl        massive of number of agglomerate types
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */


#endif /* STAT_PRINT_H */
