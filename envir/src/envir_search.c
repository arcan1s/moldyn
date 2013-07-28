/**
 * @file
 */

/* Library for search environment
 * 
 * Usage:
 *      search_envir (number_of_molecule, num_mol, centr_coords, rad, needed_mol, 
 *                                                              &num_needed_mol)
 */

#include <math.h>


/**
 * @fn search_envir
 */
int search_envir (const int num_of_mol, const int num_mol, const float *centr_coords, 
                  const double rad, int *needed_mol, int *num_needed_mol)
/**
 * @brief function that searchs environment
 * @code
 * search_envir (number_of_molecule, num_mol, centr_coords, rad, needed_mol, 
 *               &num_needed_mol);
 * @endcode
 * 
 * @param num_of_mol      number of molecule
 * @param num_mol         number of molecules
 * @param centr_coords    massive of centered coordinates
 * @param rad             radius of environment sphere
 * @param needed_mol      massive of number of needed molecules
 * @param num_needed_mol  number of needed molecules
 * 
 * @return 0              - exit without errors
 */
{
  float r;
  int i;
  
/* r                      radius
 */
  
  *num_needed_mol = 0;
  
  for (i=0; i<8*num_mol; i++)
  {
    r = sqrt (pow ((centr_coords[3*i+0]-centr_coords[3*8*(num_of_mol-1)+0]), 2) + 
        pow ((centr_coords[3*i+1]-centr_coords[3*8*(num_of_mol-1)+1]), 2) + 
        pow ((centr_coords[3*i+2]-centr_coords[3*8*(num_of_mol-1)+2]), 2));
    if (r < rad)
    {
      needed_mol[*num_needed_mol] = i;
      *num_needed_mol = *num_needed_mol + 1;
    }
  }
  
  return 0;
}