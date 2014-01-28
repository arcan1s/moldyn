/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file summary_stat.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef SUMMARY_STAT_H
#define SUMMARY_STAT_H

#include <mathmech/var_types.h>


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
int summary_statistic (const char *filename, const system_info _system_info, 
                       const int max_depth, const int *type_agl, const int *stat_all);


#endif /* SUMMARY_STAT_H */
