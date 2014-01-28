/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file select_mol.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <math.h>

#include <mathmech/select_mol.h>


/**
 * @fn select_molecule
 */
int select_molecule (const float *centr_coords, const int num_needed_mol, int *needed_mol)
{
  float r, ref[3], rmin;
  int i, j, jmin;
  
/* r                      radius
 * ref                    coordinated of center mass
 * rmin                   minimal radius
 * jmin                   index of the nearest molecule
 */
  
// set first molecule
  needed_mol[0] = 0;
  for (i=0; i<3; i++)
    ref[i] = centr_coords[3*8*0+0+i];
  
// work block
  for (i=1; i<num_needed_mol; i++)
  {
    rmin = sqrt (pow ((centr_coords[3*8*i+0+0] - ref[0]), 2) + \
                 pow ((centr_coords[3*8*i+0+1] - ref[1]), 2) + \
                 pow ((centr_coords[3*8*i+0+2] - ref[2]), 2));
    jmin = 0;
    for (j=1; j<8; j++)
    {
      r = sqrt (pow ((centr_coords[3*8*i+j+0] - ref[0]), 2) + \
                pow ((centr_coords[3*8*i+j+1] - ref[1]), 2) + \
                pow ((centr_coords[3*8*i+j+2] - ref[2]), 2));
      if (r < rmin)
      {
        rmin = r;
        jmin = j;
      }
    }
    
// add molecule
    needed_mol[i] = 8 * i + jmin;
// update ref
    for (j=0; j<3; j++)
    {
      ref[j] += centr_coords[3*8*i+jmin+j];
      ref[j] = ref[j] / 2;
    }
  }
  
  return 0;
}
