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
int error_checking (const system_info _system_info, const char *input, const int max_depth, 
                    const int num_of_inter, const char *output, const int type_inter)
{
  if ((type_inter == 0) || (type_inter > 4))
    return 11;
  if ((_system_info.cell[0] == 0.0) || (_system_info.cell[1] == 0.0) || (_system_info.cell[2] == 0.0))
    return 12;
  if ((_system_info.to == -1) || (_system_info.from == -1))
    return 13;
  if (num_of_inter == 0)
    return 14;
  if (input[0] == '#')
    return 15;
  if (output[0] == '#')
    return 16;
  if ((max_depth < 3) && (max_depth != 0))
    return 19;
  
  return 0;
}


/**
 * @fn printing_head
 */
int printing_head (const char *output, const int log, const int quiet, 
                   const char *input, const system_info _system_info,
                   const int type_inter, const int *label_atom, 
                   const int num_of_inter, const float *crit, const int max_depth)
{
  int i, j;
  FILE *f_out;
  
  f_out = fopen (output, "w");
  fprintf (f_out, "statgen ::: V.%s\n\n", PROJ_VERSION);
  fprintf (f_out, "CONFIGURATION\n");
  
  fprintf (f_out, "LOG=%i\nQUIET=%i\n", log, quiet);
  fprintf (f_out, "MASK=%s\nFIRST=%i\nLAST=%i\n", input, _system_info.from, _system_info.to);
  fprintf (f_out, "CELL=%.4f,%.4f,%.4f\n", _system_info.cell[0], _system_info.cell[1], 
           _system_info.cell[2]);
  fprintf (f_out, "ATOMS=%i", label_atom[0]);
  for (i=1; i<type_inter; i++)
    fprintf (f_out, ",%i", label_atom[i]);
  fprintf (f_out, "\n");
  for (i=0; i<num_of_inter; i++)
  {
    fprintf (f_out, "INTERACTION=");
    for (j=0; j<16; j++)
      if ((crit[16*i+j] != 0.0) && 
        ((j != 4) && (j != 8) && (j != 9) && (j != 12) && (j != 13) && (j != 14)))
        fprintf (f_out, "%i-%i:%4.2f,", j/4, j%4, crit[16*i+j]);
    fprintf (f_out, "\n");
  }
  fprintf (f_out, "ISOMORPHISM=%i\n", max_depth);
  
  fprintf (f_out, "END\n\n");
  fclose (f_out);
  
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
int set_defaults (system_info *_system_info, char *input, int *log, int *max_depth, 
                  int *num_of_inter, char *output, int *type_inter, int *quiet)
{
  int i;
  
  for (i=0; i<3; i++)
    (*_system_info).cell[i] = 0.0;
  (*_system_info).from = -1;
  input[0] = '#';
  *log = 0;
  *max_depth = 0;
  *num_of_inter = 0;
  output[0] = '#';
  (*_system_info).to = -1;
  *type_inter = 0;
  *quiet = 0;
  
  return 0;
} 
