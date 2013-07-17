#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// prototypes
char conv (int, int);
int create_matrix (int, int, const int *, const int *, const float *, int, 
                   const float *, int *);
int printing_agl (char *, char *, const int *, int, const int *, const int *, 
                  const int *, const int *, int *);
int proc_matrix (int, const int *, int *, int *, int *, int *);
int reading_coords (char *, int, const int *, const float *, int *, int *, 
                    int *, int *, int *, float *);
int summary_statistic (char *, int, int, const int *, const int *);


int error_checking (const float *cell, int from, const char *input, 
                    int num_of_inter, const char *output, int to, int type_inter)
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
  
  return 0;
}


int printing_head (const char *output, int log, int quiet, const char *input, 
                   int from, int to, const float *cell, int type_inter, 
                   const int *label_atom, int num_of_inter, const float *crit)
{
  int i;
  FILE *f_out;
  
  f_out = fopen (output, "w");
  fprintf (f_out, "statgen ::: V.1.0.0 ::: 2013-07-17\n\n");
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
    fprintf (f_out, "0-0:%4.2f,0-1:%4.2f,1-1:%4.2f,", crit[16*i+0], crit[16*i+1], 
             crit[16*i+5]);
    fprintf (f_out, "0-2:%4.2f,1-2:%4.2f,2-2:%4.2f,", crit[16*i+2], crit[16*i+6], 
             crit[16*i+10]);
    fprintf (f_out, "0-3:%4.2f,1-3:%4.2f,2-3:%4.2f,3-3:%4.2f\n", crit[16*i+3], 
             crit[16*i+7], crit[16*i+11], crit[16*i+15]);
  }
    
  fprintf (f_out, "END\n\n");
  fclose (f_out);
  
  return 0;
}


int set_defaults (float *cell, int *from, char *input, int *log, int *num_of_inter, 
                  char *output, int *to, int *type_agl, int *type_inter, int *quiet)
{
  int i;
  
  for (i=0; i<3; i++)
    cell[i] = 0.0;
  *from = -1;
  input[0] = '#';
  *log = 0;
  *num_of_inter = 0;
  output[0] = '#';
  *to = -1;
  type_agl[0] = 0;
  type_agl[1] = 0;
  *type_inter = 0;
  *quiet = 0;
  
  return 0;
}


int main (int argc, char *argv[])
{
  char filename[256], tmp_str[256];
  int error, i, index, j, k, label[2];
  float label_fl;
  FILE *f_inp;
  
  char input[256], logfile[256], output[256];
  float cell[3], *coords, *crit;
  int *agl, *connect, from, *label_atom, *label_mol, log, num_atoms, num_mol, 
      *num_mol_agl, num_of_inter, *stat, *stat_all, step, to, *true_label_mol, 
      type_agl[2], *type_atoms, type_inter, quiet;
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
  
  set_defaults (cell, &from, input, &log, &num_of_inter, output, &to, type_agl, 
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
      printf ("                                        statgen\n");
      printf ("Program for analyze molecular dynamic trajectories\n");
      printf ("Version : 1.0.0                                                    License : GPL\n");
      printf ("                                                    Alekseev Evgeniy aka arcanis\n");
      printf ("                                                    E-mail : esalexeev@gmail.com\n\n");
      printf ("Usage:\n");
      printf ("statgen -i INPUT -s FIRST,LAST -c X,Y,Z -a ... -r ... -o OUTPUT [ -l LOGFILE ] [ -q ] [ -h ]\n\n");
      printf ("Parametrs:\n");
      printf ("  -i          - mask of input files\n");
      printf ("  -s          - trajectory steps (integer)\n");
      printf ("  -c          - cell size (float), A\n");
      printf ("  -a          - atom types (integer). Format: 'ATOM1' or 'ATOM1,ATOM2' or etc\n");
      printf ("  -r          - criteria (float), A. Format: '0-0:2.4,0-1:3.0' means 0-0-interaction\n");
      printf ("                (<2.4 A) and 0-1 (<3.0) are needed. This flag can be used multiple times\n");
      printf ("  -o          - output file name\n");
      printf ("  -l          - log enable\n");
      printf ("  -q          - quiet enable\n");
      printf ("  -h          - show this help and exit\n");
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
  
//   error checking
  error = error_checking (cell, from, input, num_of_inter, output, to, type_inter);
  if (error > 1)
  {
    printf ("Something wrong (error code: %i)!\nSee 'statgen -h' for more details\n", error);
    return 1;
  }
  
//   processing
//   initial variables
  k = strlen (input);
  strcpy (filename, input);
  filename[k] = '.';
  filename[k+1] = conv (from, 3);
  filename[k+2] = conv (from, 2);
  filename[k+3] = conv (from, 1);
  filename[k+4] = '\0';
  f_inp = fopen (filename, "r");
  if (f_inp == NULL)
    return 1;
  fscanf (f_inp, "%i", &num_atoms);
  fclose (f_inp);
  coords = (float *) malloc (3 * 8 * num_atoms * sizeof (float));
  label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  true_label_mol = (int *) malloc (8 * num_atoms * sizeof (int));
  type_atoms = (int *) malloc (8 * num_atoms * sizeof (int));
  
//   head
  printing_head (output, log, quiet, input, from, to, cell, type_inter, label_atom, 
                 num_of_inter, crit);
  
//   main cycle
  for (i=from; i<to+1; i++)
  {
//     reading coordinates
    filename[k+1] = conv (i, 3);
    filename[k+2] = conv (i, 2);
    filename[k+3] = conv (i, 1);
    filename[k+4] = '\0';
    error = reading_coords (filename, type_inter, label_atom, cell, &num_mol, 
                            &num_atoms, true_label_mol, label_mol, type_atoms, coords);
    
//     initializate variables
    if (i == from)
    {
      agl = (int *) malloc (num_mol * num_mol * sizeof (int));
      connect = (int *) malloc (num_mol * num_mol * sizeof (int));
      num_mol_agl = (int *) malloc (num_mol * sizeof (int));
      stat = (int *) malloc (num_mol * sizeof (int));
      stat_all = (int *) malloc (num_mol * sizeof (int));
    }
    
    for (j=0; j<num_mol; j++)
    {
      num_mol_agl[j] = j;
      printf ("%i - %i\n", j, num_mol_agl[j]);
    }
    
//     analyze
    error = 1;
    error = create_matrix (num_mol, num_atoms, label_mol, type_atoms, coords, 
                          num_of_inter, crit, connect);
    if (error == 0)
    {
      error = 1;
      error = proc_matrix (num_mol, connect, num_mol_agl, agl, stat, stat_all);
      if (error == 0)
        printing_agl (filename, output, connect, num_mol, true_label_mol, 
                      num_mol_agl, agl, stat, type_agl);
    }
    
  }
  num_mol_agl[num_mol-1] = num_mol;
  printf ("%i - %i\n", num_mol-1, num_mol_agl[num_mol]);

//     tail
  summary_statistic (output, step, num_mol, type_agl, stat_all);
  printf ("%i - %i\n", num_mol-1, num_mol_agl[num_mol]);

//   free memory
  free (agl);
  free (connect);
  free (coords);
  free (crit);
  free (label_mol);
//   memory crash here
  free(num_mol_agl);
//   free (stat);
//   free (stat_all);
  free (true_label_mol);
  free (type_atoms);
  
  return 0;
}
