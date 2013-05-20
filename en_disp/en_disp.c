/*                                    en_disp
 * Version:                                                                 1.0                   
 * License:                                                                 GPL
 * Author:                                          Evgeniy Alexeev aka arcanis
 * Email:                                                   esalexeev@gmail.com
 *
 * 'en_disp' calculate the energy difference between forms with different states 
 * of a salt bridge.
 *
 * Usage:            
 *                   en_disp -cc FILENAME -no FILENAME [ -ref REF_C-C REF_N-0 ] 
 *      [ -s NUM_OF_SIMULATION ] [ -p POINTS_IN_SIMULATION ] [ -t TEMPERATURE ] 
 *                                                       [ -d FILENAME ] [ -h ]
 *
 * Compile:
 *                                                 gcc en_disp.c -o en_disp -lm
 * Dependence:
 *      * gcc
 *      * libs: math.h, stdio.h, stdlib.h, string.h
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define new RAND_MAX - NOT long int
#ifdef RAND_MAX
#undef RAND_MAX
#define RAND_MAX 100000
#endif


double cc_ref, no_ref, temp;
double dist[50000][2];
int distrib_exists[50000], points, points_in_model, total_points;
/* cc_ref           - reference distance for C-C
 * dist             - distance between atoms
 * distrib_exists   - array of number of points when ionic lock exists
 * no_ref           - reference distance for N-O
 * points           - number of simulations
 * points_in_model  - number of points in single simulation
 * temp             - temperature
 * total_points     - trajectory length
 */


void analyze()
{
// function to analyze distributions
  double aver=0.0, disp=0.0, t_ratio;
  int i;
/* aver             - average energy
 * disp             - standard deviation
 * t_ratio          - ratio of t(exists) to t(broken)
 */

  for (i=0; i<points; i++)
  {
    t_ratio = points_in_model - distrib_exists[i];
    t_ratio = distrib_exists[i] / t_ratio;
    aver += log(t_ratio);
  }
  aver = -1.99 * temp * aver / points;
  
  for (i=0; i<points; i++)
  {
    disp += pow((-1.99 * temp * log(t_ratio) - aver), 2);
  }
  disp = sqrt(disp / (points - 1));
  
  printf ("Energy: %5.2f +- %4.2f ccal/mol\n", aver/1000, disp/1000);
}


void calc()
{
// function to calculate initial system energy
  double ener, t_ratio;
  int exists=0, i;
/* ener             - energy
 * t_rato           - ratio of t(exists) to t(broken)
 * exists           - time when ionic lock exists
 */

  for (i=0; i<total_points; i++)
    if ((dist[i][0] <= cc_ref) && (dist[i][1] <= no_ref))
      exists++;
  printf ("Ionic lock exists: %4i ns\n", exists);
  
  t_ratio = total_points - exists;
  t_ratio = exists / t_ratio;
  ener = -1.99 * temp * log(t_ratio);
  printf ("Initial trajectory energy: %5.2f ccal/mol\n", ener/1000);
}


void disp(int iter)
{
// function to create distributions
  int i=0, index;

  for (i=0; i<points_in_model; i++)
  {
    // max of index is ~(total_points-1)
    index = rand() % ((RAND_MAX % total_points)+1);
    if ((dist[index][0] <= cc_ref) && (dist[index][1] <= no_ref))
      distrib_exists[iter]++;
  }
}


void print_distr(char out_name[])
{
// function to print received simulations
  int i;
  FILE *out;

  out = fopen(out_name, "w+");
  for (i=0; i<points; i++)
    fprintf(out, "%i\n", distrib_exists[i]);
  fclose(out);
}


void reading(char inp_name[], int choice)
{
// function to read input data
// choice           - equal 0 if C-C or equal 1 if N-O
  int i=0;
  FILE *inp;

  inp = fopen(inp_name, "r+");
  if (inp == NULL)
  {
    printf ("File '%s' doesn't exists\nExiting\n", inp_name);
    exit(1);
  }
  
  while (!feof(inp))
  {
    fscanf (inp, "%lf", &dist[i][choice]);
    i++;
  }
  total_points = i;
  
  fclose(inp);
}


void zeroing()
{
// function to zeroing of variables
  int i;
  
  cc_ref = 9.0;
  no_ref = 3.0;
  temp = 313.0;
  points = 300;
  points_in_model = 250;
  for (i=0; i<50000; i++)
    distrib_exists[i] = 0;
}


int main(int argc, char *argv[])
{
  char distrib_out_name[256];
  int distrib_out=0, error_label=0, i;
  FILE *inp;
/* distrib_out      - equal 1 if print results or equal 1 if not
 * distrib_out_name - filename with results
 * error_label      - label for checking error in input files
 */

  printf ("Starting program '%s'\n", argv[0]);

  printf ("\n1) Zeroing");
  zeroing();
  printf ("%41s\n", "done\n");
    
  printf ("2) Reading arguments\n");
  if (argc == 1)
  {
    printf ("Arguments aren't set\nType 'en_disp -h' for help message\nExiting\n");
    return 1;
  }
  
  for (i=1; i<argc; i++)
  {
    if ((argv[i][0] == '-') && (argv[i][1] == 'c') && (argv[i][2] == 'c'))
    {
      printf ("Reading file '%s'\n", argv[i+1]);
      reading(argv[i+1], 0);
      error_label++;
      i++;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 'n') && (argv[i][2] == 'o'))
    {
      printf ("Reading file '%s'\n", argv[i+1]);
      reading(argv[i+1], 1);
      error_label++;
      i++;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 'r') && (argv[i][2] == 'e') && (argv[i][3] == 'f'))
    {
      cc_ref = atof(argv[i+1]);
      no_ref = atof(argv[i+2]);
      i += 2;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 's'))
    {
      points = atoi(argv[i+1]);
      i++;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 'p'))
    {
      points_in_model = atoi(argv[i+1]);
      i++;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 't'))
    {
      temp = atof(argv[i+1]);
      i++;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 'd'))
    {
      distrib_out = 1;
      strcpy(distrib_out_name, argv[i+1]);
      i++;
    }
    if ((argv[i][0] == '-') && (argv[i][1] == 'h'))
    {
      printf ("Usage: en_disp -cc FILENAME -no FILENAME [ -ref REF_C-C REF_N-0 ]\
 [ -s NUM_OF_SIMULATION ] [ -p POINTS_IN_SIMULATION ] [ -t TEMPERATURE ]\
 [ -d FILENAME ] [ -h ]\n\n");
      printf ("  -cc    - input file with C-C distance\n");
      printf ("  -no    - input file with N-O distance\n");
      printf ("  -ref   - reference distance, A. Default is 9.0 and 3.0 A\n");
      printf ("  -s     - number of simulation for distribution. Default is 300\n");
      printf ("  -p     - number of points in distribution simulation. Default is 250\n");
      printf ("  -t     - temperature, K. Default is 313 K\n");
      printf ("  -d     - print distribution in file %%FILENAME%%\n");
      printf ("  -h     - show this help and exit\n");
      return 0;
    }
  }
  
// error check
  if (error_label < 2)
  {
    printf ("Input files aren't set\nType 'en_disp -h' for help message\nExiting\n");
    return 1;
  }

  printf ("Parametrs:\n");
  printf ("  C-C reference, A                = %5.2f\n", cc_ref);
  printf ("  N-O reference, A                = %5.2f\n", no_ref);
  printf ("  Number of simulation            = %5i\n", points);
  printf ("  Number of points in simulation  = %5i\n", points_in_model);
  printf ("  Temperature, K                  = %5.1f\n", temp);
  
  printf ("%50s\n", "done");
  
  printf ("\n3) Calculating\n");
  calc();
  printf ("%50s\n", "done");
  
  printf ("\n4) Simulation");
  for (i=0; i<points; i++)
    disp(i);
  if (distrib_out == 1)
  {
    printf ("\nPrint distribution to file '%s'\n%50s\n", distrib_out_name, "done");
    print_distr(distrib_out_name);
  }
  else
    printf ("%37s\n", "done");
  
  printf ("\n5) Analyzing\n");
  analyze();
  printf ("%50s\n", "done");
  
  
  printf ("\nExiting without errors\n");
  return 0; 
}  
