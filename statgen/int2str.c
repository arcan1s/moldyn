/* Library for converting integer to string
 * Usage
 *                                                char = conv (number, position)
 */

#include <stdio.h>
#include <stdlib.h>


char conv (int fnumb, int dig_pos)
/* fnumb            - integer
 * dig_pos          - position
 */
{
  int d, h, o;
  char const digit[] = "0123456789";
 
  h = fnumb / 100;
  d = (fnumb % 100) / 10;
  o = fnumb % 10;

  if (dig_pos == 1) return digit[o];
  if (dig_pos == 2) return digit[d];
  if (dig_pos == 3) return digit[h];
  else return digit[0];
}