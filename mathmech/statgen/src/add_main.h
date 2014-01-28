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
 * Header of statgen
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
 * error_checking (_system_info, input, max_depth, num_of_inter, output, type_inter);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param input           mask of trajectory files
 * @param max_depth       max depth for check cycles in graph analyze
 * @param num_of_inter    number of different interactions
 * @param output          output file name
 * @param type_inter      number of atoms for interactions
 * 
 * @return 11             - error in 'type_inter'
 * @return 12             - error in 'cell'
 * @return 13             - error in 'to' or 'from'
 * @return 14             - error in 'num_of_inter'
 * @return 15             - error in 'input'
 * @return 16             - error in 'output'
 * @return 19             - error in 'max_depth'
 * @return 0              - exit without errors
 */
int error_checking (const system_info _system_info, const char *input, const int max_depth, 
                    const int num_of_inter, const char *output, const int type_inter);


/**
 * @brief function that prints header in output file
 * @code
 * printing_head (output, log, quiet, input, _system_info, type_inter, label_atom, 
 *                num_of_inter, crit, max_depth);
 * @endcode
 * 
 * @param output          output file nams
 * @param log             status of log-mode
 * @param quiet           status of quiet-mode
 * @param input           mask of trajectory files
 * @param _system_info    system information structure
 * @param type_inter      number of atoms for interactions
 * @param label_atom      massive of atom types for interactions
 * @param num_of_inter    number of different interactions
 * @param crit            massive of criteria
 * @param max_depth       maximum depth for check cycles in graph analyze
 * 
 * @return 0              - exit without errors
 */
int printing_head (const char *output, const int log, const int quiet, 
                   const char *input, const system_info _system_info,
                   const int type_inter, const int *label_atom, 
                   const int num_of_inter, const float *crit, const int max_depth);


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
 * set_defaults (&_system_info, input, &log, &max_depth, &num_of_inter, output, 
 *               &type_inter, &quiet);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param max_depth       maximum depth for check cycles in graph analyze
 * @param num_of_inter    number of different interactions
 * @param output          output file name
 * @param type_inter      number of atoms for interactions
 * @param quiet           status of quiet-mode
 * 
 * @return 0              - exit without errors
 */
int set_defaults (system_info *_system_info, char *input, int *log, int *max_depth, 
                  int *num_of_inter, char *output, int *type_inter, int *quiet);


#endif /* ADD_MAIN_H */
