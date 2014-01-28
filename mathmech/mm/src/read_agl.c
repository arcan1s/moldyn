/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file read_agl.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <stdio.h>

#include <mathmech/read_agl.h>


/**
 * @fn reading_agl
 */
int reading_agl (const char *aglinp, int *num_needed_mol, char *agl_class, int *needed_mol)

{
  char connect[256], tmp_str[256];
  int i;
  FILE *f_agl;
  
/* connect                - connectivity matrix for molecule
 * f_agl                  - agglomerate file
 */
  
  f_agl = fopen (aglinp, "r");
  
  fgets (tmp_str, 256, f_agl);
  sscanf (tmp_str, "AGL=%i=%s", num_needed_mol, agl_class);
  for (i=0; i<*num_needed_mol; i++)
  {
    fgets (tmp_str, 256, f_agl);
    sscanf (tmp_str, "%i=%s", &needed_mol[i], connect);
  }
  fclose (f_agl);
  
  return 0;
}
