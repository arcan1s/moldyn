/**
 * @file
 */

#ifndef COORDS_H
#define COORDS_H

#include <mathmech/var_types.h>


/**
 * @fn reading_coords
 */
int reading_coords (const int mode, const char *filename, const int type_inter, 
                    const int *label_atom, system_info *_system_info, 
                    int *true_label_mol, atom_info *_atom_info);
/**
 * @brief function that reads coordinates from special file format
 * @code
 * reading_coords (0, filename, type_inter, label_atom, &_system_info, 
 *                 true_label_mol, _atom_info);
 * @endcode
 * 
 * @param mode            mode of reading; '1' is statgen, '2' is envir or 
 *                        frad, '3' is agl
 * @param filename        input file name
 * @param type_inter      number of needed atoms
 *                        (number of needed molecules)
 * @param label_atom      massive of needed atom types
 *                        (massive of needed molecules)
 * @param _system_info    system information structure
 * @param true_label_mol  massive of true numbers of molecule for atoms
 * @param _atom_info      atom information structure
 * 
 * @return 1              - file $filename does not exist
 * @return 2              - unknown mode
 * @return 3              - memory error
 * @return 0              - exit without errors
 */


#endif /* COORDS_H */
