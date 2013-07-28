/**
 * @file
 */

#include <stdio.h>

#include "messages.h"


/**
 * @fn error_checking
 */
int error_checking (const float *cell, const int from, const char *input, 
                    const int max_depth, const int num_of_inter, const char *output, 
                    const int to, const int type_inter)
/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (cell, from, input, max_depth, num_of_inter, output, to, 
 *                 type_inter);
 * @endcode
 * 
 * @param cell            massive of cell size
 * @param from            first trajectory step
 * @param input           mask of trajectory files
 * @param max_depth       max depth for check cycles in graph analyze
 * @param num_of_inter    number of different interactions
 * @param output          output file name
 * @param to              last trajectory step
 * @param type_inter      number of atoms for interactions
 * 
 * @return 11             - error in 'type_inter'
 * @return 12             - error in 'cell'
 * @return 13             - error in 'to' or 'from'
 * @return 14             - error in 'num_of_inter'
 * @return 15             - error in 'input'
 * @return 16             - error in 'output'
 * @return 19             - error in 'max_depth'
 * @return 0              - exit without errors
 */
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


/**
 * @fn printing_head
 */
int printing_head (const char *output, const int log, const int quiet, 
                   const char *input, const int from, const int to, const float *cell, 
                   const int type_inter, const int *label_atom, 
                   const int num_of_inter, const float *crit, const int max_depth)
/**
 * @brief function that prints header in output file
 * @code
 * printing_head (output, log, quiet, input, from, to, cell, type_inter, label_atom, 
 *                num_of_inter, crit, max_depth);
 * @endcode
 * 
 * @param output          output file nams
 * @param log             status of log-mode
 * @param quiet           status of quiet-mode
 * @param input           mask of trajectory files
 * @param from            first trajectory step
 * @param to              last trajectory step
 * @param cell            massive of cell size
 * @param type_inter      number of atoms for interactions
 * @param label_atom      massive of atom types for interactions
 * @param num_of_inter    number of different interactions
 * @param crit            massive of criteria
 * @param max_depth       maximum depth for check cycles in graph analyze
 * 
 * @return 0              - exit without errors
 */
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
int set_defaults (float *cell, int *from, char *input, int *log, int *max_depth, 
                  int *num_of_inter, char *output, int *to, int *type_inter, int *quiet)
/**
 * @brief function that sets default values of variables
 * @code
 * set_defaults (cell, &from, input, &log, &max_depth, &num_of_inter, output, &to, 
 *               &type_inter, &quiet);
 * @endcode
 * 
 * @param cell            massive of cell size
 * @param from            first trajectory step
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param max_depth       maximum depth for check cycles in graph analyze
 * @param num_of_inter    number of different interactions
 * @param output          output file name
 * @param to              last trajectory step
 * @param type_inter      number of atoms for interactions
 * @param quiet           status of quiet-mode
 * 
 * @return 0              - exit without errors
 */
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
