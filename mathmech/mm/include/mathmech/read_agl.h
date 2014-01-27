/**
 * @file
 */

#ifndef READ_AGL_H
#define READ_AGL_H


/**
 * @fn reading_agl
 */
int reading_agl (const char *aglinp, int *num_needed_mol, char *agl_class, int *needed_mol);
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


#endif /* READ_AGL_H */
