/**
 * @file
 */

#include <math.h>
#include <stdio.h>

#include <mathmech/radf_proc.h>
#include <mathmech/var_types.h>

// pi
#if !defined __USE_BSD && !defined __USE_XOPEN
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */
#endif /* __USE_BSD && __USE_XOPEN */


/**
 * @fn print_result
 */
int print_result (const char *output, const int matrix, const int mode, 
                  const system_info _system_info, const radf_info _radf_info,
                  const int *radf)
{
  float ang, dv, norm, r, ro;
  int i, j, k, n;
  FILE *f_out;
  
/* ang                    angle
 * dv                     volume
 * norm                   normed RDF
 * r                      radius
 * ro                     density
 * f_out                  output file
 */
  
  f_out = fopen (output, "a");
  fprintf (f_out, "SUMMARY STATISTIC\n");
  
  switch (mode)
  {
    case 0:
      if (matrix == 0)
        fprintf (f_out, "|    r    |    dV    |   RDF   | RDFnorm |\n------------------------------------------\n");
      k = (_radf_info.r_max - _radf_info.r_min) / _radf_info.r_step;
      for (i=0; i<k; i++)
      {
        r = _radf_info.r_min + (0.5 + i) * _radf_info.r_step;
        dv = 4 * M_PI * pow (r, 2) * _radf_info.r_step;
        ro = _system_info.num_atoms  / (2 * _system_info.cell[0] * _system_info.cell[1] * _system_info.cell[2]);
        norm = radf[i] / (dv * ro * _system_info.num_atoms * (_system_info.to - _system_info.from + 1));
        if (matrix == 0)
          fprintf (f_out, " %9.4f %10.4e %9i %9.6f \n", r, dv, radf[i] / 2, norm);
        else
          fprintf (f_out, " %9.4f %9.6f\n", r, norm);
      }
      fprintf (f_out, "------------------------------------------\n");
      break;
    case 1:
      if (matrix == 0)
        fprintf (f_out, "|    r    |    dV    |   RDF   | RDFnorm |\n------------------------------------------\n");
      k = (_radf_info.r_max - _radf_info.r_min) / _radf_info.r_step;
      for (i=0; i<k; i++)
      {
        r = _radf_info.r_min + (0.5 + i) * _radf_info.r_step;
        dv = 4 * M_PI * pow (r, 2) * _radf_info.r_step;
        ro = _system_info.num_atoms  / (3 * 2 * _system_info.cell[0] * _system_info.cell[1] * _system_info.cell[2]);
        norm = radf[i] / (dv * ro * _system_info.num_atoms / 3 * (_system_info.to - _system_info.from + 1));
        if (matrix == 0)
          fprintf (f_out, " %9.4f %10.4e %9i %9.6f \n", r, dv, radf[i] / 2, norm);
        else
          fprintf (f_out, " %9.4f %9.6f\n", r, norm);
      }
      fprintf (f_out, "------------------------------------------\n");
      break;
    case 2:
      if (matrix == 0)
        fprintf (f_out, "|    r    |   ang   |    dV    |   RDF   | RDFnorm |\n----------------------------------------------------\n");
      k = (_radf_info.r_max - _radf_info.r_min) / _radf_info.r_step;
      n = (_radf_info.ang_max - _radf_info.ang_min) / _radf_info.ang_step;
      if (matrix == 1)
      {
        fprintf (f_out, "  r\\ang   ");
        for (j=0; j<n; j++)
          fprintf (f_out, " %9.2f", _radf_info.ang_min+(0.5+j)*_radf_info.ang_step);
        fprintf (f_out, "\n");
      }
      for (i=0; i<k; i++)
      {
        if (matrix == 1)
          fprintf (f_out, " %9.4f", r);
        for (j=0; j<n; j++)
        {
          r = _radf_info.r_min + (0.5 + i) * _radf_info.r_step;
          ang = _radf_info.ang_min + (0.5 + j) * _radf_info.ang_step;
          dv = 4 * M_PI * pow (r, 2) * sin (M_PI * ang / 180) * _radf_info.r_step * (M_PI * _radf_info.ang_step / 180);
          ro = _system_info.num_atoms  / (3 * 2 * _system_info.cell[0] * _system_info.cell[1] * _system_info.cell[2]);
          norm = radf[n*i+j] / (dv * ro * _system_info.num_atoms / 3 * (_system_info.to - _system_info.from + 1));
          if (matrix == 0)
            fprintf (f_out, " %9.4f %9.2f %10.4e %9i %9.6f \n", r, ang, dv, radf[n*i+j] / 2, norm);
          else
            fprintf (f_out, " %9.6f", norm);
        }
        if (matrix == 1)
          fprintf (f_out, "\n");
      }
      fprintf (f_out, "----------------------------------------------------\n");
      break;
  }
  
  fclose (f_out);
  
  return 0;
}
