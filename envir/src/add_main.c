/**
 * @file
 */

#include <stdio.h>

#include "messages.h"


/**
 * @fn error_checking
 */
int error_checking (const float *cell, const char *input, const char *output)
/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (cell, input, output);
 * @endcode
 * 
 * @param cell            massive of cell size
 * @param input           input file name
 * @param output          output file name
 * 
 * @return 11             - error in 'cell'
 * @return 12             - error in 'input'
 * @return 13             - error in 'output'
 * @return 0              - exit without errors
 */
{
  if ((cell[0] == 0.0) || (cell[1] == 0.0) || (cell[2] == 0.0))
    return 11;
  if (input[0] == '#')
    return 12;
  if (output[0] == '#')
    return 13;
  
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
int set_defaults (float *cell, char *input, int *log, int *num_of_mol, char *output, 
                  int *quiet, float *rad)
/**
 * @brief function that sets default values of variables
 * @code
 * set_defaults (cell, &from, input, &log, &max_depth, &num_of_inter, output, &to, 
 *               &type_inter, &quiet);
 * @endcode
 * 
 * @param cell            massive of cell size
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param num_of_mol      number of molecule
 * @param output          output file name
 * @param quiet           status of quiet-mode
 * @param rad             radius of environment sphere
 * 
 * @return 0              - exit without errors
 */
{
  int i;
  
  for (i=0; i<3; i++)
    cell[i] = 0.0;
  input[0] = '#';
  *log = 0;
  *num_of_mol = 1;
  output[0] = '#';
  *quiet = 0;
  *rad = 6.0;
  
  return 0;
}