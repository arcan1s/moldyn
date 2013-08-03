/**
 * @file
 */

#include <math.h>
#include <stdio.h>

// pi
#if !defined __USE_BSD && !defined __USE_XOPEN
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* __USE_BSD && __USE_XOPEN */
#endif /* M_PI */


/**
 * @fn print_result
 */
int print_result (const char *output, const int matrix, const int mode, 
                  const int step, const int num_atoms, const double r_min, 
                  const double r_max, const double r_step, const double ang_min, 
                  const double ang_max, const double ang_step, const float *cell, 
                  const int *radf)
/**
 * @brief function that print result to output file
 * @code
 * print_result (output, matrix, mode, step, num_atoms, r_min, r_max, r_step, ang_min, 
 *               ang_max, ang_step, cell, radf);
 * @endcode
 * 
 * @param output          output file name
 * @param matrix          status of matrix-mode
 * @param mode            1 - if RDF, 2 - if RDF for center mass, 3 - if RADF
 * @param step            $(to - from + 1)
 * @param num_atoms       number of atoms
 * @param r_min           minimal radius
 * @param r_max           maximal radius
 * @param r_step          radius step
 * @param ang_min         minimal angle
 * @param ang_max         maximal angle
 * @param ang_step        angle step
 * @param cell            cell size
 * @param radf            not normed RADF
 * 
 * @return 0              - exit without errors
 */
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
      k = (r_max - r_min) / r_step;
      for (i=0; i<k; i++)
      {
        r = r_min + (0.5 + i) * r_step;
        dv = 4 * M_PI * pow (r, 2) * r_step;
        ro = num_atoms  / (2 * cell[0] * cell[1] * cell[2]);
        norm = radf[i] / (dv * ro * num_atoms * step);
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
      k = (r_max - r_min) / r_step;
      for (i=0; i<k; i++)
      {
        r = r_min + (0.5 + i) * r_step;
        dv = 4 * M_PI * pow (r, 2) * r_step;
        ro = num_atoms  / (3 * 2 * cell[0] * cell[1] * cell[2]);
        norm = radf[i] / (dv * ro * num_atoms / 3 * step);
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
      k = (r_max - r_min) / r_step;
      n = (ang_max - ang_min) / ang_step;
      if (matrix == 1)
      {
        fprintf (f_out, "  r\\ang   ");
        for (j=0; j<n; j++)
          fprintf (f_out, " %9.2f", ang_min+(0.5+j)*ang_step);
        fprintf (f_out, "\n");
      }
      for (i=0; i<k; i++)
      {
        if (matrix == 1)
          fprintf (f_out, " %9.4f", r);
        for (j=0; j<n; j++)
        {
          r = r_min + (0.5 + i) * r_step;
          ang = ang_min + (0.5 + j) * ang_step;
          dv = 4 * M_PI * pow (r, 2) * sin (M_PI * ang / 180) * r_step * (M_PI * ang_step / 180);
          ro = num_atoms  / (3 * 2 * cell[0] * cell[1] * cell[2]);
          norm = radf[n*i+j] / (dv * ro * num_atoms / 3 * step);
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