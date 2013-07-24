/* Additional library for main.c (envir)
 */

#include <stdio.h>

// #include "messages.h"


int error_checking (const float *cell, const char *input, const char *output)
{
  if ((cell[0] == 0.0) || (cell[1] == 0.0) || (cell[2] == 0.0))
    return 11;
  if (input[0] == '#')
    return 12;
  if (output[0] == '#')
    return 13;
  
  return 0;
}


int print_message (const int quiet, FILE *std_output, const int log, FILE *f_log, 
                   const int mode, const char *str)
{
  if ((quiet != 1) && (std_output != stderr))
    message (0, mode, str, std_output);
  if (log == 1)
    message (1, mode, str, f_log);
  
  return 0;
}


int set_defaults (float *cell, char *input, int *log, int *num_of_mol, char *output, 
                  int *quiet, float *rad)
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