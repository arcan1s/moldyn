/**
 * @file
 */

#ifndef ADD_MAIN_H
#define ADD_MAIN_H

#include <mathmech/var_types.h>


/**
 * @fn error_checking
 */
int error_checking (const system_info _system_info, const char *input, 
                    const char *output);
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


/**
 * @fn print_message
 */
int print_message (const int quiet, FILE *std_output, const int log, FILE *f_log, 
                   const int mode, const char *str);
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


/**
 * @fn set_defaults
 */
int set_defaults (system_info *_system_info, char *input, int *log, int *num_of_mol, 
                  char *output, int *quiet, float *rad);
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


#endif /* ADD_MAIN_H */
