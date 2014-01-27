/**
 * @file
 */

#ifndef RADF_H
#define RADF_H

#include <mathmech/var_types.h>


/**
 * @fn search_rdf
 */
int search_rdf (const system_info _system_info, const atom_info *_atom_info, 
                const radf_info _radf_info, int *radf);
/**
 * @brief function that searchs molecule for rdf massive
 * @code
 * search_rdf (_system_info, _atom_info, _radf_info, radf);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param _atom_info      atom information structure
 * @param _radf_info      radf information structure
 * @param radf            not normed RDF
 * 
 * @return 0              - exit without errors
 */


/**
 * @fn search_rdf_centr
 */
int search_rdf_centr (const system_info _system_info, const atom_info *_atom_info, 
                      const radf_info _radf_info, int *radf);
/**
 * @brief function that searchs molecule for rdf massive by centered coordinates
 * @code
 * search_rdf_centr (_system_info, _atom_info, _radf_info, radf);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param _atom_info      atom information structure
 * @param _radf_info      radf information structure
 * @param radf            not normed RDF
 * 
 * @return 0              - exit without errors
 * @return 1              - error in set center (missing atoms)
 */


/**
 * @fn search_radf
 */
int search_radf (const system_info _system_info, const atom_info *_atom_info, 
                 const radf_info _radf_info, int *radf);
/**
 * @brief function that searchs molecule for radf massive
 * @code
 * search_radf (_system_info, _atom_info, _radf_info, radf);
 * @endcode
 * 
 * @param _system_info    system information structure
 * @param _atom_info      atom information structure
 * @param _radf_info      radf information structure
 * @param radf            not normed RDF
 * 
 * @return 0              - exit without errors
 * @return 1              - error in set center (missing atoms)
 */


#endif /* RADF_H */
