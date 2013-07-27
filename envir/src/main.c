#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_main.h"
#include "coords.h"
#include "envir_search.h"
#include "messages.h"
#include "print_struct.h"
#include "set_center.h"


int main(int argc, char *argv[])
{
  char tmp_str[2048];
  int error, i, j, *tmp_int;
  FILE *f_inp, *f_log;
  
  char *ch_type_atoms, input[256], logfile[256], output[256];
  float cell[3], *centr_coords, *coords, rad;
  int *label_mol, log, num_atoms, num_mol, num_needed_mol, num_of_mol, 
      *needed_mol, quiet, *true_label_mol;
/* ch_type_atoms    - massive of char types for atoms
 * input            - input file name
 * logfile          - log file name
 * output           - output file name
 * 
 * cell             - cell dimension
 * centr_coords     - massive of coordinates of center molecules
 * coords           - massive of coordinates
 * rad              - criterion
 * 
 * label_mol        - massive of numbers of molecule for atoms
 * log              - status of log-mode
 * num_atoms        - number of atoms for writing coordinates
 * num_mol          - number of molecules for writing coordinates
 * num_needed_mol   - number of needed molecules
 * num_of_mol       - number of molecule for search
 * needed_mol       - massive of needed molecules
 * quiet            - status of quiet-mode
 * true_label_mol   - massive of true numbers of molecule for atoms
 */
  
  set_defaults (cell, input, &log, &num_of_mol, output, &quiet, &rad);
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h'))
    {
      sprintf (tmp_str, "                                        envir\n");
      sprintf (tmp_str, "%sProgram for search environment for chosen molecule by geometric criterion\n", tmp_str);
      sprintf (tmp_str, "%sVersion : 1.0.1                                                    License : GPL\n", tmp_str);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%senvir -i FILENAME -c X,Y,Z -o FILEMANE [ -n NUM_OF_MOLECULE ] [ -r RADIUS ] [ -l LOGFILE] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - input file with coordinates\n", tmp_str);
      sprintf (tmp_str, "%s  -c          - cell size (float), A\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - output file with coordinates\n", tmp_str);
      sprintf (tmp_str, "%s  -n          - number of molecule for search (integer). Default is 1\n", tmp_str);
      sprintf (tmp_str, "%s  -r          - radius of environment (float). Default is 6.0\n", tmp_str);
      sprintf (tmp_str, "%s  -l          - log enable\n", tmp_str);
      sprintf (tmp_str, "%s  -q          - quiet enable\n", tmp_str);
      sprintf (tmp_str, "%s  -h          - show this help and exit\n", tmp_str);
      fputs (tmp_str, stdout);
      return 0;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'i'))
//       input file
    {
      strcpy (input, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'c'))
//       cell size
    {
      sscanf (argv[i+1], "%f,%f,%f", &cell[0], &cell[1], &cell[2]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o'))
//       output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'n'))
//       number of molecule
    {
      sscanf (argv[i+1], "%i", &num_of_mol);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'r'))
//       radius of environment
    {
      sscanf (argv[i+1], "%f", &rad);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'l'))
//       log mode
    {
      log = 1;
      strcpy (logfile, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'q'))
//       quiet mode
    {
      quiet = 1;
    }
  }
  
  if (log == 1)
    f_log = fopen (logfile, "w");
  
  print_message (quiet, stdout, log, f_log, 0, argv[0]);
  print_message (quiet, stdout, log, f_log, 1, argv[0]);
  
// error check
  error = error_checking (cell, input, output);
  if (error != 0)
  {
    print_message (quiet, stderr, log, f_log, 17, argv[0]);
    return 1;
  }
  
  print_message (quiet, stdout, log, f_log, 2, argv[0]);
  
//   processing
//   initial variables
  print_message (quiet, stdout, log, f_log, 3, input);
  f_inp = fopen (input, "r");
  if (f_inp == NULL)
  {
    print_message (quiet, stderr, log, f_log, 18, input);
    return 1;
  }
  fscanf (f_inp, "%i", &num_atoms);
  fclose (f_inp);
  ch_type_atoms = (char *) malloc (2 * num_atoms * sizeof (char));
  coords = (float *) malloc (3 * 8 * num_atoms * sizeof (float));
  label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  tmp_int = (int *) malloc (8 * num_atoms * sizeof (int));
  true_label_mol = (int *) malloc (num_atoms * sizeof (int));
//   error checking
  if ((ch_type_atoms == NULL) ||
    (coords == NULL) || 
    (label_mol == NULL) || 
    (tmp_int == NULL) || 
    (true_label_mol == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 17;
  }
  sprintf (tmp_str, "%6cInput file: '%s';\n%6cOutput file: '%s';\n%6cLog: %i;\n\
%6cQuiet: %i;\n%6cCell size: %.4f, %.4f, %.4f;\n%6cSelect molecule: %i;\n\
%6cCriterion: %.1f\n", ' ', input, ' ', output, ' ', log, ' ', quiet, ' ', cell[0], 
           cell[1], cell[2], ' ' , num_of_mol, ' ', rad);
  print_message (quiet, stdout, log, f_log, 5, tmp_str);
  
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
  
//   reading coordinates
  print_message (quiet, stdout, log, f_log, 7, input);
  error = reading_coords (1, input, tmp_int, tmp_int, cell, &num_mol, &num_atoms, 
                          true_label_mol, label_mol, tmp_int, coords, ch_type_atoms);
  centr_coords = (float *) malloc (3 * 8 * num_mol * sizeof (float));
  needed_mol = (int *) malloc (num_mol * sizeof (int));
  if (error == 0)
  {
    sprintf (tmp_str, "%6cNumber of molecules: %i; %6cNumber of atoms: %i\n", 
             ' ', num_mol, ' ', num_atoms);
    print_message (quiet, stdout, log, f_log, 8, tmp_str);
  }
//   error checking
  if ((centr_coords == NULL) ||
    (needed_mol == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 17;
  }
  
//   analyze
  if (error == 0)
  {
    error = set_center (num_atoms, num_mol, label_mol, coords, centr_coords);
    if (error == 0)
    {
      print_message (quiet, stderr, log, f_log, 20, argv[0]);
      error = search_envir (num_of_mol, num_mol, centr_coords, rad, needed_mol, 
                            &num_needed_mol);
      if (error == 0)
      {
        print_message (quiet, stderr, log, f_log, 21, argv[0]);
        error = print_structure (output, num_needed_mol, needed_mol, num_atoms, 
                                 label_mol, ch_type_atoms, coords);
        print_message (quiet, stderr, log, f_log, 12, output);
      }
    }
  }
  
  print_message (quiet, stdout, log, f_log, 13, argv[0]);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
//   free memory
  free (ch_type_atoms);
  free (centr_coords);
  free (coords);
  free (label_mol);
  free (needed_mol);
  free (tmp_int);
  free (true_label_mol);
  
  print_message (quiet, stdout, log, f_log, 16, argv[0]);

  if (log == 1)
    fclose (f_log);
  return 0;
}