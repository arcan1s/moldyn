/**
 * @file
 */

#ifndef READ_GMX_H
#define READ_GMX_H

/**
 * @fn translate_coords
 */
/**
 * @fn rw_gmx
 */

int translate_coords (const float, const float, float *);
int rw_gmx (const char *, const int, const char *, const int, const int *, 
            const int *, const char *, const int *, float *);

#endif /* READ_GMX_H */