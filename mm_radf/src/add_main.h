/**
 * @file
 */

#ifndef ADD_MAIN_H
#define ADD_MAIN_H

/**
 * @fn error_checking
 */
/**
 * @fn print_message
 */
/**
 * @fn printing_head
 */
/**
 * @fn set_defaults
 */

int error_checking (const float *, const int, const char *, const int, const int *, 
                    const char *, const int);
int print_message (const int, FILE *, const int, FILE *, const int, const char *);
int printing_head (const char *, const int, const int, const int, const char *, 
                   const int, const int, const float *, const int, const double, 
                   const double, const double, const double, const double, const double, 
                   const int *);
int set_defaults (float *, float *, float *, float *, int *, char *, int *, int *,
                  float *, float *, float *, char *, int *, int *);

#endif /* ADD_MAIN_H */