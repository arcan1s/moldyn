/**
 * @file
 */

#include <stdio.h>

#include <version.h>
#include <mathmech/messages.h>


/**
 * @fn error_checking
 */
int error_checking (const float *cell, const int from, const char *input, 
                    const int num_needed_at, const int *needed_at, 
                    const char *output, const int to)
/**
 * @brief function that checks errors in input variables
 * @code
 * error_checking (cell, from, input, num_needed_at, needed_at, output, to);
 * @endcode
 * 
 * @param cell            massive of cell size
 * @param from            first trajectory step
 * @param input           input file name
 * @param num_needed_at   number of needed atom types
 * @param needed_at       massive of number of needed atom types
 * @param output          output file name
 * @param to              last trajectory step
 * 
 * @return 11             - error in 'cell'
 * @return 12             - error in 'input'
 * @return 13             - error in 'output'
 * @return 14             - error in 'from' or 'to'
 * @return 15             - error in 'num_needed_at'
 * @return 16             - error in 'needed_at'
 * @return 0              - exit without errors
 */
{
  if ((cell[0] == 0.0) || (cell[1] == 0.0) || (cell[2] == 0.0))
    return 11;
  if (input[0] == '#')
    return 12;
  if (output[0] == '#')
    return 13;
  if ((from == -1) || (to == -1))
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
 * @fn printing_head
 */
int printing_head (const char *output, const int log, const int quiet, const int matrix, 
                   const char *input, const int from, const int to, const float *cell, 
                   const int mode, const double r_min, const double r_max, 
                   const double r_step, const double ang_min, const double ang_max, 
                   const double ang_step, const int *needed_at)
/**
 * @brief function that prints header in output file
 * @code
 * printing_head (output, log, quiet, matrix, input, from, to, cell, mode, r_min, 
 *                r_max, r_step, ang_min, ang_max, ang_step, needed_at);
 * @endcode
 * 
 * @param output          output file nams
 * @param log             status of log-mode
 * @param quiet           status of quiet-mode
 * @param matrix          status of matrix-mode
 * @param input           mask of trajectory files
 * @param from            first trajectory step
 * @param to              last trajectory step
 * @param cell            massive of cell size
 * @param mode            0 - if RDF, 1 - if RDF for center mass, 2 - if RADF
 * @param r_max           maximal radius
 * @param r_min           minimal radius
 * @param r_step          radius step
 * @param ang_max         maximal angle for RADF
 * @param ang_min         minimal angle for RADF
 * @param ang_step        anlge step for RADF
 * @param needed_at       massive of number of needed atom types
 * 
 * @return 0              - exit without errors
 */
{
  FILE *f_out;
  
  f_out = fopen (output, "w");
  fprintf (f_out, "radf ::: V.%s\n\n", PROJ_VERSION);
  fprintf (f_out, "CONFIGURATION\n");
  
  fprintf (f_out, "LOG=%i\nQUIET=%i\nMATRIX=%i\n", log, quiet, matrix);
  fprintf (f_out, "MASK=%s\nFIRST=%i\nLAST=%i\n", input, from, to);
  fprintf (f_out, "CELL=%.4f,%.4f,%.4f\n", cell[0], cell[1], cell[2]);
  fprintf (f_out, "MODE=%i\n", mode);
  fprintf (f_out, "R_MIN=%.3f\nR_MAX=%.3f\nR_STEP=%.3f\n", r_min, r_max, r_step);
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
ATOM=%i,%i,%i-%i,%i,%i\n",ang_min, ang_max, ang_step, needed_at[0], needed_at[1], 
needed_at[2], needed_at[3], needed_at[4], needed_at[5]);
      break;
  }
  
  fprintf (f_out, "END\n\n");
  fclose (f_out);
  
  return 0;
}


/**
 * @fn set_defaults
 */
int set_defaults (float *ang_max, float *ang_min, float *ang_step, float *cell, 
                  int *from, char *input, int *log, int *matrix, float *r_max, 
                  float *r_min, float *r_step, char *output, int *to, int *quiet)
/**
 * @brief function that sets default values of variables
 * @code
 * set_defaults (&ang_max, &ang_min, &ang_step, cell, &from, input, &log, &r_max, 
 *               &r_min, &r_step, output, &to, &quiet);
 * @endcode
 * 
 * @param ang_max         maximal angle for RADF
 * @param ang_min         minimal angle for RADF
 * @param ang_step        angle step
 * @param cell            massive of cell size
 * @param from            first trajectory step
 * @param input           mask of trajectory files
 * @param log             status of log-mode
 * @param matrix          status of matrix-mode
 * @param r_max           maximal radius
 * @param r_min           minimal radius
 * @param r_step          radius step
 * @param output          output file name
 * @param to              last trajectory step
 * @param quiet           status of quiet-mode
 * 
 * @return 0              - exit without errors
 */
{
  int i;
  
  *ang_max = 90.0;
  *ang_min = 0.0;
  *ang_step = 0.0;
  for (i=0; i<3; i++)
    cell[i] = 0.0;
  *from = -1;
  input[0] = '#';
  *log = 0;
  *matrix = 0;
  *r_max = 15.0;
  *r_min = 2.0;
  *r_step = 0.2;
  output[0] = '#';
  *to = -1;
  *quiet = 0;
  
  return 0;
}
