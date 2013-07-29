/**
 * @file
 */
/**
 * @mainpage agl
 * @image latex ./logo.png
 *
 * @section intro_sec Introduction
 *
 * <b>About this program</b>:
 * <ul>
 * <li>Program that creates PDB file with chosen aglomerate
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
 * agl -a FILENAME -i FILENAME -c X,Y,Z -o FILEMANE [ -l LOGFILE] [ -q ] [ -h ]
 *
 * Parametrs:
 *    -a          - input file with aglomerates (in format statgen)
 *    -i          - input file with coordinates
 *    -c          - cell size (float), A
 *    -o          - output file with coordinates
 *    -l          - log enable
 *    -q          - quiet enable
 *    -h          - show this help and exit
 * </pre>
 * 
 * @page Install
 * 
 * @section Requirements Requirements
 * The application statgen requires the following external stuff:
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
#include "coords.h"
#include "messages.h"
#include "print_struct.h"
#include "read_agl.h"
#include "select_mol.h"
#include "set_center.h"


/**
 * @fn main
 */
int main(int argc, char *argv[])
/**
 * @return 1              - error in error_checking
 * @return 2              - input file does not exist
 * @return 3              - memory error
 * @return 0              - exit without errors
 */
{
  char tmp_str[2048];
  int error, i, *tmp_int;
  FILE *f_inp, *f_log;
  
  char aglinp[256], *ch_type_atoms, input[256], logfile[256], output[256];
  float cell[3], *centr_coords, *coords;
  int *label_mol, log, num_atoms, num_mol, num_needed_mol, *needed_mol, quiet, 
      *true_label_mol;
  
/* aglinp                 aglomerate file name
 * ch_type_atoms          massive of char atom types
 * input                  input file name
 * logfile                log file name
 * output                 output file name
 * 
 * cell                   massive of cell size
 * centr_coords           massive of centered coordinates
 * coords                 massive of coordinates
 * 
 * label_mol              massive of numbers of molecule for atoms
 * log                    status of log-mode
 * num_atoms              number of atoms
 * num_mol                number of molecules
 * num_needed_mol         number of needed molecules
 * needed_mol             massive of number of needed molecules
 * quiet                  status of quiet-mode
 * true_label_mol         massive of true numbers of molecule for atoms
 */
  
  set_defaults (aglinp, cell, input, &log, output, &quiet);
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h'))
    {
      sprintf (tmp_str, "                                        agl\n");
      sprintf (tmp_str, "%sProgram for create PDB file with chosen aglomerate\n", tmp_str);
      sprintf (tmp_str, "%sVersion : 1.0.1                                                    License : GPL\n", tmp_str);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%sagl -a FILENAME -i FILENAME -c X,Y,Z -o FILEMANE [ -l LOGFILE] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -a          - input file with aglomerates (in format statgen)\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - input file with coordinates\n", tmp_str);
      sprintf (tmp_str, "%s  -c          - cell size (float), A\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - output file with coordinates\n", tmp_str);
      sprintf (tmp_str, "%s  -l          - log enable\n", tmp_str);
      sprintf (tmp_str, "%s  -q          - quiet enable\n", tmp_str);
      sprintf (tmp_str, "%s  -h          - show this help and exit\n", tmp_str);
      fputs (tmp_str, stdout);
      return 0;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a'))
// input file
    {
      strcpy (aglinp, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'i'))
// input file
    {
      strcpy (input, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'c'))
// cell size
    {
      sscanf (argv[i+1], "%f,%f,%f", &cell[0], &cell[1], &cell[2]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o'))
// output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'l'))
// log mode
    {
      log = 1;
      strcpy (logfile, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'q'))
// quiet mode
    {
      quiet = 1;
    }
  }
  
  if (log == 1)
    f_log = fopen (logfile, "w");
  
  print_message (quiet, stdout, log, f_log, 0, argv[0]);
  print_message (quiet, stdout, log, f_log, 1, argv[0]);
  
// error check
  error = error_checking (aglinp, cell, input, output);
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
  {
    print_message (quiet, stderr, log, f_log, 18, input);
    return 2;
  }
  fscanf (f_inp, "%i", &num_atoms);
  fclose (f_inp);
  ch_type_atoms = (char *) malloc (2 * num_atoms * sizeof (char));
  coords = (float *) malloc (3 * 8 * num_atoms * sizeof (float));
  label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  needed_mol = (int *) malloc (num_atoms * sizeof (int));
  tmp_int = (int *) malloc (8 * num_atoms * sizeof (int));
  true_label_mol = (int *) malloc (num_atoms * sizeof (int));
// error checking
  if ((ch_type_atoms == NULL) ||
    (coords == NULL) || 
    (label_mol == NULL) || 
    (needed_mol == NULL) || 
    (tmp_int == NULL) || 
    (true_label_mol == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 3;
  }
  sprintf (tmp_str, "%6cAglomerate file: '%s';\n%6cInput file: '%s';\n\
%6cOutput file: '%s';\n%6cLog: %i;\n%6cQuiet: %i;\n%6cCell size: %.4f, %.4f, %.4f\n", 
' ', aglinp, ' ', input, ' ', output, ' ', log, ' ', quiet, ' ', cell[0], cell[1], cell[2]);
  print_message (quiet, stdout, log, f_log, 5, tmp_str);
  
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
  
// reading aglomerate
  print_message (quiet, stdout, log, f_log, 7, aglinp);
  error = reading_agl (aglinp, &num_needed_mol, tmp_str, needed_mol);
  
  if (error == 0)
  {
    sprintf (tmp_str, "%6cNumber of molecules in aglomerate: %i\n", ' ', num_needed_mol);
    print_message (quiet, stdout, log, f_log, 8, tmp_str);
// reading coordinates
    print_message (quiet, stdout, log, f_log, 7, input);
    error = reading_coords (2, input, num_needed_mol, needed_mol, cell, &num_mol, 
                            &num_atoms, true_label_mol, label_mol, tmp_int, coords, 
                            ch_type_atoms);
    centr_coords = (float *) malloc (3 * 8 * num_mol * sizeof (float));
    if (centr_coords == NULL)
    {
      print_message (quiet, stderr, log, f_log, 19, argv[0]);
      return 3;
    }
    
// analyze
    if (error == 0)
    {
      sprintf (tmp_str, "%6cNumber of molecules: %i; %6cNumber of atoms: %i\n", 
              ' ', num_mol, ' ', num_atoms);
      print_message (quiet, stdout, log, f_log, 8, tmp_str);
      error = 1;
      error = set_center (num_atoms, num_mol, label_mol, coords, centr_coords);
      if (error == 0)
      {
        print_message (quiet, stderr, log, f_log, 20, argv[0]);
        error = 1;
        error = select_molecule (centr_coords, num_needed_mol, needed_mol);
        if (error == 0)
        {
          print_message (quiet, stderr, log, f_log, 4, argv[0]);
          error = 1;
          error = print_structure (output, num_needed_mol, needed_mol, num_atoms, 
                                   label_mol, ch_type_atoms, coords);
          print_message (quiet, stderr, log, f_log, 12, output);
        }
      }
    }
  }
  
  print_message (quiet, stderr, log, f_log, 13, argv[0]);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
// free memory
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