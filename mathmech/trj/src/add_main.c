/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 */

#include <stdio.h>

#include "add_main.h"
#include <mathmech/messages.h>


/**
 * @fn error_checking
 */
int error_checking (const char *input, const char *input_at, const char *output, 
                    const int step, const int type)
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
