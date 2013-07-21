/* Library for graph structure analyze
 * Usage:
 *                                         graph_analyze (N, connect, max_depth)
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int check_cycle (const int N, const int *matrix)
// function to return number of cycles
{
  int cycle, i, j;
/* cycle            - number of cycle
 */
  
  cycle = 0;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      cycle += matrix[i*N+j];
  
//   for linear (0.5*cycle == N-1)
  cycle = 0.5 * cycle - (N - 1);
  
  return cycle;
}


int check_cycle_size (const int N, const int *matrix, const int size)
// function to return number of cycles of certain size
{
  int cur_N, cycle, i, j, k, n, num, *submatrix, *vertex;
/* cur_N            - current number of elements in submatrix
 * cycle            - if ((0.5 * cycle) == size) that cycle exist
 * n                - number of samples
 * num              - number of cycles of certain size
 * submatrix        - connectivity matrix for subgraph
 * vertex           - vertexes of subgraph
 */
  
  num = 0;
  submatrix = (int *) malloc (size * size * sizeof (int));
  vertex = (int *) malloc (N * sizeof (int));
  
//   matrix generation from
//   http://wincode.org/acm-icpc/subsets-generation
  n = pow (2, N);
  for (i=0; i<n; i++)
  {
    cur_N = 0;
    for (j=0; j<N; j++)
      if ( i & (1 << j))
      {
        vertex[cur_N] = j;
        cur_N++;
      }
    
    if (cur_N == size)
    {
//       copy connectivity matrix
      for (j=0; j<cur_N; j++)
        for (k=0; k<cur_N; k++)
          submatrix[j*cur_N+k] = matrix[vertex[j]*N+vertex[k]];
      
      cycle = 0;
//       analyze subgraph
      for (j=0; j<cur_N; j++)
        for (k=0; k<cur_N; k++)
          cycle += submatrix[j*cur_N+j];
      
      if ((0.5 * cycle) == size)
        num++;
    }
  }
  
  free (vertex);
  free (submatrix);
  
  return num;
}


int check_tail (const int N, const int *matrix)
// function to return number of tails
{
  int i, j, pn, tail;
/* pn               - weight one vertex
 * tail             - number of tails
 */
  
  tail = 0;
  for (i=0; i<N; i++)
  {
    pn = 0;
    for (j=0; j<N; j++)
      pn += matrix[i*N+j];
    if (pn == 1)
      tail++;
  }
  
  return tail;
}


int graph_analyze (const int N, const int *matrix, const int max_depth, char *iso)
/* N                - number of vertex in graph
 * matrix           - connectivity matrix
 * max_depth        - maximum depth for check_cycle_size
 * iso              - isomorphism class
 */
{
  int cycle, depth, i, *n_cycle, tail;
/* cycle            - number of cycles
 * depth            - depth for check_cycle_size
 * n_cycle          - number of cycles of certain size
 * tail             - number of tails
 */
  
  if (max_depth > N)
    depth = N;
  else
    depth = max_depth;
  n_cycle = (int *) malloc ((max_depth-2) * sizeof (int));
  
  tail = check_tail (N, matrix);
  cycle = check_cycle (N, matrix);
  if (cycle > 0)
    for (i=0; i<depth-2; i++)
      n_cycle[i] = check_cycle_size (N, matrix, i+3);
  else
    for (i=0; i<depth-2; i++)
      n_cycle[i] = 0;
  for (i=depth-2; i<max_depth-2; i++)
    n_cycle[i] = 0;
  
  sprintf (iso, "%i.%i.%i", N, tail, cycle);
  for (i=0; i<max_depth-2; i++)
    sprintf (iso, "%s.%i", iso, n_cycle[i]);
  
  free (n_cycle);
  
  return 1;
}