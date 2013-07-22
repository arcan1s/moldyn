#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "add_main.h"
#include "coords.h"
#include "int2char.h"
#include "messages.h"
#include "stat_print.h"
#include "stat_select.h"
#include "stat_sort.h"
#include "summary_stat.h"


int main (int argc, char *argv[])
{
  char filename[256], tmp_str[2048];
  int error, i, index, j, k, label[2];
  float label_fl;
  FILE *f_inp, *f_log;
  
  char input[256], logfile[256], output[256];
  float cell[3], *coords, *crit;
  int *agl, *connect, from, *label_atom, *label_mol, log, max_depth, num_atoms, 
      num_mol, *num_mol_agl, num_of_inter, *stat, *stat_all, step, to, 
      *true_label_mol, *type_agl, *type_atoms, type_inter, quiet;
/* input            - mask of input files
 * logfile          - log file name
 * output           - output file name
 * 
 * cell             - cell dimension
 * coords           - massive of coordinates
 * crit             - massive of criteria
 * 
 * agl              - massive of aglomerates
 * connect          - connectivity graph for all molecules
 * from             - start point
 * label_atom       - types of atom for interaction
 * label_mol        - massive of numbers of molecule for atoms
 * log              - status of log-mode
 * max_depth        - max depth for check cycles in graph analyze
 * num_atoms        - number of atoms for writing coordinates
 * num_mol          - number of molecules for writing coordinates
 * num_mol_agl      - massive of numbers of molecule in aglomerates
 * num_of_inter     - number of different interactions
 * stat             - massive of statistics
 * stat_all         - massive of summary statistics
 * step             - $(to - from + 1)
 * to               - finish point
 * true_label_mol   - massive of true numbers of molecule for atoms
 * type_agl         - massive of numbers of aglomerate types
 * type_atoms       - massive of atom types for atoms
 * type_inter       - type interaction (number of molecules for interaction)
 * quiet            - status of quiet-mode
 */
  
  set_defaults (cell, &from, input, &log, &max_depth, &num_of_inter, output, &to, 
                &type_inter, &quiet);
  
//   reading number of interactions
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

//   reading arguments
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'h'))
    {
      sprintf (tmp_str, "                                        statgen\n");
      sprintf (tmp_str, "%sProgram for analyze molecular dynamic trajectories\n", tmp_str);
      sprintf (tmp_str, "%sVersion : 1.0.0                                                    License : GPL\n", tmp_str);
      sprintf (tmp_str, "%s                                                    Evgeniy Alekseev aka arcanis\n", tmp_str);
      sprintf (tmp_str, "%s                                                    E-mail : esalexeev@gmail.com\n\n", tmp_str);
      sprintf (tmp_str, "%sUsage:\n", tmp_str);
      sprintf (tmp_str, "%sstatgen -i INPUT -s FIRST,LAST -c X,Y,Z -a ... -r ... -o OUTPUT [ -g DEPTH ] [ -l LOGFILE ] [ -q ] [ -h ]\n\n", tmp_str);
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
//       mask of input files
    {
      strcpy (input, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 's'))
//       steps
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
//       cell size
    {
      sscanf (argv[i+1], "%f,%f,%f", &cell[0], &cell[1], &cell[2]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'a'))
//       atom types
    {
      type_inter = 1;
      for (j=0; j<strlen(argv[i+1]); j++)
        if (argv[i+1][j] == ',')
          type_inter++;
      
      label_atom = (int *) malloc (type_inter * sizeof (int));
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
//       criteria
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
//       output file
    {
      strcpy (output, argv[i+1]);
      i++;
    }
    else if ((argv[i][0] == '-') && (argv[i][1] == 'g'))
//       graph isomorphism scan
    {
      sscanf (argv[i+1], "%i", &max_depth);
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
  
  if (quiet != 1)
  {
    message (0, 0, argv[0], stdout);
    message (0, 1, argv[0], stdout);
  }
  if (log == 1)
  {
    message (1, 0, argv[0], f_log);
    message (1, 1, argv[0], f_log);
  }
  
  //   error checking
  error = error_checking (cell, from, input, max_depth, num_of_inter, output, to, 
                          type_inter);
  if (error != 0)
  {
    sprintf (tmp_str, "Something wrong (error code: %i)!\nSee 'statgen -h' for more details\n", error);
    fputs (tmp_str, stderr);
    if (log == 1)
      fputs (tmp_str, f_log);
    return 1;
  }
  
  if (quiet != 1)
    message (0, 2, argv[0], stdout);
  if (log == 1)
    message (1, 2, argv[0], f_log);
  
//   processing
//   initial variables
  k = strlen (input);
  strcpy (filename, input);
  filename[k] = '.';
  filename[k+1] = conv (from, 3);
  filename[k+2] = conv (from, 2);
  filename[k+3] = conv (from, 1);
  filename[k+4] = '\0';
  if (quiet != 1)
    message (0, 3, filename, stdout);
  if (log == 1)
    message (1, 3, filename, f_log);
  f_inp = fopen (filename, "r");
  if (f_inp == NULL)
  {
    sprintf (tmp_str, "\nFile '%s' not found\nError", filename);
    fputs (tmp_str, stderr);
    if (log == 1)
      fputs (tmp_str, f_log);
    return 1;
  }
  fscanf (f_inp, "%i", &num_atoms);
  fclose (f_inp);
  coords = (float *) malloc (3 * 8 * num_atoms * sizeof (float));
  label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  true_label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  type_agl = (int *) malloc ((max_depth + 2) * sizeof (int));
  type_atoms = (int *) malloc (8 * num_atoms * sizeof (int));
//   temporary declaration of variables
  agl = (int *) malloc (2 * 2 * sizeof (int));
  connect = (int *) malloc (2 * 2 * sizeof (int));
  num_mol_agl = (int *) malloc (2 * sizeof (int));
  stat = (int *) malloc (2 * sizeof (int));
  stat_all = (int *) malloc (2 * sizeof (int));
//   error checking
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
    sprintf (tmp_str, "\nMemory error (error code: 17)\n");
    fputs (tmp_str, stderr);
    if (log == 1)
      fputs (tmp_str, f_log);
    return 17;
  }
//   set type_agl to zero
  for (i=0; i<max_depth+2; i++)
    type_agl[i] = 0;
  if (quiet != 1)
  {
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
    message (0, 5, tmp_str, stdout);
  }
  if (log == 1)
  {
    sprintf (tmp_str, "%34cOutput file: '%s';\n%34cLog: %i;\n%34cQuiet: %i;\n\
%34cMask: %s;\n%34cFirst step: %i;\n%34cLast step: %i;\n%34cCell size: %.4f, %.4f, %.4f;\n\
%34cSelect atoms: %i", ' ', output, ' ', log, ' ', quiet, ' ', input, ' ', from, 
' ' , to, ' ', cell[0], cell[1], cell[2], ' ' , label_atom[0]);
    for (i=1; i<type_inter; i++)
      sprintf (tmp_str, "%s,%i", tmp_str, label_atom[i]);
    sprintf (tmp_str, "%s;\n", tmp_str);
    for (i=0; i<num_of_inter; i++)
    {
      sprintf (tmp_str, "%s%34cInteraction: ", tmp_str, ' ');
      for (j=0; j<16; j++)
        if ((crit[16*i+j] != 0.0) && 
          ((j != 4) && (j != 8) && (j != 9) && (j != 12) && (j != 13) && (j != 14)))
          sprintf (tmp_str, "%s%i-%i:%4.2f,", tmp_str, j/4, j%4, crit[16*i+j]);
      sprintf (tmp_str, "%s;\n", tmp_str);
    }
    sprintf (tmp_str, "%s%34cIsomorphism check: %i\n", tmp_str, ' ', max_depth);
    message (1, 5, tmp_str, f_log);
  }
  
//   head
  printing_head (output, log, quiet, input, from, to, cell, type_inter, label_atom, 
                 num_of_inter, crit, max_depth);
  
//   main cycle
  if (quiet != 1)
    message (0, 6, argv[0], stdout);
  if (log == 1)
    message (1, 6, argv[0], f_log);
  for (i=from; i<to+1; i++)
  {
//     reading coordinates
    filename[k+1] = conv (i, 3);
    filename[k+2] = conv (i, 2);
    filename[k+3] = conv (i, 1);
    filename[k+4] = '\0';
    if (quiet != 1)
      message (0, 7, filename, stdout);
    if (log == 1)
      message (1, 7, filename, f_log);
    error = reading_coords (filename, type_inter, label_atom, cell, &num_mol, 
                            &num_atoms, true_label_mol, label_mol, type_atoms, coords);
    if (error != 1)
    {
      if (quiet != 1)
      {
        sprintf (tmp_str, "%6cNumber of molecules: %i\n%6cNumber of atoms: %i\n", 
                 ' ', num_mol, ' ', num_atoms);
        message (0, 8, tmp_str, stdout);
      }
      if (log == 1)
      {
        sprintf (tmp_str, "%6cNumber of molecules: %i\n%34cNumber of atoms: %i\n", 
                 ' ', num_mol, ' ', num_atoms);
        message (1, 8, tmp_str, f_log);
      }
    }
    
//     resize dynamic arrays
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
//     error checking
    if ((agl == NULL) || 
      (connect == NULL) || 
      (num_mol_agl == NULL) || 
      (stat == NULL) || 
      (stat_all == NULL))
    {
      sprintf (tmp_str, "\nMemory error (error code: 18)\n");
      fputs (tmp_str, stderr);
      if (log == 1)
        fputs (tmp_str, f_log);
      return 18;
    }
    if (quiet != 1)
      message (0, 9, argv[0], stdout);
    if (log == 1)
      message (1, 9, argv[0], f_log);
    
//     analyze
    if (error == 0)
    {
      error = 1;
      error = create_matrix (num_mol, num_atoms, label_mol, type_atoms, coords, 
                            num_of_inter, crit, connect);
      if (error == 0)
      {
        if (quiet != 1)
          message (0, 10, argv[0], stdout);
        if (log == 1)
          message (1, 10, argv[0], f_log);
        error = 1;
        error = proc_matrix (num_mol, connect, num_mol_agl, agl, stat, stat_all);
        if (error == 0)
        {
          if (quiet != 1)
            message (0, 11, argv[0], stdout);
          if (log == 1)
            message (1, 11, argv[0], f_log);
          error = printing_agl (filename, output, connect, num_mol, true_label_mol, 
                                num_mol_agl, agl, stat, max_depth, type_agl);
          if (error == 0)
          {
            if (quiet != 1)
              message (0, 12, output, stdout);
            if (log == 1)
              message (1, 12, output, f_log);
          }
        }
      }
    }
  }
  
  if (quiet != 1)
  {
    message (0, 13, argv[0], stdout);
    message (0, 14, output, stdout);
  }
  if (log == 1)
  {
    message (1, 13, argv[0], f_log);
    message (1, 14, output, f_log);
  }
//     tail
  summary_statistic (output, step, num_mol, max_depth, type_agl, stat_all);
  
  if (quiet != 1)
    message (0, 15, argv[0], stdout);
  if (log == 1)
    message (1, 15, argv[0], f_log);
//   free memory
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
  
  if (quiet != 1)
    message (0, 16, argv[0], stdout);
  if (log == 1)
    message (1, 16, argv[0], f_log);
  
  if (log == 1)
    fclose (f_log);
  return 0;
}
