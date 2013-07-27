/**
 * @file
 */


/**
 * @fn conv
 */
char conv (const int fnumb, const int dig_pos)
/**
 * @brief function that converts from integer to char
 * @code
 * char = conv (N, 0);
 * @endcode
 * 
 * @param fnumb           integer
 * @param dig_pos         position: ones=1, decimals=2, hundreds=3
 * 
 * @return char
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