/* Library for check isomorphic graph
 * 
 * Usage:
 *                                           iso_check (number_of_vertex, graph)
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"


int equat (const int num_mol_agl, float *c, const int rang, float *sol)
{
  int i, j, k, imax;
  float max, res;
  
  for (i=0; i<num_mol_agl; i++)
    if (i == rang)
      c[i*num_mol_agl+num_mol_agl] = 1;
    else
      c[i*num_mol_agl+num_mol_agl] = 0;
  
  for (i=0; i<num_mol_agl; i++)
  {
    imax = 0;
    max = c[imax*num_mol_agl+i];
    for (j=i; j<num_mol_agl; j++)
      if (fabs (c[j*num_mol_agl+i]) > max)
      {
        max = fabs (c[j*num_mol_agl+i]);
        imax = j;
      }
    for (j=0; j<=num_mol_agl; j++)
    {
      res = c[i*num_mol_agl+j];
      c[i*num_mol_agl+j] = c[imax*num_mol_agl+j];
      c[imax*num_mol_agl+j] = res;
    }
    
    for (j=0; j<num_mol_agl; j++)
      if (j != i)
      {
        res = c[j*num_mol_agl+i] / c[i*num_mol_agl+i];
        for(k=i; k<=num_mol_agl; k++)
          c[j*num_mol_agl+k] = c[j*num_mol_agl+k] - (res * c[i*num_mol_agl+k]);
      }
  }
  
  for (i=0; i<num_mol_agl; i++)
    sol[i] = c[i*num_mol_agl+num_mol_agl] / c[i*num_mol_agl+i];
  
  return 0;
}


int three_vertex (const int *matrix)
{
  int i, j;
  int test_mtx[2][9] = {{0, 1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 0}};
  
  for (i=0; i<2; i++)
    
  
  return 0;
}


int iso (const int N, const int *mtx, const int *ref_mtx)
{
  int i, j, k, *indx;
  float *a, *b, *d, dmax, det, eps, **nr_mtx, *x;
  
//   initialization of variables
  a = (float *) malloc (N * N * sizeof (float));
  d = (float *) malloc (N * sizeof (float));
  nr_mtx = matrix (1, N, 1, N);
  indx = ivector (1, N);
  x = vector (1, N);
//   copy matrix
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      a[i*N+j] = mtx[i*N+j];
//   create d-matrix
  for (i=0; i<N; i++)
  {
    d[i] = 0;
    for (j=0; j<N; j++)
      if (j != i)
        d[i] += a[i*N+j];
  }
  dmax = d[0];
  for (i=0; i<N; i++)
    if (d[i] > dmax)
      dmax = d[i];
  
  for (i=0; i<N; i++)
  {
//     to nr object
    for (j=1; j<=N; j++)
      for (k=1; k<=N; k++)
        nr_mtx[j][k] = a[(j-1)*N+(k-1)];
    ludcmp (nr_mtx, N, indx, &det);
    for(j=1; j<=N; j++) det *= nr_mtx[j][j];
    
//     define SLE
    eps = sqrt (pow ((d + d[i]), 2) + 2 / n * (det + 2 + 2 / n)) - (d + d[i]);
    for (j=0; j<N; j++)
      for (k=0; k<N; k++)
        if ((j == k) && (j == i))
          a[j*N+k] = a[j*N+k] + eps;
        else
          a[j*N+k] = a[j*N+k];
//     solution of SLE
    for (j=1; j<=N; j++)
    {
      if (j == i)
        x[j] = 1;
      else
        x[j] = 0;
      for (k=1; k<=N; k++)
        nr_mtx[j][k] = a[(j-1)*N+(k-1)];
      ludcmp (nr_mtx, N, indx, &det);
      lubksb (nr_mtx, N, indx, x);
    }
  }
  
  free_vector (i);
  free_ivector (indx);
  free_matrix (nr_mtx);
  
  return 0;
}


int iso_check (const int num_mol_agl, const int *matrix)
{
  int i, j, type;
  
  type = 0;
  
  switch (num_mol_agl)
  {
    case 2:
      type = 1;
      break;
    case 3:
      type = three_vertex (matrix);
  }
  
  return type;
}