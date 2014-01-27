/**
 * @file
 */

#ifndef SET_CENTER_H
#define SET_CENTER_H

#include <mathmech/var_types.h>


/**
 * @fn set_center
 */
int set_center (const system_info _system_info, const atom_info *_atom_info, 
                float *centr_coords);
/**
 * @brief function that searchs center mass of molecules
 * @code
 * set_center (_system_info, _atom_info, centr_coords);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param _atom_info      atom information structure
 * @param centr_coords    massive of centered coordinates
 * 
 * @return 0              - exit without errors
 */


#endif /* SET_CENTER_H */
