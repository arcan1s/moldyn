/* Additional library for main.c (statgen)
 */

#include <stdio.h>

// #include "messages.h"


int error_checking (const float *cell, const int from, const char *input, 
                    const int max_depth, const int num_of_inter, const char *output, 
                    const int to, const int type_inter)
{
  if ((type_inter == 0) || (type_inter > 4))
    return 11;
  if ((cell[0] == 0.0) || (cell[1] == 0.0) || (cell[2] == 0.0))
    return 12;
  if ((to == -1) || (from == -1))
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


int printing_head (const char *output, const int log, const int quiet, 
                   const char *input, const int from, const int to, const float *cell, 
                   const int type_inter, const int *label_atom, 
                   const int num_of_inter, const float *crit, const int max_depth)
{
  int i, j;
  FILE *f_out;
  
  f_out = fopen (output, "w");
  fprintf (f_out, "statgen ::: V.1.0.1 ::: 2013-07-23\n\n");
  fprintf (f_out, "CONFIGURATION\n");
  
  fprintf (f_out, "LOG=%i\nQUIET=%i\n", log, quiet);
  fprintf (f_out, "MASK=%s\nFIRST=%i\nLAST=%i\n", input, from, to);
  fprintf (f_out, "CELL=%.4f,%.4f,%.4f\n", cell[0], cell[1], cell[2]);
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


int print_message (const int quiet, FILE *std_output, const int log, FILE *f_log, 
                   const int mode, const char *str)
{  
  if ((quiet != 1) && (std_output != stderr))
    message (0, mode, str, std_output);
  if (log == 1)
    message (1, mode, str, f_log);
  
  return 0;
}


int set_defaults (float *cell, int *from, char *input, int *log, int *max_depth, 
                  int *num_of_inter, char *output, int *to, int *type_inter, int *quiet)
{
  int i;
  
  for (i=0; i<3; i++)
    cell[i] = 0.0;
  *from = -1;
  input[0] = '#';
  *log = 0;
  *max_depth = 0;
  *num_of_inter = 0;
  output[0] = '#';
  *to = -1;
  *type_inter = 0;
  *quiet = 0;
  
  return 0;
} 
