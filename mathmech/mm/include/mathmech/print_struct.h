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

#ifndef PRINT_STRUCT_H
#define PRINT_STRUCT_H

#include <mathmech/var_types.h>


/**
 * @fn print_structure
 */
int print_structure (const char *output, const int num_needed_mol, const int *needed_mol, 
                     const system_info _system_info, const atom_info *_atom_info);
/**
 * @brief function that prints structure to pdb file
 * @code
 * print_structure (output, num_needed_mol, needed_mol, _system_info, _atom_info);
 * @endcode
 * 
 * @param output          output file name
 * @param num_needed_mol  number of needed molecules
 * @param needed_mol      massive of number of needed molecules
 * @param _system_info    system information structure
 * @param _atom_info      atom information structure
 * 
 * @return 0              - exit without errors
 */


#endif /* PRINT_STRUCT_H */
