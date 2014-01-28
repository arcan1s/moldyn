/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file add_main.h
 * Header of radf
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef ADD_MAIN_H
#define ADD_MAIN_H

#include <mathmech/var_types.h>


/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (input, num_needed_at, needed_at, output, _system_info);
 * @endcode
 * 
 * @param input           input file name
 * @param num_needed_at   number of needed atom types
 * @param needed_at       massive of number of needed atom types
 * @param output          output file name
 * @param _system_info    system information structure
 * 
 * @return 11             - error in 'cell'
 * @return 12             - error in 'input'
 * @return 13             - error in 'output'
 * @return 14             - error in 'from' or 'to'
 * @return 15             - error in 'num_needed_at'
 * @return 16             - error in 'needed_at'
 * @return 0              - exit without errors
 */
int error_checking (const char *input, const int num_needed_at, const int *needed_at, 
                    const char *output, const system_info _system_info);


/**
 * @brief function that prints message in log and stdout
 * @code
 * print_message (quiet, stdout, log, f_log, 0, str);
 * @endcode
 * 
 * @param quiet           status of quiet-mode
 * @param std_output      stdout
 * @param log             status of log-mode
 * @param f_log           log file
 * @param mode            number of message in "messages.c"
 * @param str             additional text in message
 * 
 * @return 0              - exit without errors
 */
int print_message (const int quiet, FILE *std_output, const int log, FILE *f_log, 
                   const int mode, const char *str);


/**
 * @brief function that prints header in output file
 * @code
 * printing_head (output, log, quiet, matrix, input, _system_info, mode, _radf_info, 
 *                needed_at);
 * @endcode
 * 
 * @param output          output file nams
 * @param log             status of log-mode
 * @param quiet           status of quiet-mode
 * @param matrix          status of matrix-mode
 * @param input           mask of trajectory files
 * @param _system_info    system information structure
 * @param mode            0 - if RDF, 1 - if RDF for center mass, 2 - if RADF
 * @param _radf_info      radf information structure
 * @param needed_at       massive of number of needed atom types
 * 
 * @return 0              - exit without errors
 */
int printing_head (const char *output, const int log, const int quiet, const int matrix, 
                   const char *input, const system_info _system_info, const int mode, 
                   const radf_info _radf_info, const int *needed_at);


/**
 * @brief function that sets default values of variables
 * @code
 * set_defaults (&_system_info, &_radf_info, input, &log, &matrix, output, &quiet);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param _radf_info      radf information structure
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param output          output file name
 * @param quiet           status of quiet-mode
 * 
 * @return 0              - exit without errors
 */
int set_defaults (system_info *_system_info, radf_info *_radf_info, char *input, 
                  int *log, int *matrix, char *output, int *quiet);


#endif /* ADD_MAIN_H */
