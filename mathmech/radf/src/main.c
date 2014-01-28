/**
 * @file
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_main.h"
#include <version.h>
#include <mathmech/coords.h>
#include <mathmech/messages.h>
#include <mathmech/radf.h>
#include <mathmech/radf_proc.h>
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
  char filename[256], tmp_str[2048];
  int error, i, j;
  FILE *f_inp, *f_log;
  
  char input[256], logfile[256], output[256];
  int log, matrix, mode, num_needed_at, needed_at[6], quiet, *radf, *true_label_mol;
  atom_info *_atom_info;
  radf_info _radf_info;
  system_info _system_info;
  
/* input                  input file name
 * logfile                log file name
 * output                 output file name
 * 
 * log                    status of log-mode
 * matrix                 status of matrix-mode
 * mode                   0 - if RDF, 1 - if RDF for center mass, 2 - if RADF
 * num_needed_at          number of needed atom types
 * needed_at              massive of number of needed atom types
 * quiet                  status of quiet-mode
 * radf                   not normed RADF
 * true_label_mol         massive of true numbers of molecule for atoms
 * 
 * _atom_info             atom information structure
 * _radf_info             radf information structure
 * _system_info           system information structure
 */
  
  set_defaults (&_system_info, &_radf_info, input, &log, &matrix, output, &quiet);
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h') && (argv[i][2] == '\0'))
    {
      sprintf (tmp_str, "                                    mm_radf\n");
      sprintf (tmp_str, "%sProgram that calculates radial distribution function (RDF) or radial-angles\n", tmp_str);
      sprintf (tmp_str, "%sdistribution function\n", tmp_str);
      sprintf (tmp_str, "%sVersion : %s                                               License : Beerware\n", tmp_str, PROJ_VERSION);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%smm_radf -i INPUT -s FIRST,LAST -c X,Y,Z -at ... -o OUTPUT [ -r MIN,MAX ]\n", tmp_str);
      sprintf (tmp_str, "%s                   [ -rs R_STEP ] [ -a MIN,MAX ] [ -as ANG_STEP ] [ -m ]\n", tmp_str);
      sprintf (tmp_str, "%s                                            [ -l LOGFILE ] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - mask of input files\n", tmp_str);
      sprintf (tmp_str, "%s  -s          - trajectory steps (integer)\n", tmp_str);
      sprintf (tmp_str, "%s  -c          - cell size (float), A\n", tmp_str);
      sprintf (tmp_str, "%s  -at         - atom types (integer). Format: 'AT1-AT2' or 'A1,A2,A3-B1,B2,B3'\n", tmp_str);
      sprintf (tmp_str, "%s                (will enable RDF calculation for center mass automaticaly)\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - output file name\n", tmp_str);
      sprintf (tmp_str, "%s  -r          - minimal and maximal radii for analyze (float), A. Default is\n", tmp_str);
      sprintf (tmp_str, "%s                '2.0,15.0'\n", tmp_str);
      sprintf (tmp_str, "%s  -rs         - radius step for analyze (float), A. Default is '0.2'\n", tmp_str);
      sprintf (tmp_str, "%s  -a          - minimal and maximal angles for analyze (float), deg. Default is\n", tmp_str);
      sprintf (tmp_str, "%s                '0.0,90.0'\n", tmp_str);
      sprintf (tmp_str, "%s  -as         - angle step for analyze (float), deg. It will enable RADF\n", tmp_str);
      sprintf (tmp_str, "%s                calculation automaticaly\n", tmp_str);
      sprintf (tmp_str, "%s  -m          - matrix output enable\n", tmp_str);
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
    else if ((argv[i][0] == '-') && (argv[i][1] == 's') && (argv[i][2] == '\0'))
// steps
    {
      sscanf (argv[i+1], "%i,%i", &_system_info.from, &_system_info.to);
      if (_system_info.from > _system_info.to)
      {
        _system_info.to += _system_info.from;
        _system_info.from = _system_info.to - _system_info.from;
        _system_info.to -= _system_info.from;
      }
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'c') && (argv[i][2] == '\0'))
// cell size
    {
      sscanf (argv[i+1], "%f,%f,%f", &_system_info.cell[0], &_system_info.cell[1], &_system_info.cell[2]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a') && (argv[i][2] == 't') && (argv[i][3] == '\0'))
// atom types
    {
      num_needed_at = 2;
      for (j=0; j<strlen(argv[i+1]); j++)
        if (argv[i+1][j] == ',')
          num_needed_at++;
      if (num_needed_at == 2)
        sscanf (argv[i+1], "%i-%i", &needed_at[0], &needed_at[1]);
      else if (num_needed_at == 6)
        sscanf (argv[i+1], "%i,%i,%i-%i,%i,%i", &needed_at[0], &needed_at[1], &needed_at[2],
                &needed_at[3], &needed_at[4], &needed_at[5]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o') && (argv[i][2] == '\0'))
// output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'r') && (argv[i][2] == '\0'))
// radii
    {
      sscanf (argv[i+1], "%f,%f", &_radf_info.r_min, &_radf_info.r_max);
      if (_radf_info.r_min > _radf_info.r_max)
      {
        _radf_info.r_min += _radf_info.r_max;
        _radf_info.r_max = _radf_info.r_min - _radf_info.r_max;
        _radf_info.r_min -= _radf_info.r_max;
      }
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'r') && (argv[i][2] == 's') && (argv[i][3] == '\0'))
// radius step
    {
      sscanf (argv[i+1], "%f", &_radf_info.r_step);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a') && (argv[i][2] == '\0'))
// angles
    {
      sscanf (argv[i+1], "%f,%f", &_radf_info.ang_min, &_radf_info.ang_max);
      if (_radf_info.ang_min > _radf_info.ang_max)
      {
        _radf_info.ang_min += _radf_info.ang_max;
        _radf_info.ang_max = _radf_info.ang_min - _radf_info.ang_max;
        _radf_info.ang_min -= _radf_info.ang_max;
      }
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a') && (argv[i][2] == 's') && (argv[i][3] == '\0'))
// angle step
    {
      sscanf (argv[i+1], "%f", &_radf_info.ang_step);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'm') && (argv[i][2] == '\0'))
// matrix mode
    {
      matrix = 1;
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
  error = error_checking (input, num_needed_at, needed_at, output, _system_info);
  if (error != 0)
  {
    print_message (quiet, stderr, log, f_log, 17, argv[0]);
    return 1;
  }
  
  print_message (quiet, stdout, log, f_log, 2, argv[0]);
  
// processing
// initial variables
// set mode
  if ((num_needed_at == 6) && (_radf_info.ang_step != 0.0))
    mode = 2;
  else if (num_needed_at == 6)
    mode = 1;
  else if (num_needed_at == 2)
    mode = 0;
  
  sprintf (filename, "%s.%03i", input, _system_info.from);
  print_message (quiet, stdout, log, f_log, 3, filename);
  f_inp = fopen (filename, "r");
  if (f_inp == NULL)
  {
    print_message (quiet, stderr, log, f_log, 18, filename);
    return 2;
  }
  fscanf (f_inp, "%i", &_system_info.num_atoms);
  fclose (f_inp);
  _atom_info = (atom_info *) malloc (8 * _system_info.num_atoms * sizeof (atom_info));
  if (mode == 2)
  {
    i = (_radf_info.r_max - _radf_info.r_min) / _radf_info.r_step;
    j = (_radf_info.ang_max - _radf_info.ang_min) / _radf_info.ang_step;
    i *= j;
  }
  else
    i = (_radf_info.r_max - _radf_info.r_min) / _radf_info.r_step;
  radf = (int *) malloc (i * sizeof (int));
  for (j=0; j<i; j++)
    radf[j] = 0;
  true_label_mol = (int *) malloc (_system_info.num_atoms * sizeof (int));
// error checking
  if ((_atom_info == NULL) || 
     (radf == NULL) || 
     (true_label_mol == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 3;
  }
  sprintf (tmp_str, "%6cOutput file: '%s';\n%6cLog: %i;\n%6cQuiet: %i;\n%6cMatrix mode: %i;\n\
%6cMask: %s;\n%6cFirst step: %i;\n%6cLast step: %i;\n%6cCell size: %.4f, %.4f, %.4f;\n%6cMode: %i;\n\
%6cR_MIN: %6.3f; R_MAX: %6.3f; R_STEP: %6.3f;\n", ' ', output, ' ', log, ' ', quiet, ' ', matrix, 
' ', input, ' ', _system_info.from, ' ', _system_info.to, ' ', _system_info.cell[0], 
_system_info.cell[1], _system_info.cell[2], ' ', mode, ' ', _radf_info.r_min, 
_radf_info.r_max, _radf_info.r_step);
  switch (mode)
  {
    case 0:
      sprintf (tmp_str, "%s%6cATOM TYPES: %i-%i\n", tmp_str, ' ', needed_at[0], needed_at[1]);
      break;
    case 1:
      sprintf (tmp_str, "%s%6cATOM TYPES: %i,%i,%i-%i,%i,%i\n", tmp_str, ' ', needed_at[0], needed_at[1], 
needed_at[2], needed_at[3], needed_at[4], needed_at[5]);
      break;
    case 2:
      sprintf (tmp_str, "%s%6cANG_MIN: %6.2f; ANG_MAX: %6.2f; ANG_STEP: %6.2f;\n\
%6cATOM TYPES: %i,%i,%i-%i,%i,%i\n", tmp_str, ' ', _radf_info.ang_min, _radf_info.ang_max, 
_radf_info.ang_step, ' ', needed_at[0], needed_at[1], needed_at[2], needed_at[3], 
needed_at[4], needed_at[5]);
      break;
  }
  print_message (quiet, stdout, log, f_log, 5, tmp_str);
  
// head
  printing_head (output, log, quiet, matrix, input, _system_info, mode, _radf_info, 
                 needed_at);
  
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
// main cycle
  for (i=_system_info.from; i<_system_info.to+1; i++)
  {
    sprintf (filename, "%s.%03i", input, i);
    print_message (quiet, stdout, log, f_log, 7, filename);
    error = reading_coords (0, filename, num_needed_at, needed_at, &_system_info, 
                            true_label_mol, _atom_info);
    if (error == 0)
    {
      sprintf (tmp_str, "%6cNumber of molecules: %i; %6cNumber of atoms: %i\n", 
               ' ', _system_info.num_mol, ' ', _system_info.num_atoms);
      print_message (quiet, stdout, log, f_log, 8, tmp_str);
      error = 1;
      switch (mode)
      {
        case 0:
          error = search_rdf (_system_info, _atom_info, _radf_info, radf);
          break;
        case 1:
          error = search_rdf_centr (_system_info, _atom_info, _radf_info, radf);
          if (error == 0)
        case 2:
          error = search_radf (_system_info, _atom_info, _radf_info, radf);
          break;
      }
    }
    if (error == 0)
      print_message (quiet, stdout, log, f_log, 22, argv[0]);
  }
  
  print_message (quiet, stdout, log, f_log, 13, argv[0]);
  print_message (quiet, stdout, log, f_log, 14, output);
// tail
  print_result (output, matrix, mode, _system_info, _radf_info, radf);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
// free memory
  free (_atom_info);
  free (radf);
  free (true_label_mol);
  
  print_message (quiet, stdout, log, f_log, 16, argv[0]);

  if (log == 1)
    fclose (f_log);
  return 0;
}
