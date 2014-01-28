/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file summary_stat.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <stdio.h>

#include <mathmech/summary_stat.h>
#include <mathmech/var_types.h>


/**
 * @fn summary_statistic
 */
int summary_statistic (const char *filename, const system_info _system_info, 
                       const int max_depth, const int *type_agl, const int *stat_all)
{
  float conc, p, pn, type[2], x, y;
  int i, index;
  FILE *f_out;
  
/* conc                   concentrate of agglomerates
 * p                      probability of agglomerates
 * pn                     weight probability of agglomerates
 * f_out                  output file
 */
  
  index = 0;
  for (i=0; i<_system_info.num_mol; i++)
    if (stat_all[i] != 0)
      index = i;
  
// head
  f_out = fopen (filename, "a");
  fprintf (f_out, "SUMMARY STATISTIC\n");
  fprintf (f_out, "|   n   |   N   |    C    |    p    |    pn    |\n------------------------------------------------\n");
  
  for (i=0; i<index+1; i++)
  {
// calculating concentrates
    x = stat_all[i];
    y = _system_info.to - _system_info.from + 1;
    conc = x / y;
    
// calculating probabilityes
    x = (i + 1) * stat_all[i];
    y = (_system_info.to - _system_info.from + 1) * _system_info.num_mol;
    p = x / y;
    pn = (i + 1) * p;
    
    fprintf (f_out, " %7i %7i %9.2f %9.5f %10.5f\n", i+1, stat_all[i], conc, p, pn);
  }
  fprintf (f_out, "------------------------------------------------\n");
  
  if (max_depth > 0)
  {
// types of agglomerates
// linear and cycle
    x = type_agl[0] + type_agl[1];
    type[0] = type_agl[0];
    type[1] = type_agl[1];
    fprintf (f_out, "LINEAR=%.5f\nCYCLE=%.5f\n--------------------\n", type[0]/x, type[1]/x);
// branched
    type[0] = type_agl[2];
    type[1] = type_agl[3];
    fprintf (f_out, "NOT BRANCHED=%.5f\nBRANCHED=%.5f\n--------------------\n", type[0]/x, type[1]/x);
// n_cycle
    x = 0;
    for (i=4; i<max_depth+2; i++)
      x += type_agl[i];
    for (i=4; i<max_depth+2; i++)
    {
      type[0] = type_agl[i];
      fprintf (f_out, "CYCLE_'%2i'=%.5f\n", i-1, type[0]/x);
    }
  }
  
  fclose (f_out);
  
  return 0;
}
