/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file add_main.c
 * Header of trj
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef ADD_MAIN_H
#define ADD_MAIN_H


/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (input, input_at, output, step, type);
 * @endcode
 * 
 * @param input           input file name
 * @param input_at        input file name with atom types
 * @param output          output file name
 * @param step            number of trajectory steps
 * @param type            type of trajectory
 * 
 * @return 11             - error in 'input_at'
 * @return 12             - error in 'input'
 * @return 13             - error in 'output'
 * @return 14             - error in 'step'
 * @return 15             - error in 'type'
 * @return 0              - exit without errors
 */
int error_checking (const char *input, const char *input_at, const char *output, 
                    const int step, const int type);


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
 * set_defaults (input, input_at, &log, output, &step, &total_types, &type, &quiet);
 * @endcode
 * 
 * @param input           input file name
 * @param input_at        input file name with atom types
 * @param log             status of log-mode
 * @param output          output file name
 * @param step            number of trajectory steps
 * @param total_types     number of different atom types
 * @param type            type of trajectory
 * @param quiet           status of quiet-mode
 * 
 * @return 0              - exit without errors
 */
int set_defaults (char *input, char *input_at, int *log, char *output, int *step, 
                  int *total_types, int *type, int *quiet);


#endif /* ADD_MAIN_H */
