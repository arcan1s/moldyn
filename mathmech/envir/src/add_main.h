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
 * Header of envir
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
 * error_checking (_system_info, input, output);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param input           input file name
 * @param output          output file name
 * 
 * @return 11             - error in 'cell'
 * @return 12             - error in 'input'
 * @return 13             - error in 'output'
 * @return 0              - exit without errors
 */
int error_checking (const system_info _system_info, const char *input, 
                    const char *output);


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
 * @brief function that sets default values of variables
 * @code
 * set_defaults (&_system_info, &from, input, &log, &max_depth, &num_of_inter, output, &to, 
 *               &type_inter, &quiet);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param num_of_mol      number of molecule
 * @param output          output file name
 * @param quiet           status of quiet-mode
 * @param rad             radius of environment sphere
 * 
 * @return 0              - exit without errors
 */
int set_defaults (system_info *_system_info, char *input, int *log, int *num_of_mol, 
                  char *output, int *quiet, float *rad);


#endif /* ADD_MAIN_H */
