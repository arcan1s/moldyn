/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file radf_proc.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef RADF_PROC_H
#define RADF_PROC_H

#include <mathmech/var_types.h>


/**
 * @brief function that print result to output file
 * @code
 * print_result (output, matrix, mode, _system_info, _radf_info, radf);
 * @endcode
 * 
 * @param output          output file name
 * @param matrix          status of matrix-mode
 * @param mode            1 - if RDF, 2 - if RDF for center mass, 3 - if RADF
 * @param _system_info    system information structure
 * @param _radf_info      radf information structure
 * @param radf            not normed RADF
 * 
 * @return 0              - exit without errors
 */
int print_result (const char *output, const int matrix, const int mode, 
                  const system_info _system_info, const radf_info _radf_info,
                  const int *radf);


#endif /* RADF_PROC_H */
