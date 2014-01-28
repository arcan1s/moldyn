/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file var_types.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef VAR_TYPES_H
#define VAR_TYPES_H


/**
 * @struct atom_info
 * @brief atom information structure
 * @var atom_info::label_mol
 * massive of numbers of molecule for atoms
 * @var atom_info::type_atoms
 * massive of atom types
 * @var atom_info::coords
 * massive of coordinates
 * @var atom_info::ch_type_atoms
 * massive of char atom types
 */
typedef struct
{
  int label_mol;
  int type_atoms;
  char ch_type_atoms[2];
  float coords[3];
} atom_info;


/**
 * @struct radf_info
 * @brief radf information structure
 * @var radf_info::r_min
 * minimal radius
 * @var radf_info::r_max
 * maximal radius
 * @var radf_info::r_step
 * radius step
 * @var radf_info::ang_min
 * minimal angle
 * @var radf_info::ang_max
 * minimal angle
 * @var radf_info::ang_step
 * angle step
 */
typedef struct
{
  float r_min;
  float r_max;
  float r_step;
  float ang_min;
  float ang_max;
  float ang_step;
} radf_info;


/**
 * @struct system_info
 * @brief system information structure
 * @var system_info::from
 * last trajectory step
 * @var system_info::to
 * first trajectory step
 * @var system_info::cell
 * cell size
 * @var system_info::num_atoms
 * number of atoms
 * @var system_info::num_mol
 * number of molecules
 */
typedef struct
{
  int from;
  int to;
  float cell[3];
  int num_atoms;
  int num_mol;
} system_info;


#endif /* VAR_TYPES_H */
