/**
 * @file
 */
/**
 * @mainpage mm_trj
 * @image latex ./logo.png
 *
 * @section intro_sec Introduction
 *
 * <b>About this program</b>:
 * <ul>
 * <li>Program that generates trajectory files
 * </ul>
 *
 * <b>Developer</b>:
 * <ul>
 * <li>Evgeniy Alekseev aka arcanis <pre><esalexeev (at) gmail (dot) com></pre>
 *</ul>
 * <b>License</b>:
 * <ul>
 * <li>GPL
 * </ul>
 *
 * @section How-To-Use How to use
 * Usage:
 * <pre>
 * mm_trj -i INPUT_TRJ -t INPUT_TYPE -s NUMBER -a INPUT_ATOMS -o OUTPUT [ -tt TOTAL_TYPES ]
 *                                                             [ -l LOGFILE ] [ -q ] [ -h ]
 * Parametrs:
 *    -i          - input file name
 *    -t          - type of trajectory. Supported formats: gmx, puma
 *    -s          - number of trajectory steps (integer)
 *    -a          - input file with atom types. See file format in manual
 *    -o          - mask of output files
 *    -tt         - number of different atom types. Default is 1024
 *    -l          - log enable
 *    -q          - quiet enable
 *    -h          - show this help and exit
 * </pre>
 * 
 * @page Install
 * 
 * @section Requirements Requirements
 * The application mm_trj requires the following external stuff:
 * - cmake  >= 2.8
 * - gcc    >= 4.8
 *
 * @section How-To How to install
 *
 * @subsection Linux Linux
 * @code
 * mkdir build && cd build
 * cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ../
 * make
 * make install
 * @endcode
 * 
 * @subsection Windows Windows
 * @code
 * create project file using 'cmake'
 * compile project
 * @endcode
 * You may also download compiled executable file for Win_x86.
 *
 * @page Changelog
 * V.1.0.1 (2013-07-27)
 * * initial release
 */ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_main.h"
#include "atom_types.h"
#include "messages.h"
#include "print_trj.h"
#include "read_gmx.h"
#include "read_puma.h"


/**
 * @fn main
 */
int main(int argc, char *argv[])
/**
 * @return 1              - error in error_checking
 * @return 2              - input file does not exist
 * @return 3              - memory error
 * @return 4              - unknown flag
 * @return 0              - exit without errors
 */
{
  char tmp_str[2048];
  int error, i;
  FILE *f_inp, *f_log;
  
  char *ch_atom_types, input[256], input_at[256], logfile[256], output[256];
  float *coords;
  int *atom_types, log, *num_atoms, *num_mol, num_types, quiet, step, total_types, type;
  
/* ch_atom_types          massive of char atom types
 * input                  input file name
 * input_at               input file name with atom types
 * logfile                log file name
 * output                 mask of output files
 * 
 * coords                 massive of coordinates
 * 
 * atom_types             massive of atom types
 * log                    status of log-mode
 * num_atoms              massive of number of atoms of selected molecule
 * num_mol                massive of number of molecule of selected type
 * num_types              number of molecule types
 * quiet                  status of quiet-mode
 * step                   number of trajectory steps
 * total_types            number of different atom types
 * type                   type of trajectory
 */
  
  set_defaults (input, input_at, &log, output, &step, &total_types, &type, &quiet);
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h') && (argv[i][2] == '\0'))
    {
      sprintf (tmp_str, "                                    mm_trj\n");
      sprintf (tmp_str, "%sProgram that generates trajectory files\n", tmp_str);
      sprintf (tmp_str, "%sVersion : 1.0.1                                                    License : GPL\n", tmp_str);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%smm_trj -i INPUT_TRJ -t INPUT_TYPE -s NUMBER -a INPUT_ATOMS -o OUTPUT [ -tt TOTAL_TYPES ]\n", tmp_str);
      sprintf (tmp_str, "%s                                                            [ -l LOGFILE ] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - input file name\n", tmp_str);
      sprintf (tmp_str, "%s  -t          - type of trajectory. Supported formats: gmx, puma\n", tmp_str);
      sprintf (tmp_str, "%s  -s          - number of trajectory steps (integer)\n", tmp_str);
      sprintf (tmp_str, "%s  -a          - input file with atom types. See file format in manual\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - mask of output files\n", tmp_str);
      sprintf (tmp_str, "%s  -tt         - number of different atom types. Default is 1024\n", tmp_str);
      sprintf (tmp_str, "%s  -l          - log enable\n", tmp_str);
      sprintf (tmp_str, "%s  -q          - quiet enable\n", tmp_str);
      sprintf (tmp_str, "%s  -h          - show this help and exit\n", tmp_str);
      fputs (tmp_str, stdout);
      return 0;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'i') && (argv[i][2] == '\0'))
// input file
    {
      strcpy (input, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 't') && (argv[i][2] == '\0'))
// type
    {
      if ((argv[i+1][0] == 'g') && (argv[i+1][1] == 'm') && (argv[i+1][2] == 'x') && 
         (argv[i+1][3] == '\0'))
// gromacs text file
        type = 0;
      else if ((argv[i+1][0] == 'p') && (argv[i+1][1] == 'u') && (argv[i+1][2] == 'm') && 
              (argv[i+1][3] == 'a') && (argv[i+1][4] == '\0'))
// puma
        type = 1;
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 's') && (argv[i][2] == '\0'))
// steps
    {
      sscanf (argv[i+1], "%i", &step);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a') && (argv[i][2] == '\0'))
// atom types
    {
      strcpy (input_at, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o') && (argv[i][2] == '\0'))
// output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 't') && (argv[i][2] == 't') && (argv[i][3] == '\0'))
// number of atom types
    {
      sscanf (argv[i+1], "%i", &total_types);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'l') && (argv[i][2] == '\0'))
// log mode
    {
      log = 1;
      strcpy (logfile, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'q') && (argv[i][2] == '\0'))
// quiet mode
    {
      quiet = 1;
    }
    else
// unknown flag
    {
      return 4;
    }
  }
  
  if (log == 1)
    f_log = fopen (logfile, "w");
  
  print_message (quiet, stdout, log, f_log, 0, argv[0]);
  print_message (quiet, stdout, log, f_log, 1, argv[0]);
  
// error check
  error = error_checking (input, input_at, output, step, type);
  if (error != 0)
  {
    print_message (quiet, stderr, log, f_log, 17, argv[0]);
    return 1;
  }
  
  print_message (quiet, stdout, log, f_log, 2, argv[0]);
  
// processing
// initial variables
  print_message (quiet, stdout, log, f_log, 3, input);
  f_inp = fopen (input, "r");
  if (f_inp == NULL)
    return 2;
  switch (type)
  {
    case 0:
      fgets (tmp_str, 256, f_inp);
      fgets (tmp_str, 256, f_inp);
      sscanf (tmp_str, "   natoms=%i%s", &i, tmp_str);
      break;
    case 1:
      fgets (tmp_str, 256, f_inp);
      sscanf (tmp_str, "%s%s%i%s", tmp_str, tmp_str, &i, tmp_str);
      break;
  }
  fclose (f_inp);
  atom_types = (int *) malloc (total_types * sizeof (int));
  ch_atom_types = (char *) malloc (2 * total_types * sizeof (char));
  coords = (float *) malloc (3 * i * sizeof (float));
  num_atoms = (int *) malloc (total_types * sizeof (int));
  num_mol = (int *) malloc (total_types * sizeof (int));
  num_types = 0;
  if ((atom_types == NULL) || 
     (ch_atom_types == NULL) || 
     (coords == NULL) || 
     (num_atoms == NULL) || 
     (num_mol == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 3;
  }
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
// read atom types
  error = 1;
  error = reading_atoms (input_at, &num_types, num_mol, num_atoms, ch_atom_types, 
                         atom_types, total_types);
  
  if (error == 0)
  {
    sprintf (tmp_str, "%6cLog: %i;\n%6cQuiet: %i;\n%6cInput file: %s;\n%6cTrajectory type: %i;\n\
%6cNumber of trajectory step: %i;\n%6cInput file with atom types: %s;\n%6cMask of output file: %s;\n\
%6cNumber of different atom types: %i;\n%6cNumber of different molecules: %i;\n%6cNumber of atoms in system: %i\n",
' ', log, ' ', quiet, ' ', input, ' ', type, ' ', step, ' ', input_at, ' ', output, 
' ', total_types, ' ', num_types, ' ', i);
    print_message (quiet, stdout, log, f_log, 5, tmp_str);
  }
  else
    return 2;
  
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
// main cycle
  switch (type)
  {
    case 0:
      rw_gmx (input, step, output, num_types, num_mol, num_atoms, ch_atom_types, 
              atom_types, coords);
      break;
    case 1:
      rw_puma (input, step, output, num_types, num_mol, num_atoms, ch_atom_types, 
               atom_types, coords);
      break;
  }
  
  print_message (quiet, stdout, log, f_log, 13, argv[0]);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
// free memory
  free (atom_types);
  free (ch_atom_types);
  free (coords);
  free (num_atoms);
  free (num_mol);
  
  print_message (quiet, stdout, log, f_log, 16, argv[0]);

  if (log == 1)
    fclose (f_log);
  return 0;
}