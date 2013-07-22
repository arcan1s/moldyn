/* Library for graph structure analyze
 * Usage:
 *                      graph_analyze (N, connect, max_depth, isomorphism_class)
 */

#include <math.h>
#include <stdlib.h>


int check_cycle (const int N, const int *pn)
// function to return number of cycles
{
  int cycle, i;
/* cycle            - number of cycle
 */
  
  cycle = 0;
  for (i=1; i<N; i++)
    cycle += i*pn[i];
  
//   for linear (0.5*cycle == N-1)
  cycle = 0.5 * cycle - (N - 1);
  
  return cycle;
}


int check_cycle_size (const int N, const int *matrix, const int depth, int *n_cycle)
// function to return number of cycles of certain size
{
  int cur_N, cycle, i, j, k, n, p, *vertex;
/* cur_N            - current number of elements in submatrix
 * cycle            - if (cycle == 1) that cycle exist
 * n                - number of samples
 * vertex           - vertexes of subgraph
 */
  
  vertex = (int *) malloc (N * sizeof (int));
  for (i=0; i<depth-2; i++)
    n_cycle[i] = 0;
  
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
    
    if ((cur_N > 2) && (cur_N <= depth))
    {
//       copy connectivity matrix
      cycle = 1;
      for (j=0; j<cur_N; j++)
      {
        p = 0;
        for (k=0; k<cur_N; k++)
          p += matrix[vertex[j]*N+vertex[k]];
        if (p != 2)
          cycle = 0;
      }
      
//       analyze subgraph
      if (cycle == 1)
        n_cycle[cur_N-3]++;
    }
  }
  
  free (vertex);
  
  return 0;
}


int check_tail (const int *pn)
// function to return number of tails
{
  return pn[1];
}


int graph_analyze (const int N, const int *matrix, const int max_depth, int *iso)
/* N                - number of vertex in graph
 * matrix           - connectivity matrix
 * max_depth        - maximum depth for check_cycle_size
 * iso              - isomorphism class
 */
{
  int depth, i, j, *n_cycle, p, *pn;
/* depth            - depth for check_cycle_size
 * n_cycle          - number of cycle
 * p                - current weight
 * pn               - total weight
 */
  
  if (max_depth > N)
    depth = N;
  else
    depth = max_depth;
//   convert to matrix of weight
  pn = (int *) malloc (N * sizeof (int));
  n_cycle = (int *) malloc ((depth - 2) * sizeof (int));
  for (i=0; i<N; i++)
    pn[i] = 0;
  for (i=0; i<N; i++)
  {
    p = 0;
    for (j=0; j<N; j++)
      p += matrix[i*N+j];
    pn[p]++;
  }
  
  iso[0] = check_tail (pn);
  iso[1] = check_cycle (N, pn);
  for (i=2; i<max_depth; i++)
    iso[i] = 0;
  if (iso[1] > 0)
  {
    check_cycle_size (N, matrix, depth, n_cycle);
    for (i=0; i<depth-2; i++)
      iso[i+2] = n_cycle[i];
  }
  
  free (n_cycle);
  free (pn);
  
  return 1;
}