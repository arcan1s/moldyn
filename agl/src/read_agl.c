/* Library for reading aglomerate from statgen-file
 *
 * Usage:
 *                reading_agl (aglinput, &num_needed_mol, agl_class, needed_mol)
 */

#include <stdio.h>


int reading_agl (const char *aglinp, int *num_needed_mol, char *agl_class, int *needed_mol)
/* aglinp           - input file with aglomerate
 * num_needed_mol   - number of needed molecules
 * agl_class        - aglomerate class
 * needed_mol       - massive of needed molecules
 */
{
  char connect[256], tmp_str[256];
  int i;
  FILE *f_agl;
  
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
