/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file radf.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef RADF_H
#define RADF_H

#include <mathmech/var_types.h>


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
int search_rdf (const system_info _system_info, const atom_info *_atom_info, 
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
int search_rdf_centr (const system_info _system_info, const atom_info *_atom_info, 
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
int search_radf (const system_info _system_info, const atom_info *_atom_info, 
                 const radf_info _radf_info, int *radf);


#endif /* RADF_H */
