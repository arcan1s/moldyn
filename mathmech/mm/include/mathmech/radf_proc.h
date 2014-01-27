/**
 * @file
 */

#ifndef RADF_PROC_H
#define RADF_PROC_H

#include <mathmech/var_types.h>


/**
 * @fn print_result
 */
int print_result (const char *output, const int matrix, const int mode, 
                  const system_info _system_info, const radf_info _radf_info,
                  const int *radf);
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


#endif /* RADF_PROC_H */
