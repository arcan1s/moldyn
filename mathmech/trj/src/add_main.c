/**
 * @file
 */

#include <stdio.h>

#include <mathmech/messages.h>


/**
 * @fn error_checking
 */
int error_checking (const char *input, const char *input_at, const char *output, 
                    const int step, const int type)
/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (cell, from, input, num_needed_at, needed_at, output, to);
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
{
  if (input_at[0] == '#')
    return 11;
  if (input[0] == '#')
    return 12;
  if (output[0] == '#')
    return 13;
  if (step == 0)
    return 14;
  if (type == -1)
    return 15;
  
  return 0;
}


/**
 * @fn print_message
 */
int print_message (const int quiet, FILE *std_output, const int log, FILE *f_log, 
                   const int mode, const char *str)
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
{
  if ((quiet != 1) && (std_output != stderr))
    message (0, mode, str, std_output);
  if (log == 1)
    message (1, mode, str, f_log);
  
  return 0;
}


/**
 * @fn set_defaults
 */
int set_defaults (char *input, char *input_at, int *log, char *output, int *step, 
                  int *total_types, int *type, int *quiet)
/**
 * @brief function that sets default values of variables
 * @code
 * set_defaults (input, input_at, &log, output, &step, &type, &quiet);
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
{
  input[0] = '#';
  input_at[0] = '#';
  *log = 0;
  output[0] = '#';
  *step = 0;
  *total_types = 1024;
  *type = -1;
  *quiet = 0;
  
  return 0;
}
