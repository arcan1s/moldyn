/**
 * @file
 */

#include <stdio.h>

#include "add_main.h"
#include <mathmech/messages.h>
#include <mathmech/var_types.h>


/**
 * @fn error_checking
 */
int error_checking (const char *aglinp, const system_info _system_info, const char *input, 
                    const char *output)
{
  if ((_system_info.cell[0] == 0.0) || (_system_info.cell[1] == 0.0) || (_system_info.cell[2] == 0.0))
    return 11;
  if (input[0] == '#')
    return 12;
  if (output[0] == '#')
    return 13;
  if (aglinp[0] == '#')
    return 14;
  
  return 0;
}


/**
 * @fn print_message
 */
int print_message (const int quiet, FILE *std_output, const int log, FILE *f_log, 
                   const int mode, const char *str)
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
int set_defaults (char *aglinp, system_info *_system_info, char *input, int *log, 
                  char *output, int *quiet)
{
  int i;
  
  aglinp[0] = '#';
  for (i=0; i<3; i++)
    (*_system_info).cell[i] = 0.0;
  input[0] = '#';
  *log = 0;
  output[0] = '#';
  *quiet = 0;
  
  return 0;
}
