/**
 * @file
 */

#include <stdio.h>

#include <mathmech/messages.h>


/**
 * @fn error_checking
 */
int error_checking (const const char *input, const char *output)
/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (input, output);
 * @endcode
 * 
 * @param aglinp          aglomerate file name
 * @param cell            massive of cell size
 * @param input           input file name
 * @param output          output file name
 * 
 * @return 11             - error in 'input'
 * @return 12             - error in 'output'
 * @return 0              - exit without errors
 */
{
  if (input[0] == '#')
    return 11;
  if (output[0] == '#')
    return 12;
  
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
int set_defaults (char *input, int *log, char *output, int *quiet)
/**
 * @brief function that sets default values of variables
 * @code
 * set_defaults (input, &log, output, &quiet);
 * @endcode
 * 
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param output          output file name
 * @param quiet           status of quiet-mode
 * 
 * @return 0              - exit without errors
 */
{
  input[0] = '#';
  *log = 0;
  output[0] = '#';
  *quiet = 0;
  
  return 0;
}