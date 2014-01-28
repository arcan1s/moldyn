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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_main.h"
#include <version.h>
#include <mathmech/messages.h>
#include <mathmech/print_struct.h>
#include <mathmech/var_types.h>


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
  int error, i, tmp_int;
  FILE *f_inp, *f_log;
  
  char input[256], logfile[256], output[256];
  int log, *needed_mol, quiet, *true_label_mol;
  atom_info *_atom_info;
  system_info _system_info;
  
/* input                  input file name
 * logfile                log file name
 * output                 output file name
 * 
 * log                    status of log-mode
 * needed_mol             massive of numbers of needed molecule
 * num_atoms              number of atoms
 * num_mol                number of molecules
 * quiet                  status of quiet-mode
 * true_label_mol         massive of true numbers of molecule for atoms
 * 
 * _atom_info             atom information structure
 */
  
  set_defaults (input, &log, output, &quiet);
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h') && (argv[i][2] == '\0'))
    {
      sprintf (tmp_str, "                                     mm_trj2pdb\n");
      sprintf (tmp_str, "%sProgram for create PDB file from trajectory snapshot\n", tmp_str);
      sprintf (tmp_str, "%sVersion : %s                                               License : Beerware\n", tmp_str, PROJ_VERSION);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%smm_trj2pdb -i INPUT -o OUTPUT [ -l LOGFILE ] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - input file name\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - output file name\n", tmp_str);
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
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o') && (argv[i][2] == '\0'))
// output file
    {
      strcpy (output, argv[i+1]);
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
  error = error_checking (input, output);
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
  fscanf (f_inp, "%i", &_system_info.num_atoms);
  fclose (f_inp);
  _atom_info = (atom_info *) malloc (8 * _system_info.num_atoms * sizeof (atom_info));
  needed_mol = (int *) malloc (_system_info.num_atoms * sizeof (int));
  true_label_mol = (int *) malloc (_system_info.num_atoms * sizeof (int));
// error checking
  if ((_atom_info == NULL) ||
     (needed_mol == NULL) || 
     (true_label_mol == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 3;
  }
  for (i=0; i<3; i++)
    _system_info.cell[i] = 0.0;
  sprintf (tmp_str, "%6cInput file: '%s';\n%6cOutput file: '%s';\n%6cLog: %i;\n%6cQuiet: %i;\n", 
' ', input, ' ', output, ' ', log, ' ', quiet);
  print_message (quiet, stdout, log, f_log, 5, tmp_str);
  
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
  
// reading coordinates
  print_message (quiet, stdout, log, f_log, 7, input);
  error = 1;
  error = reading_coords (1, input, tmp_int, &tmp_int, &_system_info, true_label_mol, 
                          _atom_info);
  
// print coordinates
  if (error == 0)
  {
    sprintf (tmp_str, "%6cNumber of molecules: %i; %6cNumber of atoms: %i\n", 
            ' ', _system_info.num_mol, ' ', _system_info.num_atoms);
    for (i=0; i<_system_info.num_mol; i++)
      needed_mol[i] = 8 * i;
    error = 1;
    error = print_structure (output, _system_info.num_mol, needed_mol, _system_info, _atom_info);
  }
  if (error == 0)
    print_message (quiet, stderr, log, f_log, 12, output);
  
  print_message (quiet, stderr, log, f_log, 13, argv[0]);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
// free memory
  free (_atom_info);
  free (needed_mol);
  free (true_label_mol);
  
  print_message (quiet, stdout, log, f_log, 16, argv[0]);

  if (log == 1)
    fclose (f_log);
  return 0;
}
