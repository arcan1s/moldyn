/**
 * @file
 */

#include <mathmech/set_center.h>
#include <mathmech/var_types.h>


/**
 * @fn set_center
 */
int set_center (const system_info _system_info, const atom_info *_atom_info, 
                float *centr_coords)
{
  int at_in_mol, cur_mol, i, j, k;
  
/* at_int_mol             number of atoms in molecule
 * cur_mol                current molecule
 */
  
  for (i=0; i<8*_system_info.num_mol; i++)
    for (j=0; j<3; j++)
      centr_coords[i*3+j] = 0.0;
  
  for (i=0; i<8*_system_info.num_atoms; i++)
  {
    if (i < _system_info.num_atoms)
      cur_mol = 0;
    else
      cur_mol = ((i - _system_info.num_atoms) % 7) + 1;
    for (j=0; j<3; j++)
      centr_coords[3*(8*_atom_info[i].label_mol+cur_mol)+j] += _atom_info[i].coords[j];
  }
  
  at_in_mol = 0;
  cur_mol = 0;
  for (i=0; i<_system_info.num_atoms; i++)
    if (cur_mol != _atom_info[i].label_mol)
    {
      for (j=0; j<8; j++)
        for (k=0; k<3; k++)
          centr_coords[3*(8*cur_mol+j)+k] = centr_coords[3*(8*cur_mol+j)+k] / at_in_mol;
      at_in_mol = 0;
      cur_mol = _atom_info[i].label_mol;
    }
    else
      at_in_mol++;
  
  return 0;
}
