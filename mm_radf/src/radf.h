/**
 * @file
 */

#ifndef RADF_H
#define RADF_H

/**
 * @fn search_rdf
 */
/**
 * @fn search_rdf_centr
 */
/**
 * @fn search_radf
 */

int search_rdf (const int, const int *, const int *, const float *, const double, 
                const double, const double, int *);
int search_rdf_centr (const int, const int *, const int *, const float *, const double, 
                      const double, const double, int *);
int search_radf (const int, const int *, const int *, const float *, const double, 
                 const double, const double, const double, const double, const double, 
                 int *);

#endif /* RADF_H */