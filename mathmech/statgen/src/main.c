/**
 * @file
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "add_main.h"
#include <version.h>
#include <mathmech/coords.h>
#include <mathmech/messages.h>
#include <mathmech/stat_print.h>
#include <mathmech/stat_select.h>
#include <mathmech/stat_sort.h>
#include <mathmech/summary_stat.h>
#include <mathmech/var_types.h>


/**
 * @fn main
 */
int main (int argc, char *argv[])
/**
 * @return 1              - error in error_checking
 * @return 2              - input file does not exist
 * @return 3              - memory error
 * @return 4              - unknown flag
 * @return 0              - exit without errors
 */
{
  char filename[256], tmp_str[2048];
  int error, i, index, j, label[2];
  float label_fl;
  FILE *f_inp, *f_log;
  
  char input[256], logfile[256], output[256];
  float *crit;
  int *agl, *connect, *label_atom, log, max_depth, *num_mol_agl, num_of_inter, *stat, 
      *stat_all, *true_label_mol, *type_agl, type_inter, quiet;
  atom_info *_atom_info;
  system_info _system_info;
  
/* input                  mask of trajectory files
 * logfile                log file name
 * output                 output file name
 * 
 * crit                   massive of criteria
 * 
 * agl                    massive of agglomerates
 * connect                connectivity graph for all molecules
 * label_atom             massive of atom types for interactions
 * log                    status of log-mode
 * max_depth              maximum depth for check cycles in graph analyze
 * num_mol_agl            massive of number of molecules in agglomerates
 * num_of_inter           number of different interactions
 * stat                   massive of statistic
 * stat_all               massive of summary statistic
 * true_label_mol         massive of true numbers of molecule for atoms
 * type_agl               massive of number of agglomerate types
 * type_inter             number of atoms for interactions
 * quiet                  status of quiet-mode
 * 
 * _atom_info             atom information structure
 * _system_info           system information structure
 */
  
  set_defaults (&_system_info, input, &log, &max_depth, &num_of_inter, output, 
                &type_inter, &quiet);
  
// reading number of interactions
  for (i=1; i<argc; i++)
    if ((argv[i][0] == '-') && (argv[i][1] == 'r') && (argv[i][2] == '\0'))
      num_of_inter++;
  if (num_of_inter > 0)
  {
    crit = (float *) malloc ( 16 * num_of_inter * sizeof (float));
    if (crit == NULL)
      return 3;
    for (i=0; i<16*num_of_inter; i++)
      crit[i] = 0.0;
    num_of_inter = 0;
  }

// reading arguments
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h') && (argv[i][2] == '\0'))
    {
      sprintf (tmp_str, "                                     mm_statgen\n");
      sprintf (tmp_str, "%sProgram for analyze molecular dynamic trajectories\n", tmp_str);
      sprintf (tmp_str, "%sVersion : %s                                               License : Beerware\n", tmp_str, PROJ_VERSION);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%smm_statgen -i INPUT -s FIRST,LAST -c X,Y,Z -a ... -r ... -o OUTPUT [ -g DEPTH ]\n", tmp_str);
      sprintf (tmp_str, "%s                                                   [ -l LOGFILE ] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - mask of input files\n", tmp_str);
      sprintf (tmp_str, "%s  -s          - trajectory steps (integer)\n", tmp_str);
      sprintf (tmp_str, "%s  -c          - cell size (float), A\n", tmp_str);
      sprintf (tmp_str, "%s  -a          - atom types (integer). Format: 'ATOM1' or 'ATOM1,ATOM2' or etc\n", tmp_str);
      sprintf (tmp_str, "%s  -r          - criteria (float), A. Format: '0-0:2.4,0-1:3.0' means 0-0\n", tmp_str);
      sprintf (tmp_str, "%s                interaction (<2.4 A) and 0-1 (<3.0) are needed. This flag can be\n", tmp_str);
      sprintf (tmp_str, "%s                used multiple times\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - output file name\n", tmp_str);
      sprintf (tmp_str, "%s  -g          - check graph isomorphism. DEPTH (integet) is max depth for check\n", tmp_str);
      sprintf (tmp_str, "%s                cycles (>= 3)\n", tmp_str);
      sprintf (tmp_str, "%s  -l          - log enable\n", tmp_str);
      sprintf (tmp_str, "%s  -q          - quiet enable\n", tmp_str);
      sprintf (tmp_str, "%s  -h          - show this help and exit\n", tmp_str);
      fputs (tmp_str, stdout);
      return 0;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'i') && (argv[i][2] == '\0'))
// mask of input files
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
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a') && (argv[i][2] == '\0'))
// atom types
    {
      type_inter = 1;
      for (j=0; j<strlen(argv[i+1]); j++)
        if (argv[i+1][j] == ',')
          type_inter++;
      
      label_atom = (int *) malloc (type_inter * sizeof (int));
      if (label_atom == NULL)
        return 1;
      switch (type_inter)
      {
        case 1:
          sscanf (argv[i+1], "%i", &label_atom[0]);
          break;
        case 2:
          sscanf (argv[i+1], "%i,%i", &label_atom[0], &label_atom[1]);
          break;
        case 3:
          sscanf (argv[i+1], "%i,%i,%i", &label_atom[0], &label_atom[1], &label_atom[2]);
          break;
        case 4:
          sscanf (argv[i+1], "%i,%i,%i,%i", &label_atom[0], &label_atom[1], &label_atom[2], &label_atom[3]);
          break;
      }
      
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'r') && (argv[i][2] == '\0'))
// criteria
    {
      index = 0;
      sscanf (&argv[i+1][index], "%i-%i:%f%s", &label[0], &label[1], &label_fl, tmp_str);
      crit[16*num_of_inter+4*label[0]+label[1]] = label_fl;
      crit[16*num_of_inter+4*label[1]+label[0]] = label_fl;
      for (j=index; j<strlen(argv[i+1]); j++)
        if (argv[i+1][j] == ',')
        {
          index = j+1;
          sscanf (&argv[i+1][index], "%i-%i:%f%s", &label[0], &label[1], &label_fl, tmp_str);
          crit[16*num_of_inter+4*label[0]+label[1]] = label_fl;
          crit[16*num_of_inter+4*label[1]+label[0]] = label_fl;
        }
      
      num_of_inter++;
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o') && (argv[i][2] == '\0'))
// output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'g') && (argv[i][2] == '\0'))
// graph isomorphism scan
    {
      sscanf (argv[i+1], "%i", &max_depth);
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
  
// error checking
  error = error_checking (_system_info, input, max_depth, num_of_inter, output, 
                          type_inter);
  if (error != 0)
  {
    print_message (quiet, stderr, log, f_log, 17, argv[0]);
    return 1;
  }
  
  print_message (quiet, stdout, log, f_log, 2, argv[0]);
  
// processing
// initial variables
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
  true_label_mol = (int *) malloc (_system_info.num_atoms * sizeof (int));
  type_agl = (int *) malloc ((max_depth + 2) * sizeof (int));
// temporary declaration of variables
  agl = (int *) malloc (2 * 2 * sizeof (int));
  connect = (int *) malloc (2 * 2 * sizeof (int));
  num_mol_agl = (int *) malloc (2 * sizeof (int));
  stat = (int *) malloc (2 * sizeof (int));
  stat_all = (int *) malloc (2 * sizeof (int));
// error checking
  if ((_atom_info == NULL) || 
     (true_label_mol == NULL) || 
     (type_agl == NULL) || 
     (agl == NULL) || 
     (connect == NULL) || 
     (num_mol_agl == NULL) || 
     (stat == NULL) || 
     (stat_all == NULL))
  {
    print_message (quiet, stderr, log, f_log, 19, argv[0]);
    return 3;
  }
// set type_agl to zero
  for (i=0; i<max_depth+2; i++)
    type_agl[i] = 0;
  sprintf (tmp_str, "%6cOutput file: '%s';\n%6cLog: %i;\n%6cQuiet: %i;\n\
%6cMask: %s;\n%6cFirst step: %i;\n%6cLast step: %i;\n%6cCell size: %.4f, %.4f, %.4f;\n\
%6cSelect atoms: %i", ' ', output, ' ', log, ' ', quiet, ' ', input, ' ', _system_info.from, 
' ' , _system_info.to, ' ', _system_info.cell[0], _system_info.cell[1], _system_info.cell[2], 
' ' , label_atom[0]);
  for (i=1; i<type_inter; i++)
    sprintf (tmp_str, "%s,%i", tmp_str, label_atom[i]);
  sprintf (tmp_str, "%s;\n", tmp_str);
  for (i=0; i<num_of_inter; i++)
  {
    sprintf (tmp_str, "%s%6cInteraction: ", tmp_str, ' ');
    for (j=0; j<16; j++)
      if ((crit[16*i+j] != 0.0) && 
        ((j != 4) && (j != 8) && (j != 9) && (j != 12) && (j != 13) && (j != 14)))
        sprintf (tmp_str, "%s%i-%i:%4.2f,", tmp_str, j/4, j%4, crit[16*i+j]);
    sprintf (tmp_str, "%s;\n", tmp_str);
  }
  sprintf (tmp_str, "%s%6cIsomorphism check: %i\n", tmp_str, ' ', max_depth);
  print_message (quiet, stdout, log, f_log, 5, tmp_str);
  
// head
  printing_head (output, log, quiet, input, _system_info, type_inter, label_atom, 
                 num_of_inter, crit, max_depth);
  
// main cycle
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
  for (i=_system_info.from; i<_system_info.to+1; i++)
  {
// reading coordinates
    sprintf (filename, "%s.%03i", input, i);
    print_message (quiet, stdout, log, f_log, 7, filename);
    error = reading_coords (0, filename, type_inter, label_atom, &_system_info, 
                            true_label_mol, _atom_info);
    if (error == 0)
    {
      sprintf (tmp_str, "%6cNumber of molecules: %i; %6cNumber of atoms: %i\n", 
               ' ', _system_info.num_mol, ' ', _system_info.num_atoms);
      print_message (quiet, stdout, log, f_log, 8, tmp_str);
    }
    
// resize dynamic arrays
    agl = (int *) realloc (agl, _system_info.num_mol * _system_info.num_mol * sizeof (int));
    connect = (int *) realloc (connect, _system_info.num_mol * _system_info.num_mol * sizeof (int));
    num_mol_agl = (int *) realloc (num_mol_agl, _system_info.num_mol * sizeof (int));
    stat = (int *) realloc (stat, _system_info.num_mol * sizeof (int));
    if (i == _system_info.from)
    {
      stat_all = (int *) realloc (stat_all, _system_info.num_mol * sizeof (int));
      for (j=0; j<_system_info.num_mol; j++)
        stat_all[j] = 0;
    }
// error checking
    if ((agl == NULL) || 
       (connect == NULL) || 
       (num_mol_agl == NULL) || 
       (stat == NULL) || 
       (stat_all == NULL))
    {
      print_message (quiet, stderr, log, f_log, 19, argv[0]);
      return 3;
    }
    print_message (quiet, stdout, log, f_log, 9, argv[0]);
    
// analyze
    if (error == 0)
    {
      error = 1;
      error = create_matrix (_system_info, _atom_info, num_of_inter, crit, connect);
    }
    if (error == 0)
    {
      print_message (quiet, stdout, log, f_log, 10, argv[0]);
      error = 1;
      error = proc_matrix (_system_info, connect, num_mol_agl, agl, stat, stat_all);
    }
    if (error == 0)
    {
      print_message (quiet, stdout, log, f_log, 11, argv[0]);
      error = printing_agl (filename, output, connect, _system_info, true_label_mol, 
                            num_mol_agl, agl, stat, max_depth, type_agl);
    }
    if (error == 0)
      print_message (quiet, stdout, log, f_log, 12, output);
  }
  
  print_message (quiet, stdout, log, f_log, 13, argv[0]);
  print_message (quiet, stdout, log, f_log, 14, output);
// tail
  summary_statistic (output, _system_info, max_depth, type_agl, stat_all);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
// free memory
  free (_atom_info);
  free (agl);
  free (connect);
  free (crit);
  free (num_mol_agl);
  free (stat);
  free (stat_all);
  free (true_label_mol);
  free (type_agl);
  
  print_message (quiet, stdout, log, f_log, 16, argv[0]);
  
  if (log == 1)
    fclose (f_log);
  return 0;
}
