/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file set_center.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef SET_CENTER_H
#define SET_CENTER_H

#include <mathmech/var_types.h>


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
int set_center (const system_info _system_info, const atom_info *_atom_info, 
                float *centr_coords);


#endif /* SET_CENTER_H */
