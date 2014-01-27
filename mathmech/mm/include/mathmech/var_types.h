/**
 * @file
 */

#ifndef VAR_TYPES_H
#define VAR_TYPES_H


/**
 * @struct atom_info
 */
typedef struct
{
  int label_mol;
  int type_atoms;
  char ch_type_atoms[2];
  float coords[3];
} atom_info;
/**
 * @brief atom information structure
 * @var label_mol         massive of numbers of molecule for atoms
 * @var type_atoms        massive of atom types
 * @var coords            massive of coordinates
 * @var ch_type_atoms     massive of char atom types
 */


/**
 * @struct radf_info
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
 * @brief radf information structure
 * @var r_min             minimal radius
 * @var r_max             maximal radius
 * @var r_step            radius step
 * @var ang_min           minimal angle
 * @var ang_max           minimal angle
 * @var ang_step          angle step
 */


/**
 * @struct system_info
 */
typedef struct
{
  int first;
  int last;
  float cell[3];
  int num_atoms;
  int num_mol;
} system_info;
/**
 * @brief system information structure
 * @var first             last trajectory step
 * @var last              first trajectory step
 * @var cell              cell size
 * @var num_atoms         number of atoms
 * @var num_mol           number of molecules
 */


#endif /* VAR_TYPES_H */
