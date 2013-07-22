/* Library for summary statistic
 * Usage:
 *            summary_statistic (filename, number_of_step, number_of_molecules, 
 *                             max_depth, type_of_aglomerate, summary_statistic)
 */

#include <stdio.h>


int summary_statistic (const char *filename, const int step, const int num_mol, 
                       const int max_depth, const int *type_agl, const int *stat_all)
/* filename         - name of output file
 * step             - number of steps
 * num_mol          - number of molecules
 * max_depth        - max depth for check cycles in graph analyze
 * type_agl         - massive of numbers of aglomerate types
 * stat_all         - massive of summary statistics
 */
{
  float conc, p, pn, type[2], x, y;
  int i, index;
  FILE *f_out;
/* conc             - concentrate of aglomerates
 * p                - probability of aglomerates
 * pn               - weight probability of aglomerates
 * f_out            - output file
 */
  
  index = 0;
  for (i=0; i<num_mol; i++)
    if (stat_all[i] != 0)
      index = i;
  
//   head
  f_out = fopen (filename, "a");
  fprintf (f_out, "SUMMARY STATISTIC\n");
  fprintf (f_out, "|   n   |   N   |    C    |    p    |    pn    |\n------------------------------------------------\n");
  
  for (i=0; i<index+1; i++)
  {
//     calculating concentrates
    x = stat_all[i];
    y = step;
    conc = x / y;
    
//     calculating probabilityes
    x = (i + 1) * stat_all[i];
    y = step * num_mol;
    p = x / y;
    pn = (i + 1) * p;
    
    fprintf (f_out, " %7i %7i %9.2f %9.5f %10.5f\n", i+1, stat_all[i], conc, p, pn);
  }
  
  if (max_depth > 0)
  {
//   types of aglomerates
    fprintf (f_out, "------------------------------------------------\n");
//   linear and cycle
    x = type_agl[0] + type_agl[1];
    type[0] = type_agl[0];
    type[1] = type_agl[1];
    fprintf (f_out, "LINEAR=%7.5f\nCYCLE=%7.5f\n--------------------\n", type[0]/x, type[1]/x);
//     branched
    type[0] = type_agl[2];
    type[1] = type_agl[3];
    fprintf (f_out, "NOT BRANCHED=%7.5f\nBRANCHED=%7.5f\n--------------------\n", type[0]/x, type[1]/x);
//     n_cycle
    x = 0;
    for (i=4; i<max_depth+2; i++)
      x += type_agl[i];
    for (i=4; i<max_depth+2; i++)
    {
      type[0] = type_agl[i];
      fprintf (f_out, "CYCLE_'%2i'=%7.5f\n", i-1, type[0]/x);
    }
  }
  
  fclose (f_out);
  
  return 0;
}