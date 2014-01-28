/**
 * @file
 */

#include <stdio.h>

#include "add_main.h"
#include <version.h>
#include <mathmech/messages.h>
#include <mathmech/var_types.h>


/**
 * @fn error_checking
 */
int error_checking (const char *input, const int num_needed_at, const int *needed_at, 
                    const char *output, const system_info _system_info)
{
  if ((_system_info.cell[0] == 0.0) || (_system_info.cell[1] == 0.0) || (_system_info.cell[2] == 0.0))
    return 11;
  if (input[0] == '#')
    return 12;
  if (output[0] == '#')
    return 13;
  if ((_system_info.from == -1) || (_system_info.to == -1))
    return 14;
  if ((num_needed_at != 2) && (num_needed_at != 6))
    return 15;
  if (num_needed_at == 6)
    if ((needed_at[0] == needed_at[1]) || 
       (needed_at[0] == needed_at[2]) || 
       (needed_at[1] == needed_at[2]) || 
       (needed_at[3] == needed_at[4]) || 
       (needed_at[3] == needed_at[5]) || 
       (needed_at[4] == needed_at[5]))
      return 16;
  
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
 * @fn printing_head
 */
int printing_head (const char *output, const int log, const int quiet, const int matrix, 
                   const char *input, const system_info _system_info, const int mode, 
                   const radf_info _radf_info, const int *needed_at)
{
  FILE *f_out;
  
  f_out = fopen (output, "w");
  fprintf (f_out, "radf ::: V.%s\n\n", PROJ_VERSION);
  fprintf (f_out, "CONFIGURATION\n");
  
  fprintf (f_out, "LOG=%i\nQUIET=%i\nMATRIX=%i\n", log, quiet, matrix);
  fprintf (f_out, "MASK=%s\nFIRST=%i\nLAST=%i\n", input, _system_info.from, 
           _system_info.to);
  fprintf (f_out, "CELL=%.4f,%.4f,%.4f\n", _system_info.cell[0], _system_info.cell[1], 
           _system_info.cell[2]);
  fprintf (f_out, "MODE=%i\n", mode);
  fprintf (f_out, "R_MIN=%.3f\nR_MAX=%.3f\nR_STEP=%.3f\n", _radf_info.r_min, 
           _radf_info.r_max, _radf_info.r_step);
  switch (mode)
  {
    case 0:
      fprintf (f_out, "ATOM=%i-%i\n", needed_at[0], needed_at[1]);
      break;
    case 1:
      fprintf (f_out, "ATOM=%i,%i,%i-%i,%i,%i\n", needed_at[0], needed_at[1], 
               needed_at[2], needed_at[3], needed_at[4], needed_at[5]);
      break;
    case 2:
      fprintf (f_out, "ANG_MIN=%.2f\nANG_MAX=%.2f\nANG_STEP=%.2f\n\
ATOM=%i,%i,%i-%i,%i,%i\n", _radf_info.ang_min, _radf_info.ang_max, _radf_info.ang_step, 
needed_at[0], needed_at[1], needed_at[2], needed_at[3], needed_at[4], needed_at[5]);
      break;
  }
  
  fprintf (f_out, "END\n\n");
  fclose (f_out);
  
  return 0;
}


/**
 * @fn set_defaults
 */
int set_defaults (system_info *_system_info, radf_info *_radf_info, char *input, 
                  int *log, int *matrix, char *output, int *quiet)
{
  int i;
  
  (*_radf_info).ang_max = 90.0;
  (*_radf_info).ang_min = 0.0;
  (*_radf_info).ang_step = 0.0;
  for (i=0; i<3; i++)
    (*_system_info).cell[i] = 0.0;
  (*_system_info).from = -1;
  input[0] = '#';
  *log = 0;
  *matrix = 0;
  (*_radf_info).r_max = 15.0;
  (*_radf_info).r_min = 2.0;
  (*_radf_info).r_step = 0.2;
  output[0] = '#';
  (*_system_info).to = -1;
  *quiet = 0;
  
  return 0;
}
