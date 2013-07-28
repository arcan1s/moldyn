/**
 * @file
 */


/**
 * @fn set_center
 */
int set_center (const int num_atoms, const int num_mol, const int *label_mol, 
                const float *coords, float *centr_coords)
/**
 * @brief function that searchs center mass of molecules
 * @code
 * set_center (num_of_atoms, num_of_molecules, label_molecules, coords, centr_coords);
 * @endcode
 * 
 * @param num_atoms       number of atoms
 * @param num_mol         number of molecules
 * @param label_mol       massive of numbers of molecule for atoms
 * @param coords          massive of coordinates
 * @param centr_coords    massive of centered coordinates
 * 
 * @return 0              - exit without errors
 */
{
  int at_in_mol, cur_mol, i, j, k;
  
/* at_int_mol             number of atoms in molecule
 * cur_mol                current molecule
 */
  
  for (i=0; i<8*num_mol; i++)
    for (j=0; j<3; j++)
      centr_coords[i*3+j] = 0.0;
  
  for (i=0; i<8*num_atoms; i++)
  {
    if (i < num_atoms)
      cur_mol = 0;
    else
      cur_mol = ((i - num_atoms) % 7) + 1;
    for (j=0; j<3; j++)
      centr_coords[3*(8*label_mol[i]+cur_mol)+j] += coords[3*i+j];
  }
  
  at_in_mol = 0;
  cur_mol = 0;
  for (i=0; i<num_atoms; i++)
    if (cur_mol != label_mol[i])
    {
      for (j=0; j<8; j++)
        for (k=0; k<3; k++)
          centr_coords[3*(8*cur_mol+j)+k] = centr_coords[3*(8*cur_mol+j)+k] / at_in_mol;
      at_in_mol = 0;
      cur_mol = label_mol[i];
    }
    else
      at_in_mol++;
  
  return 0;
}