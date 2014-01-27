/**
 * @file
 */

#include <math.h>
#include <stdlib.h>

#include <mathmech/stat_select.h>
#include <mathmech/var_types.h>


/**
 * @fn create_matrix
 */
int create_matrix (const system_info _system_info, const atom_info *_atom_info, 
                   const int num_of_inter, const float *crit, int *connect)
{
  float r;
  int cur_num_inter, i, j, k, l, num_inter, ***label_inter;
  
/* r                      radius
 * cur_num_inter          current number of true interactions
 * num_inter              needed number of true interactions
 * label_inter            temporary massive of true interactions
 */
  
/// <b>Work blocks</b>
  
  label_inter = (int ***) malloc (_system_info.num_mol * sizeof (int **));
  for (i=0; i<_system_info.num_mol; i++)
  {
    label_inter[i] = (int **) malloc (_system_info.num_mol * sizeof (int *));
    for (j=0; j<_system_info.num_mol; j++)
    {
      label_inter[i][j] = (int *) malloc (16 * sizeof (int));
      for (k=0; k<16; k++)
        label_inter[i][j][k] = 0;
    }
  }
  if (label_inter == NULL)
    return 1;
  
/// <pre>   creating initial connectivity matrix </pre>
  for (i=0; i<_system_info.num_atoms*8; i++)
    for (j=i+1; j<_system_info.num_atoms*8; j++)
// if atoms from different molecules
      if (_atom_info[i].label_mol != _atom_info[j].label_mol)
      {
        r = sqrt (pow ((_atom_info[i].coords[0]-_atom_info[j].coords[0]), 2) + 
          pow ((_atom_info[i].coords[1]-_atom_info[j].coords[1]), 2) + 
          pow ((_atom_info[i].coords[2]-_atom_info[j].coords[2]), 2));
        for (k=0; k<num_of_inter; k++)
          if (crit[16*k+4*_atom_info[i].type_atoms+_atom_info[j].type_atoms] != 0.0)
            if (r < crit[16*k+4*_atom_info[i].type_atoms+_atom_info[j].type_atoms])
            {
              label_inter[_atom_info[i].label_mol][_atom_info[j].label_mol][4*_atom_info[i].type_atoms+_atom_info[j].type_atoms] = 1;
              label_inter[_atom_info[i].label_mol][_atom_info[j].label_mol][4*_atom_info[j].type_atoms+_atom_info[i].type_atoms] = 1;
              label_inter[_atom_info[j].label_mol][_atom_info[i].label_mol][4*_atom_info[i].type_atoms+_atom_info[j].type_atoms] = 1;
              label_inter[_atom_info[j].label_mol][_atom_info[i].label_mol][4*_atom_info[j].type_atoms+_atom_info[i].type_atoms] = 1;
            }
      }
  
  for (i=0; i<_system_info.num_mol; i++)
    for (j=0; j<_system_info.num_mol; j++)
      connect[i*_system_info.num_mol+j] = 0;
  
/// <pre>   processing of initial connectivity matrix </pre>
  for (k=0; k<num_of_inter; k++)
  {
// determination of the number of interactions
    num_inter = 0;
    for (l=0; l<16; l++)
      if (crit[16*k+l] != 0.0)
        num_inter++;
    
    for (i=0; i<_system_info.num_mol; i++)
      for (j=i+1; j<_system_info.num_mol; j++)
      {
        cur_num_inter = 0;
        for (l=0; l<16; l++)
          cur_num_inter += label_inter[i][j][l];
        
        if (cur_num_inter == num_inter)
        {
          connect[i*_system_info.num_mol+j] = 1;
          connect[j*_system_info.num_mol+i] = 1;
        }
      }
  }
  
/// <pre>   free memory</pre>
  for (i=0; i<_system_info.num_mol; i++)
  {
    for (j=0; j<_system_info.num_mol; j++)
      free (label_inter[i][j]);
    free (label_inter[i]);
  }
  free (label_inter);
  
  return 0;
}
