/**
 * @file
 */
/**
 * @mainpage statgen 
 * @image latex ./logo.png
 *
 * @section intro_sec Introduction
 * 
 * <b>About this program</b>:
 * <ul>
 * <li>Program that analyzes molecular dynamic trajectories using topological analysis
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
 * statgen -i INPUT -s FIRST,LAST -c X,Y,Z -a ... -r ... -o OUTPUT [ -g DEPTH ] 
 *                                                 [ -l LOGFILE ] [ -q ] [ -h ]
 *
 * Parametrs:
 *    -i          - mask of input files
 *    -s          - trajectory steps (integer)
 *    -c          - cell size (float), A
 *    -a          - atom types (integer). Format: 'ATOM1' or 'ATOM1,ATOM2' or etc
 *    -r          - criteria (float), A. Format: '0-0:2.4,0-1:3.0' means 0-0-interaction
 *                  (<2.4 A) and 0-1 (<3.0) are needed. This flag can be used multiple times
 *    -o          - output file name
 *    -g          - check graph isomorphism. DEPTH is max depth for check cycles (>= 3)
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
#include <time.h>

#include "add_main.h"
#include "coords.h"
#include "messages.h"
#include "stat_print.h"
#include "stat_select.h"
#include "stat_sort.h"
#include "summary_stat.h"


/**
 * @fn main
 */
int main (int argc, char *argv[])
/**
 * @return 1              - error in error_checking
 * @return 2              - input file does not exist
 * @return 3              - memory error
 * @return 0              - exit without errors
 */
{
  char filename[256], tmp_str[2048];
  int error, i, index, j, label[2];
  float label_fl;
  FILE *f_inp, *f_log;
  
  char input[256], logfile[256], output[256];
  float cell[3], *coords, *crit;
  int *agl, *connect, from, *label_atom, *label_mol, log, max_depth, num_atoms, 
      num_mol, *num_mol_agl, num_of_inter, *stat, *stat_all, step, to, 
      *true_label_mol, *type_agl, *type_atoms, type_inter, quiet;
  
/* input                  mask of trajectory files
 * logfile                log file name
 * output                 output file name
 * 
 * cell                   massive of cell size
 * coords                 massive of coordinates
 * crit                   massive of criteria
 * 
 * agl                    massive of aglomerates
 * connect                connectivity graph for all molecules
 * from                   first trajectory step
 * label_atom             massive of atom types for interactions
 * label_mol              massive of numbers of molecule for atoms
 * log                    status of log-mode
 * max_depth              maximum depth for check cycles in graph analyze
 * num_atoms              number of atoms
 * num_mol                number of molecules
 * num_mol_agl            massive of number of molecules in aglomerates
 * num_of_inter           number of different interactions
 * stat                   massive of statistic
 * stat_all               massive of summary statistic
 * step                   $(to - from + 1)
 * to                     last trajectory step
 * true_label_mol         massive of true numbers of molecule for atoms
 * type_agl               massive of number of aglomerate types
 * type_atoms             massive of atom types
 * type_inter             number of atoms for interactions
 * quiet                  status of quiet-mode
 */
  
  set_defaults (cell, &from, input, &log, &max_depth, &num_of_inter, output, &to, 
                &type_inter, &quiet);
  
// reading number of interactions
  for (i=1; i<argc; i++)
    if ((argv[i][0] == '-') && (argv[i][1] == 'r'))
      num_of_inter++;
  if (num_of_inter > 0)
  {
    crit = (float *) malloc ( 16 * num_of_inter * sizeof (float));
    for (i=0; i<16*num_of_inter; i++)
      crit[i] = 0.0;
    num_of_inter = 0;
  }

// reading arguments
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h'))
    {
      sprintf (tmp_str, "                                        statgen\n");
      sprintf (tmp_str, "%sProgram for analyze molecular dynamic trajectories\n", tmp_str);
      sprintf (tmp_str, "%sVersion : 1.0.1                                                    License : GPL\n", tmp_str);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%sstatgen -i INPUT -s FIRST,LAST -c X,Y,Z -a ... -r ... -o OUTPUT [ -g DEPTH ]\n", tmp_str);
      sprintf (tmp_str, "%s                                                [ -l LOGFILE ] [ -q ] [ -h ]\n\n", tmp_str);
      sprintf (tmp_str, "%sParametrs:\n", tmp_str);
      sprintf (tmp_str, "%s  -i          - mask of input files\n", tmp_str);
      sprintf (tmp_str, "%s  -s          - trajectory steps (integer)\n", tmp_str);
      sprintf (tmp_str, "%s  -c          - cell size (float), A\n", tmp_str);
      sprintf (tmp_str, "%s  -a          - atom types (integer). Format: 'ATOM1' or 'ATOM1,ATOM2' or etc\n", tmp_str);
      sprintf (tmp_str, "%s  -r          - criteria (float), A. Format: '0-0:2.4,0-1:3.0' means 0-0-interaction\n", tmp_str);
      sprintf (tmp_str, "%s                (<2.4 A) and 0-1 (<3.0) are needed. This flag can be used multiple times\n", tmp_str);
      sprintf (tmp_str, "%s  -o          - output file name\n", tmp_str);
      sprintf (tmp_str, "%s  -g          - check graph isomorphism. DEPTH is max depth for check cycles (>= 3)\n", tmp_str);
      sprintf (tmp_str, "%s  -l          - log enable\n", tmp_str);
      sprintf (tmp_str, "%s  -q          - quiet enable\n", tmp_str);
      sprintf (tmp_str, "%s  -h          - show this help and exit\n", tmp_str);
      fputs (tmp_str, stdout);
      return 0;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'i'))
// mask of input files
    {
      strcpy (input, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 's'))
// steps
    {
      sscanf (argv[i+1], "%i,%i", &from, &to);
      if (from > to)
      {
        to += from;
        from = to - from;
        to -= from;
      }
      step = to - from + 1;
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'c'))
// cell size
    {
      sscanf (argv[i+1], "%f,%f,%f", &cell[0], &cell[1], &cell[2]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a'))
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
    else if ((argv[i][0] == '-') && (argv[i][1] == 'r'))
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
    else if ((argv[i][0] == '-') && (argv[i][1] == 'o'))
// output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'g'))
// graph isomorphism scan
    {
      sscanf (argv[i+1], "%i", &max_depth);
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
  
// error checking
  error = error_checking (cell, from, input, max_depth, num_of_inter, output, to, 
                          type_inter);
  if (error != 0)
  {
    print_message (quiet, stderr, log, f_log, 17, argv[0]);
    return 1;
  }
  
  print_message (quiet, stdout, log, f_log, 2, argv[0]);
  
// processing
// initial variables
  sprintf (filename, "%s.%03i", input, from);
  print_message (quiet, stdout, log, f_log, 3, filename);
  f_inp = fopen (filename, "r");
  if (f_inp == NULL)
  {
    print_message (quiet, stderr, log, f_log, 18, filename);
    return 2;
  }
  fscanf (f_inp, "%i", &num_atoms);
  fclose (f_inp);
  coords = (float *) malloc (3 * 8 * num_atoms * sizeof (float));
  label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  true_label_mol = (int *) malloc (num_atoms * sizeof (int));
  type_agl = (int *) malloc ((max_depth + 2) * sizeof (int));
  type_atoms = (int *) malloc (8 * num_atoms * sizeof (int));
// temporary declaration of variables
  agl = (int *) malloc (2 * 2 * sizeof (int));
  connect = (int *) malloc (2 * 2 * sizeof (int));
  num_mol_agl = (int *) malloc (2 * sizeof (int));
  stat = (int *) malloc (2 * sizeof (int));
  stat_all = (int *) malloc (2 * sizeof (int));
// error checking
  if ((coords == NULL) || 
     (label_mol == NULL) || 
     (true_label_mol == NULL) || 
     (type_agl == NULL) || 
     (type_atoms == NULL) || 
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
%6cSelect atoms: %i", ' ', output, ' ', log, ' ', quiet, ' ', input, ' ', from, 
' ' , to, ' ', cell[0], cell[1], cell[2], ' ' , label_atom[0]);
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
  printing_head (output, log, quiet, input, from, to, cell, type_inter, label_atom, 
                 num_of_inter, crit, max_depth);
  
// main cycle
  print_message (quiet, stdout, log, f_log, 6, argv[0]);
  for (i=from; i<to+1; i++)
  {
// reading coordinates
    sprintf (filename, "%s.%03i", input, i);
    print_message (quiet, stdout, log, f_log, 7, filename);
    error = reading_coords (0, filename, type_inter, label_atom, cell, &num_mol, 
                            &num_atoms, true_label_mol, label_mol, type_atoms, 
                            coords, tmp_str);
    if (error == 0)
    {
      sprintf (tmp_str, "%6cNumber of molecules: %i; %6cNumber of atoms: %i\n", 
               ' ', num_mol, ' ', num_atoms);
      print_message (quiet, stdout, log, f_log, 8, tmp_str);
    }
    
// resize dynamic arrays
    agl = (int *) realloc (agl, num_mol * num_mol * sizeof (int));
    connect = (int *) realloc (connect, num_mol * num_mol * sizeof (int));
    num_mol_agl = (int *) realloc (num_mol_agl, num_mol * sizeof (int));
    stat = (int *) realloc (stat, num_mol * sizeof (int));
    if (i == from)
    {
      stat_all = (int *) realloc (stat_all, num_mol * sizeof (int));
      for (j=0; j<num_mol; j++)
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
      error = create_matrix (num_mol, num_atoms, label_mol, type_atoms, coords, 
                             num_of_inter, crit, connect);
      if (error == 0)
      {
        print_message (quiet, stdout, log, f_log, 10, argv[0]);
        error = 1;
        error = proc_matrix (num_mol, connect, num_mol_agl, agl, stat, stat_all);
        if (error == 0)
        {
          print_message (quiet, stdout, log, f_log, 11, argv[0]);
          error = printing_agl (filename, output, connect, num_mol, true_label_mol, 
                                num_mol_agl, agl, stat, max_depth, type_agl);
          if (error == 0)
            print_message (quiet, stdout, log, f_log, 12, output);
        }
      }
    }
  }
  
  print_message (quiet, stdout, log, f_log, 13, argv[0]);
  print_message (quiet, stdout, log, f_log, 14, output);
// tail
  summary_statistic (output, step, num_mol, max_depth, type_agl, stat_all);
  
  print_message (quiet, stdout, log, f_log, 15, argv[0]);
// free memory
  free (agl);
  free (connect);
  free (coords);
  free (crit);
  free (label_mol);
  free (num_mol_agl);
  free (stat);
  free (stat_all);
  free (true_label_mol);
  free (type_agl);
  free (type_atoms);
  
  print_message (quiet, stdout, log, f_log, 16, argv[0]);
  
  if (log == 1)
    fclose (f_log);
  return 0;
}
