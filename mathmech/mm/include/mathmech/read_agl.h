/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file read_agl.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef READ_AGL_H
#define READ_AGL_H


/**
 * @brief function that reads agglomerate from statgen-formated file
 * @code
 * reading_agl (aglinput, &num_needed_mol, agl_class, needed_mol);
 * @endcode
 * 
 * @param aglinp          agglomerate file name
 * @param num_needed_mol  number of needed molecules
 * @param agl_class       agglomerate class
 * @param needed_mol      massive of numbed of needed molecules
 * 
 * @return 0              - exit without errors
 */
int reading_agl (const char *aglinp, int *num_needed_mol, char *agl_class, int *needed_mol);


#endif /* READ_AGL_H */
