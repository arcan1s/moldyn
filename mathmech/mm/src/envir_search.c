/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 */

#include <math.h>

#include <mathmech/envir_search.h>
#include <mathmech/var_types.h>


/**
 * @fn search_envir
 */
int search_envir (const int num_of_mol, const system_info _system_info, const float *centr_coords, 
                  const double rad, int *needed_mol, int *num_needed_mol)
{
  float r;
  int i;
  
/* r                      radius
 */
  
  *num_needed_mol = 0;
  
  for (i=0; i<8*_system_info.num_mol; i++)
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
