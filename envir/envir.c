/*                               envir
 * Version:                                                                 1.0
 * License:                                                                 GPL
 * Author:                                          Evgeniy Alexeev aka arcanis
 * Email:                                                   esalexeev@gmail.com
 *
 * 'envir' is a program for search environment for chosen molecule by geometric 
 * criterion
 *
 * Usage: 
 *    envir -i FILENAME -o FILEMANE [ -n NUM_OF_MOLECULE ] [ -r RADIUS ] [ -h ]
 *
 * Compile:
 *                                                     gcc envir.c -o envir -lm
 * Dependence:
 *      * gcc
 *      * libs: stdio.h, stdlib.h, string.h, math.h
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


char atom_type[5000][30][2];
double centr_coord[5000][3], coord[5000][30][3], rad;
int at_in_mol[5000], mol, needed_mol[50], num_of_mol;
/* at_in_mol          - number of atoms in molecules
 * atom_type          - massive of atom names
 * centr_coord        - coordinates of molecule mass center
 * coord              - coordinates of atoms
 * mol                - number of molecule in system
 * needed_mol         - massive of mulecules found
 * num_of_mol         - number of molecule for search
 * rad                - geometric criterion
 */ 


void printing(char output_file[])
{
  int cur_mol=0, i, j=1;
  FILE *out;

  out = fopen (output_file, "w+");
  while (needed_mol[cur_mol] != 10000)
  {
    for (i=0; i<at_in_mol[needed_mol[cur_mol]]; i++)
    {
      fprintf(out, "ATOM  %5i %c%c MOL  %4i    %8.3f%8.3f%8.3f\n", j, atom_type[needed_mol[cur_mol]][i][0], \
          atom_type[needed_mol[cur_mol]][i][1], cur_mol+1, coord[needed_mol[cur_mol]][i][0], \
          coord[needed_mol[cur_mol]][i][1], coord[needed_mol[cur_mol]][i][2]);
      j++;
    }
    cur_mol++;
  }
  fclose (out);
}


void search()
{
  double r;
  int i, k=0;

  for (i=0; i<50; i++)
    needed_mol[i] = 10000;

  for (i=0; i<mol; i++)
  {
    r = sqrt(pow((centr_coord[i][0]-centr_coord[num_of_mol-1][0]), 2) + \
        pow((centr_coord[i][1]-centr_coord[num_of_mol-1][1]), 2) + \
        pow((centr_coord[i][2]-centr_coord[num_of_mol-1][2]), 2));
    if (r < rad)
    {
      needed_mol[k] = i;
      k++;
    }
  }
}


void set_center()
{
  int i, j, k;

  for (i=0; i<mol; i++)
    for (j=0; j<3; j++)
      centr_coord[i][j] = 0;

  for (i=0; i<mol; i++)
    for (j=0; j<at_in_mol[i]; j++)
      for (k=0; k<3; k++)
        centr_coord[i][k] += coord[i][j][k] / at_in_mol[i];
}


void reading(char input_file[])
{
  char tmp[256];
  int atom_num, cur_mol=0, i, summ;
  FILE *inp;

  inp = fopen (input_file, "r+");
  fscanf (inp, "%i", &summ);
  fgets (tmp, 256, inp);
  printf ("Atoms in system: %i\n", summ);
  for (i=0; i<summ; i++)
  {
    fgets (tmp, 256, inp);
    if (atoi(&tmp[53]) != mol+1)
    {
      at_in_mol[mol] = cur_mol;
      mol++;
      cur_mol = 0;
    }

    atom_type[mol][cur_mol][0] = tmp[7];
    atom_type[mol][cur_mol][1] = tmp[8];
    coord[mol][cur_mol][0] = atof(&tmp[10]);
    coord[mol][cur_mol][1] = atof(&tmp[22]);
    coord[mol][cur_mol][2] = atof(&tmp[34]);

    cur_mol++;
  }
  fclose (inp);
  mol++;
}


int main(int argc, char *argv[])
{
  char input_file[256], output_file[256];
  int error_label=0, i, j;
  FILE *f;

  printf ("Starting program '%s'\n", argv[0]);
  mol = 0;
  rad = 6.0;
  num_of_mol = 1;
  

  printf ("\n1) Reading arguments\n");
  if (argc == 1)
  {
    printf ("Arguments are not set\nType 'envir -h' for help message\nExiting\n");
    return 1;
  }
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'i'))
    {
      strcpy(input_file, argv[i+1]);
      f = fopen (argv[i+1], "r+");
      if (f == NULL)
      {
        printf ("File '%s' does not exist!\nExiting\n", argv[i+1]);
        return 1;
      }
      fclose(f);
      printf ("Set input file to '%s'\n", input_file);
      i++;
      error_label++;
    }

    if ((argv[i][0] == '-') && (argv[i][1] == 'o'))
    {
      strcpy(output_file, argv[i+1]);
      printf ("Set output file to '%s'\n", output_file);
      i++;
      error_label++;
    }

    if ((argv[i][0] == '-') && (argv[i][1] == 'n'))
    {
      num_of_mol = atoi(argv[i+1]);
      printf ("Set number of molecule to '%i'\n", num_of_mol);
      i++;
    }

    if ((argv[i][0] == '-') && (argv[i][1] == 'r'))
    {
      rad = atof(argv[i+1]);
      printf ("Set radius to '%lf' A\n", rad);
      i++;
    }

    if ((argv[i][0] == '-') && (argv[i][1] == 'h'))
    {
      printf ("Usage: envir -i FILENAME -o FILEMANE [ -n NUM_OF_MOLECULE ] [ -r RADIUS ] [ -h ]\n\n");
      printf ("  -i       - input file with coordinates\n");
      printf ("  -o       - output file with coordinates\n");
      printf ("  -n       - number of molecule for search\n");
      printf ("  -r       - radius of environment\n");
      printf ("  -h       - show this help and exit\n");
      return 0;
    }
  }

// error check
  if (error_label < 2)
  {
    printf ("Input files aren't set\nType 'en_disp -h' for help message\nExiting\n");
    return 1;
  }

  printf ("Reading file '%s'\n", input_file);
  reading (input_file);
  printf ("Set center of molecules\n");
  set_center ();
  printf ("Search environments\n");
  search (); 
  printf ("Printing\n");
  printing (output_file);
  printf ("Exiting without errors\n");

  return 0;
}
