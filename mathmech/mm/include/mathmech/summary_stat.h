/**
 * @file
 */

#ifndef SUMMARY_STAT_H
#define SUMMARY_STAT_H

#include <mathmech/var_types.h>


/**
 * @fn summary_statistic
 */
int summary_statistic (const char *filename, const system_info _system_info, 
                       const int max_depth, const int *type_agl, const int *stat_all);
/**
 * @brief function that prints summary statistic
 * @code
 * summary_statistic (filename, _system_info, max_depth, type_agl, stat_all);
 * @endcode
 * 
 * @param filename        output file name
 * @param _system_info    system information structure
 * @param num_mol         number of molecules
 * @param max_depth       maximum depth for check cycles in graph analyze
 * @param type_agl        massive of number of agglomerate types
 * @param stat_all        massive of summary statistic
 * 
 * @return 0              - exit without errors
 */


#endif /* SUMMARY_STAT_H */
